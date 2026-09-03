const { Plugin, Notice, Modal, Setting, PluginSettingTab } = require("obsidian");

const DEFAULT_SETTINGS = {
  dailyFolder: "",
  dateFormat: "YYYY-MM-DD",
  templatePath: "",
  insertionHeading: "",
  statusFrom: "[[0-5]]",
  taskPrefix: "- [ ]",
  includeDueDate: true,
  replaceAll: false,
  defaultDays: 1,
  defaultStatus: "1",
  openTarget: true
};

function pad(n) { return String(n).padStart(2, "0"); }

function formatDate(date, format) {
  const values = {
    YYYY: String(date.getFullYear()),
    YY: String(date.getFullYear()).slice(-2),
    MM: pad(date.getMonth() + 1),
    M: String(date.getMonth() + 1),
    DD: pad(date.getDate()),
    D: String(date.getDate())
  };
  return format.replace(/YYYY|YY|MM|M|DD|D/g, token => values[token]);
}

function addDays(date, days) {
  const result = new Date(date);
  result.setHours(12, 0, 0, 0);
  result.setDate(result.getDate() + days);
  return result;
}

class ScheduleModal extends Modal {
  constructor(app, settings) {
    super(app);
    this.settings = settings;
    this.result = null;
    this.resolvePromise = null;
  }

  waitForResult() { return new Promise(resolve => { this.resolvePromise = resolve; this.open(); }); }

  onOpen() {
    const { contentEl } = this;
    contentEl.empty();
    contentEl.createEl("h2", { text: "安排到未来日历" });
    let daysInput;
    new Setting(contentEl).setName("x：几天后").setDesc("0 表示今天，建议使用正整数。").addText(t => {
      daysInput = t.inputEl;
      t.inputEl.type = "number";
      t.setValue(String(this.settings.defaultDays));
      t.inputEl.min = "0";
      t.inputEl.style.width = "100%";
    });
    let statusInput;
    new Setting(contentEl).setName("y：修改后的状态").setDesc(`把 ${this.settings.statusFrom} 改成 [[y]]`).addText(t => {
      statusInput = t.inputEl;
      t.setValue(this.settings.defaultStatus);
      t.inputEl.placeholder = "例如 2 或 review";
      t.inputEl.style.width = "100%";
    });
    const buttons = contentEl.createDiv({ cls: "modal-button-container" });
    const cancel = buttons.createEl("button", { text: "取消" });
    cancel.addEventListener("click", () => this.close());
    const submit = buttons.createEl("button", { text: "执行", cls: "mod-cta" });
    submit.addEventListener("click", () => {
      const x = Number(daysInput?.value);
      const y = String(statusInput?.value || "").trim();
      if (!Number.isInteger(x) || x < 0) { new Notice("x 必须是大于等于 0 的整数"); return; }
      if (!y || y.includes("[[") || y.includes("]]")) { new Notice("y 不能为空，且不能包含 [[ 或 ]] "); return; }
      this.result = { days: x, status: y };
      this.close();
    });
    statusInput?.addEventListener("keydown", e => { if (e.key === "Enter") submit.click(); });
  }

  onClose() {
    this.contentEl.empty();
    if (this.resolvePromise) this.resolvePromise(this.result);
  }
}

class SchedulerSettingTab extends PluginSettingTab {
  constructor(app, plugin) { super(app, plugin); this.plugin = plugin; }
  display() {
    const { containerEl } = this; containerEl.empty();
    containerEl.createEl("h2", { text: "日历状态排程器" });
    const s = this.plugin.settings;
    new Setting(containerEl).setName("日记文件夹").setDesc("相对于库根目录；留空则使用库根目录。示例：日记/每日").addText(t => t.setValue(s.dailyFolder).onChange(async v => { s.dailyFolder = v.trim().replace(/^\/+|\/+$/g, ""); await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("日期文件名格式").setDesc("支持 YYYY、MM、DD；必须与 Calendar/Periodic Notes 的日记格式一致。").addText(t => t.setValue(s.dateFormat).onChange(async v => { s.dateFormat = v || "YYYY-MM-DD"; await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("日记模板路径（可选）").setDesc("目标日记不存在时复制此模板，例如 Templates/Daily.md；留空则创建空文件。").addText(t => t.setValue(s.templatePath).onChange(async v => { s.templatePath = v.trim(); await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("插入标题（可选）").setDesc("填写模板中的完整标题（如 ## 今日清单），任务会插入其下一行；找不到时追加到文件末尾。").addText(t => t.setValue(s.insertionHeading).onChange(async v => { s.insertionHeading = v; await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("待替换状态").setDesc("默认自动识别唯一的 [[0]] 到 [[5]]；如需固定状态，可填入完整文本，例如 [[todo]]。").addText(t => t.setValue(s.statusFrom).onChange(async v => { s.statusFrom = v || "[[0-5]]"; await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("任务前缀").setDesc("Tasks 插件通常使用 - [ ]；也可以改成普通列表前缀。").addText(t => t.setValue(s.taskPrefix).onChange(async v => { s.taskPrefix = v; await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("写入 Tasks 到期日期").addToggle(t => t.setValue(s.includeDueDate).onChange(async v => { s.includeDueDate = v; await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("替换所有状态").addToggle(t => t.setValue(s.replaceAll).onChange(async v => { s.replaceAll = v; await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("默认 x").addText(t => t.setValue(String(s.defaultDays)).onChange(async v => { const n = Number(v); if (Number.isInteger(n) && n >= 0) { s.defaultDays = n; await this.plugin.saveSettings(); } }));
    new Setting(containerEl).setName("默认 y").addText(t => t.setValue(s.defaultStatus).onChange(async v => { s.defaultStatus = v; await this.plugin.saveSettings(); }));
    new Setting(containerEl).setName("执行后打开目标日记").addToggle(t => t.setValue(s.openTarget).onChange(async v => { s.openTarget = v; await this.plugin.saveSettings(); }));
  }
}

module.exports = class CalendarStatusScheduler extends Plugin {
  async onload() {
    await this.loadSettings();
    this.addCommand({ id: "schedule-current-note", name: "安排当前笔记到未来日历并更新状态", callback: () => this.scheduleCurrentNote() });
    this.addRibbonIcon("calendar-plus", "安排当前笔记到未来日历", () => this.scheduleCurrentNote());
    this.addSettingTab(new SchedulerSettingTab(this.app, this));
  }

  async loadSettings() { this.settings = Object.assign({}, DEFAULT_SETTINGS, await this.loadData()); }
  async saveSettings() { await this.saveData(this.settings); }

  getDailyOptions() {
    const daily = this.app.internalPlugins?.getPluginById?.("daily-notes");
    const options = daily?.instance?.options || {};
    return {
      folder: this.settings.dailyFolder || options.folder || "",
      format: this.settings.dateFormat || options.format || "YYYY-MM-DD",
      template: this.settings.templatePath || options.template || ""
    };
  }

  async ensureFolder(path) {
    const parts = path.split("/").filter(Boolean); let current = "";
    for (const part of parts) { current = current ? `${current}/${part}` : part; if (!this.app.vault.getAbstractFileByPath(current)) await this.app.vault.createFolder(current); }
  }

  async getOrCreateDailyNote(date) {
    const opts = this.getDailyOptions();
    const name = formatDate(date, opts.format) + ".md";
    const path = opts.folder ? `${opts.folder}/${name}` : name;
    let file = this.app.vault.getAbstractFileByPath(path);
    if (file) return file;
    if (opts.folder) await this.ensureFolder(opts.folder);
    let content = "";
    if (opts.template) { const template = this.app.vault.getAbstractFileByPath(opts.template); if (template) content = await this.app.vault.read(template); }
    file = await this.app.vault.create(path, content);
    return file;
  }

  insertTask(content, line) {
    const heading = this.settings.insertionHeading.trim();
    if (!heading) return content.replace(/\s*$/, "") + "\n" + line + "\n";
    const lines = content.split("\n"); const index = lines.findIndex(l => l.trim() === heading);
    if (index < 0) return content.replace(/\s*$/, "") + `\n\n${heading}\n${line}\n`;
    lines.splice(index + 1, 0, line); return lines.join("\n");
  }

  async scheduleCurrentNote() {
    const source = this.app.workspace.getActiveFile();
    if (!source || source.extension !== "md") { new Notice("请先打开要安排的 Markdown 笔记"); return; }
    const input = await new ScheduleModal(this.app, this.settings).waitForResult();
    if (!input) return;
    const sourceContent = await this.app.vault.read(source);
    // 默认模式兼容旧设置 [[0]]，自动寻找 [[0]]…[[5]] 中实际出现的那个状态。
    const autoStatus = !this.settings.statusFrom || this.settings.statusFrom === "[[0]]" || this.settings.statusFrom === "[[0-5]]";
    const statusMatch = autoStatus ? sourceContent.match(/\[\[[0-5]\]\]/) : (sourceContent.includes(this.settings.statusFrom) ? [this.settings.statusFrom] : null);
    if (!statusMatch) { new Notice(autoStatus ? "当前笔记找不到 [[0]] 到 [[5]] 的状态" : `当前笔记找不到 ${this.settings.statusFrom}，未执行`); return; }
    const sourceStatus = statusMatch[0];
    const targetDate = addDays(new Date(), input.days);
    const target = await this.getOrCreateDailyNote(targetDate);
    const link = `[[${source.path.replace(/\\/g, "/").replace(/\.md$/i, "")}]]`;
    const due = this.settings.includeDueDate ? ` 📅 ${formatDate(targetDate, this.getDailyOptions().format)}` : "";
    const line = `${this.settings.taskPrefix.trim()} ${link}${due}`.trim();
    const targetContent = await this.app.vault.read(target);
    if (!targetContent.split("\n").some(l => l.trim() === line.trim())) await this.app.vault.modify(target, this.insertTask(targetContent, line));
    const replacement = `[[${input.status}]]`;
    const updated = this.settings.replaceAll ? sourceContent.split(sourceStatus).join(replacement) : sourceContent.replace(sourceStatus, replacement);
    await this.app.vault.modify(source, updated);
    new Notice(`已安排到 ${target.path}，并将状态更新为 ${replacement}`);
    if (this.settings.openTarget) await this.app.workspace.getLeaf(false).openFile(target);
  }
};
