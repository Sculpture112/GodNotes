var __getOwnPropNames = Object.getOwnPropertyNames;
var __commonJS = (cb, mod) => function __require() {
  return mod || (0, cb[__getOwnPropNames(cb)[0]])((mod = { exports: {} }).exports, mod), mod.exports;
};

// batch.js
var require_batch = __commonJS({
  "batch.js"(exports2, module2) {
    function parseDay(value) {
      if (!/^\d{4}-\d{2}-\d{2}$/.test(value)) throw new Error("\u8BF7\u586B\u5199\u5B8C\u6574\u65E5\u671F\uFF0C\u4F8B\u5982 2026-10-17");
      const date = /* @__PURE__ */ new Date(value + "T12:00:00Z");
      if (!Number.isFinite(date.getTime()) || dayString(date) !== value) throw new Error("\u65E5\u671F\u65E0\u6548\uFF1A" + value);
      return date;
    }
    function dayString(date) {
      return date.toISOString().slice(0, 10);
    }
    function shiftDay(day, offset) {
      const date = parseDay(day);
      date.setUTCDate(date.getUTCDate() + offset);
      return dayString(date);
    }
    function validateOptions(options) {
      parseDay(options.start);
      parseDay(options.end);
      parseDay(options.today);
      if (options.start > options.end) throw new Error("\u5F00\u59CB\u65E5\u671F\u4E0D\u80FD\u665A\u4E8E\u7ED3\u675F\u65E5\u671F");
      if (!Number.isInteger(options.minDays) || !Number.isInteger(options.maxDays) || options.minDays < 1 || options.maxDays < options.minDays || options.maxDays > 3660) {
        throw new Error("\u540E\u79FB\u5929\u6570\u987B\u4E3A 1\uFF5E3660 \u7684\u6574\u6570\uFF0C\u4E14\u6700\u5927\u503C\u4E0D\u5C0F\u4E8E\u6700\u5C0F\u503C");
      }
      if (!["today", "original"].includes(options.base)) throw new Error("\u8BF7\u9009\u62E9\u8BA1\u7B97\u8D77\u70B9");
    }
    function shuffle(values, random) {
      const result = values.slice();
      for (let i = result.length - 1; i > 0; i--) {
        const j = Math.floor(random() * (i + 1));
        [result[i], result[j]] = [result[j], result[i]];
      }
      return result;
    }
    function reviewTasks(content, heading = "## \u590D\u4E60") {
      let inReview = false;
      let level = 0;
      let fence = null;
      const result = [];
      content.split(/\r?\n/).forEach((line, index) => {
        const fenceMatch = line.match(/^\s*(`{3,}|~{3,})/);
        if (fenceMatch) {
          if (!fence) fence = fenceMatch[1];
          else if (fenceMatch[1][0] === fence[0] && fenceMatch[1].length >= fence.length) fence = null;
          return;
        }
        if (fence) return;
        const h = line.match(/^(#{1,6})\s+/);
        if (h && line.trim() === heading.trim()) {
          inReview = true;
          level = h[1].length;
          return;
        }
        if (h && h[1].length <= level) inReview = false;
        if (!inReview) return;
        const task = line.match(/^\s*- \[ \]\s+.*?\[\[(.+?)\]\]/);
        if (task) result.push({ index, line, link: task[1] });
      });
      return result;
    }
    function makePlan(files, options, random = Math.random) {
      validateOptions(options);
      const entries = [];
      const bags = /* @__PURE__ */ new Map();
      const byLink = /* @__PURE__ */ new Map();
      for (const file of files.slice().sort((a, b) => a.day.localeCompare(b.day))) {
        if (file.day < options.start || file.day > options.end) continue;
        for (const task of reviewTasks(file.content, options.heading)) {
          let assigned = byLink.get(task.link);
          if (!assigned) {
            const base = options.base === "today" ? options.today : file.day;
            if (!bags.get(base)?.length) {
              const offsets = Array.from({ length: options.maxDays - options.minDays + 1 }, (_, i) => i + options.minDays);
              bags.set(base, shuffle(offsets, random));
            }
            const offset = bags.get(base).pop();
            const targetDay = shiftDay(base, offset);
            if (targetDay <= options.today || targetDay <= options.end) {
              throw new Error("\u76EE\u6807\u65E5\u671F\u5FC5\u987B\u5728\u4ECA\u5929\u53CA\u539F\u65E5\u671F\u8303\u56F4\u4E4B\u540E\uFF1B\u8BF7\u589E\u5927\u540E\u79FB\u5929\u6570\u6216\u9009\u62E9\u4ECE\u4ECA\u5929\u8BA1\u7B97");
            }
            assigned = { offset, targetDay };
            byLink.set(task.link, assigned);
          }
          const newLine = task.line.replace(/📅\s*\d{4}-\d{2}-\d{2}/g, "").replace(/✅\s*\d{4}-\d{2}-\d{2}/g, "").replace(/\s+\^[\w-]+\s*$/, "").trimEnd() + " \u{1F4C5} " + options.today;
          entries.push({ ...task, ...assigned, sourcePath: file.path, sourceDay: file.day, newLine });
        }
      }
      return entries;
    }
    function insertReview(content, tasks, heading) {
      const existing = new Set(reviewTasks(content, heading).map((t) => t.link));
      const linesToAdd = [];
      for (const task of tasks) {
        if (!existing.has(task.link)) {
          linesToAdd.push(task.newLine);
          existing.add(task.link);
        }
      }
      if (!linesToAdd.length) return content;
      const eol = content.includes("\r\n") ? "\r\n" : "\n";
      const lines = content.split(/\r?\n/);
      const index = lines.findIndex((line) => line.trim() === heading.trim());
      if (index < 0) return content.replace(/\s*$/, "") + eol + eol + heading + eol + linesToAdd.join(eol) + eol;
      lines.splice(index + 1, 0, ...linesToAdd);
      return lines.join(eol);
    }
    function checkOriginal(content, entries, today) {
      const eol = content.includes("\r\n") ? "\r\n" : "\n";
      const lines = content.split(/\r?\n/);
      for (const entry of entries) {
        if (lines[entry.index] !== entry.line) throw new Error("\u539F\u4EFB\u52A1\u53D1\u751F\u53D8\u5316\uFF0C\u8BF7\u91CD\u65B0\u6253\u5F00\u6279\u91CF\u6392\u7A0B");
        lines[entry.index] = entry.line.replace(/- \[ \]/, "- [x]").replace(/\s+$/, "") + " \u2705 " + today;
      }
      return lines.join(eol);
    }
    module2.exports = { parseDay, shiftDay, validateOptions, reviewTasks, makePlan, insertReview, checkOriginal };
  }
});

// review-stage.js
var require_review_stage = __commonJS({
  "review-stage.js"(exports2, module2) {
    function reviewStage2(status) {
      const match = /^\[\[(\d+)\]\]$/.exec(status);
      if (!match) return null;
      const current = BigInt(match[1]);
      const next = current + 1n;
      let recommendedDays;
      if (current === 0n) recommendedDays = 3;
      else if (current === 1n) recommendedDays = 7;
      else if (current === 2n) recommendedDays = 10;
      else if (current === 3n) recommendedDays = 20;
      else if (current <= 5n) recommendedDays = 10;
      else if (current === 6n) recommendedDays = 30;
      else if (current <= 8n) recommendedDays = 14;
      else recommendedDays = current % 3n === 0n ? 45 : 20;
      return {
        nextStatus: next.toString(),
        recommendedDays,
        activity: next % 3n === 0n ? "\u91CD\u5199\u4EE3\u7801" : "\u9605\u8BFB\u9898\u610F\u3001\u4EE3\u7801"
      };
    }
    function findNumericStatus2(content) {
      return content.match(/\[\[\d+\]\]/)?.[0] || null;
    }
    function isAutoStatus2(value) {
      return !value || ["[[0]]", "[[0-5]]", "[[\u6570\u5B57]]"].includes(value);
    }
    module2.exports = { reviewStage: reviewStage2, findNumericStatus: findNumericStatus2, isAutoStatus: isAutoStatus2 };
  }
});

// main.js
var { Plugin, Notice, Modal, Setting, PluginSettingTab } = require("obsidian");
var batch = require_batch();
var { reviewStage, findNumericStatus, isAutoStatus } = require_review_stage();
var DEFAULT_SETTINGS = {
  dailyFolder: "",
  dateFormat: "",
  templatePath: "",
  insertionHeading: "## \u590D\u4E60",
  statusFrom: "[[\u6570\u5B57]]",
  taskPrefix: "- [ ]",
  includeDueDate: true,
  replaceAll: false,
  defaultDays: 1,
  fuzzyDates: false,
  defaultStatus: "1",
  openTarget: true
};
function pad(n) {
  return String(n).padStart(2, "0");
}
function formatDate(date, format) {
  const values = {
    YYYY: String(date.getFullYear()),
    YY: String(date.getFullYear()).slice(-2),
    MM: pad(date.getMonth() + 1),
    M: String(date.getMonth() + 1),
    DD: pad(date.getDate()),
    D: String(date.getDate())
  };
  return format.replace(/YYYY|YY|MM|M|DD|D/g, (token) => values[token]);
}
function addDays(date, days) {
  const result = new Date(date);
  result.setHours(12, 0, 0, 0);
  result.setDate(result.getDate() + days);
  return result;
}
var ScheduleModal = class extends Modal {
  constructor(app, plugin, currentStatus) {
    super(app);
    this.plugin = plugin;
    this.settings = plugin.settings;
    this.currentStatus = currentStatus;
    this.result = null;
    this.resolvePromise = null;
  }
  waitForResult() {
    return new Promise((resolve) => {
      this.resolvePromise = resolve;
      this.open();
    });
  }
  onOpen() {
    const { contentEl } = this;
    contentEl.empty();
    contentEl.createEl("h2", { text: "\u5B89\u6392\u5230\u672A\u6765\u65E5\u5386" });
    const stage = reviewStage(this.currentStatus);
    const recommendedDays = stage?.recommendedDays ?? this.settings.defaultDays;
    let daysInput;
    new Setting(contentEl).setName("x\uFF1A\u51E0\u5929\u540E").setDesc(stage ? `\u6839\u636E\u5F53\u524D\u6807\u7B7E ${this.currentStatus} \u63A8\u8350 ${recommendedDays} \u5929\uFF0C\u53EF\u624B\u52A8\u4FEE\u6539\u3002` : "0 \u8868\u793A\u4ECA\u5929\uFF0C\u5EFA\u8BAE\u4F7F\u7528\u6B63\u6574\u6570\u3002").addText((t) => {
      daysInput = t.inputEl;
      t.inputEl.type = "number";
      t.setValue(String(recommendedDays));
      t.inputEl.min = "0";
      t.inputEl.style.width = "100%";
    });
    const fuzzySetting = new Setting(contentEl).setName("\u6A21\u7CCA\u65E5\u671F").setDesc("\u52FE\u9009\u540E\uFF0C\u5728\u586B\u5199\u5929\u6570\u5230\u591A 7 \u5929\u4E4B\u95F4\u968F\u673A\u9009\u62E9\uFF08\u542B\u4E24\u7AEF\uFF09\u3002\u4F8B\u5982\u586B 20\uFF0C\u5C31\u968F\u673A\u5B89\u6392\u5728 20\uFF5E27 \u5929\u540E\u3002\u4F1A\u8BB0\u4F4F\u4E0A\u6B21\u9009\u62E9\u3002");
    const fuzzyCheckbox = fuzzySetting.controlEl.createEl("input", { type: "checkbox" });
    fuzzyCheckbox.setAttribute("aria-label", "\u6A21\u7CCA\u65E5\u671F");
    fuzzyCheckbox.checked = !!this.settings.fuzzyDates;
    fuzzyCheckbox.addEventListener("change", () => {
      this.settings.fuzzyDates = fuzzyCheckbox.checked;
      this.plugin.saveSettings().catch((error) => {
        console.error("[\u65E5\u5386\u72B6\u6001\u6392\u7A0B\u5668] \u4FDD\u5B58\u6A21\u7CCA\u65E5\u671F\u9009\u9879\u5931\u8D25", error);
        new Notice("\u6A21\u7CCA\u65E5\u671F\u9009\u9879\u4FDD\u5B58\u5931\u8D25\uFF0C\u8BF7\u91CD\u8BD5");
      });
    });
    let statusInput;
    const suggestedStatus = stage?.nextStatus ?? this.settings.defaultStatus;
    const activity = stage ? `\uFF1B\u672C\u8F6E\u9ED8\u8BA4\uFF1A${stage.activity}` : "";
    new Setting(contentEl).setName("y\uFF1A\u4FEE\u6539\u540E\u7684\u72B6\u6001").setDesc(`\u5F53\u524D\u72B6\u6001\uFF1A${this.currentStatus}\uFF1B\u9ED8\u8BA4\u66F4\u65B0\u4E3A [[${suggestedStatus}]]${activity}`).addText((t) => {
      statusInput = t.inputEl;
      t.setValue(suggestedStatus);
      t.inputEl.placeholder = "\u4F8B\u5982 2 \u6216 review";
      t.inputEl.style.width = "100%";
    });
    const buttons = contentEl.createDiv({ cls: "modal-button-container" });
    const cancel = buttons.createEl("button", { text: "\u53D6\u6D88" });
    cancel.addEventListener("click", () => this.close());
    const submit = buttons.createEl("button", { text: "\u6267\u884C", cls: "mod-cta" });
    submit.addEventListener("click", () => {
      const x = Number(daysInput?.value);
      const y = String(statusInput?.value || "").trim();
      if (!Number.isInteger(x) || x < 0) {
        new Notice("x \u5FC5\u987B\u662F\u5927\u4E8E\u7B49\u4E8E 0 \u7684\u6574\u6570");
        return;
      }
      if (!y || y.includes("[[") || y.includes("]]")) {
        new Notice("y \u4E0D\u80FD\u4E3A\u7A7A\uFF0C\u4E14\u4E0D\u80FD\u5305\u542B [[ \u6216 ]] ");
        return;
      }
      this.result = { days: x, status: y, fuzzyDates: fuzzyCheckbox.checked };
      this.close();
    });
    statusInput?.addEventListener("keydown", (e) => {
      if (e.key === "Enter") submit.click();
    });
  }
  onClose() {
    this.contentEl.empty();
    if (this.resolvePromise) this.resolvePromise(this.result);
  }
};
var BatchScheduleModal = class extends Modal {
  constructor(app, plugin) {
    super(app);
    this.plugin = plugin;
  }
  onOpen() {
    const today = formatDate(/* @__PURE__ */ new Date(), "YYYY-MM-DD");
    const previous = this.plugin.settings.batchOptions || {};
    const values = {
      start: previous.start || batch.shiftDay(today, -2),
      end: previous.end || batch.shiftDay(today, -1),
      minDays: previous.minDays ?? 1,
      maxDays: previous.maxDays ?? 7,
      base: previous.base || "today",
      today
    };
    const el = this.contentEl;
    el.empty();
    el.createEl("h2", { text: "\u6279\u91CF\u5206\u6563\u590D\u4E60\u4EFB\u52A1" });
    el.createEl("p", { text: "\u5904\u7406\u65E5\u671F\u8303\u56F4\u5185\u201C\u590D\u4E60\u201D\u533A\u57DF\u4E2D\u672A\u52FE\u9009\u3001\u5E26\u7B14\u8BB0\u94FE\u63A5\u7684\u4EFB\u52A1\u3002\u65B0\u4EFB\u52A1\u5C3D\u91CF\u5747\u5300\u968F\u673A\u5206\u6563\uFF0C\u539F\u6761\u76EE\u6253\u94A9\uFF0C\u9898\u76EE\u6807\u7B7E\u4FDD\u6301\u539F\u6837\u3002" });
    for (const [key, label] of [["start", "\u539F\u65E5\u5386\u5F00\u59CB\u65E5\u671F"], ["end", "\u539F\u65E5\u5386\u7ED3\u675F\u65E5\u671F\uFF08\u542B\u5F53\u5929\uFF09"]]) {
      new Setting(el).setName(label).addText((t) => {
        t.inputEl.type = "date";
        t.setValue(values[key]).onChange((v) => {
          values[key] = v;
        });
      });
    }
    new Setting(el).setName("\u4ECE\u54EA\u5929\u5F00\u59CB\u8BA1\u7B97").addDropdown((d) => d.addOption("today", "\u4ECA\u5929\uFF08\u5206\u6563\u5230\u672A\u6765\u51E0\u5929\uFF09").addOption("original", "\u6BCF\u6761\u4EFB\u52A1\u6240\u5728\u7684\u539F\u65E5\u5386\u65E5\u671F").setValue(values.base).onChange((v) => {
      values.base = v;
    }));
    for (const [key, label] of [["minDays", "\u6700\u5C11\u540E\u79FB\u5929\u6570"], ["maxDays", "\u6700\u591A\u540E\u79FB\u5929\u6570"]]) {
      new Setting(el).setName(label).addText((t) => {
        t.inputEl.type = "number";
        t.inputEl.min = "1";
        t.inputEl.step = "1";
        t.setValue(String(values[key])).onChange((v) => {
          values[key] = Number(v);
        });
      });
    }
    el.createEl("p", { text: "\u4F8B\u5982\uFF1A\u4ECE\u4ECA\u5929\u8BA1\u7B97\uFF0C\u6700\u5C11 1 \u5929\u3001\u6700\u591A 7 \u5929\uFF0C\u5373\u5206\u6563\u5230\u660E\u5929\u8D77\u7684\u4E03\u5929\u3002\u65E5\u671F\u6587\u4EF6\u4E0D\u5B58\u5728\u65F6\u4F7F\u7528\u65E5\u8BB0\u6A21\u677F\u521B\u5EFA\uFF1B\u6267\u884C\u524D\u81EA\u52A8\u5907\u4EFD\u3002" });
    const buttons = el.createDiv({ cls: "modal-button-container" });
    buttons.createEl("button", { text: "\u53D6\u6D88" }).addEventListener("click", () => this.close());
    const submit = buttons.createEl("button", { text: "\u5206\u6563\u5B89\u6392\u5E76\u52FE\u9009\u539F\u4EFB\u52A1", cls: "mod-cta" });
    submit.addEventListener("click", async () => {
      submit.disabled = true;
      try {
        batch.validateOptions(values);
        const result = await this.plugin.rescheduleRange(values);
        this.plugin.settings.batchOptions = { ...values };
        await this.plugin.saveSettings();
        new Notice(result.count ? `\u5DF2\u5904\u7406 ${result.count} \u6761\u539F\u4EFB\u52A1\uFF0C\u5B89\u6392 ${result.uniqueCount} \u4E2A\u7B14\u8BB0\u5230\u672A\u6765\u65E5\u5386` : "\u8FD9\u4E2A\u65E5\u671F\u8303\u56F4\u5185\u6CA1\u6709\u5F85\u79FB\u52A8\u7684\u590D\u4E60\u4EFB\u52A1");
        this.close();
      } catch (error) {
        console.error("[\u65E5\u5386\u72B6\u6001\u6392\u7A0B\u5668]", error);
        new Notice(error.message || String(error), 12e3);
      } finally {
        submit.disabled = false;
      }
    });
  }
  onClose() {
    this.contentEl.empty();
  }
};
var SchedulerSettingTab = class extends PluginSettingTab {
  constructor(app, plugin) {
    super(app, plugin);
    this.plugin = plugin;
  }
  display() {
    const { containerEl } = this;
    containerEl.empty();
    containerEl.createEl("h2", { text: "\u65E5\u5386\u72B6\u6001\u6392\u7A0B\u5668" });
    const s = this.plugin.settings;
    new Setting(containerEl).setName("\u65E5\u8BB0\u6587\u4EF6\u5939").setDesc("\u76F8\u5BF9\u4E8E\u5E93\u6839\u76EE\u5F55\uFF1B\u7559\u7A7A\u5219\u4F7F\u7528\u5E93\u6839\u76EE\u5F55\u3002\u793A\u4F8B\uFF1A\u65E5\u8BB0/\u6BCF\u65E5").addText((t) => t.setValue(s.dailyFolder).onChange(async (v) => {
      s.dailyFolder = v.trim().replace(/^\/+|\/+$/g, "");
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u65E5\u671F\u6587\u4EF6\u540D\u683C\u5F0F").setDesc("\u652F\u6301 YYYY\u3001MM\u3001DD\uFF1B\u7559\u7A7A\u5219\u76F4\u63A5\u4F7F\u7528 Periodic Notes \u7684\u65E5\u8BB0\u683C\u5F0F\u3002").addText((t) => t.setValue(s.dateFormat).onChange(async (v) => {
      s.dateFormat = v.trim();
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u65E5\u8BB0\u6A21\u677F\u8DEF\u5F84\uFF08\u53EF\u9009\uFF09").setDesc("\u76EE\u6807\u65E5\u8BB0\u4E0D\u5B58\u5728\u65F6\u590D\u5236\u6B64\u6A21\u677F\uFF0C\u4F8B\u5982 Templates/Daily.md\uFF1B\u7559\u7A7A\u5219\u521B\u5EFA\u7A7A\u6587\u4EF6\u3002").addText((t) => t.setValue(s.templatePath).onChange(async (v) => {
      s.templatePath = v.trim();
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u63D2\u5165\u6807\u9898\uFF08\u53EF\u9009\uFF09").setDesc("\u586B\u5199\u6A21\u677F\u4E2D\u7684\u5B8C\u6574\u6807\u9898\uFF08\u5982 ## \u4ECA\u65E5\u6E05\u5355\uFF09\uFF0C\u4EFB\u52A1\u4F1A\u63D2\u5165\u5176\u4E0B\u4E00\u884C\uFF1B\u627E\u4E0D\u5230\u65F6\u8FFD\u52A0\u5230\u6587\u4EF6\u672B\u5C3E\u3002").addText((t) => t.setValue(s.insertionHeading).onChange(async (v) => {
      s.insertionHeading = v;
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u5F85\u66FF\u6362\u72B6\u6001").setDesc("\u586B [[\u6570\u5B57]] \u81EA\u52A8\u8BC6\u522B\u975E\u8D1F\u6574\u6570\u6807\u7B7E\uFF0C\u5982 [[0]]\u3001[[12]]\uFF1B\u4E5F\u53EF\u586B\u56FA\u5B9A\u6587\u672C\uFF0C\u5982 [[todo]]\u3002").addText((t) => t.setValue(s.statusFrom).onChange(async (v) => {
      s.statusFrom = v || "[[\u6570\u5B57]]";
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u4EFB\u52A1\u524D\u7F00").setDesc("Tasks \u63D2\u4EF6\u901A\u5E38\u4F7F\u7528 - [ ]\uFF1B\u4E5F\u53EF\u4EE5\u6539\u6210\u666E\u901A\u5217\u8868\u524D\u7F00\u3002").addText((t) => t.setValue(s.taskPrefix).onChange(async (v) => {
      s.taskPrefix = v;
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u5199\u5165\u65E5\u671F\u6807\u8BB0").setDesc("\u542F\u7528\u540E\u5728\u4EFB\u52A1\u672B\u5C3E\u5199\u5165\u5B89\u6392\u5F53\u5929\u7684\u65E5\u671F\uFF08\u4E0D\u662F\u76EE\u6807\u65E5\u8BB0\u65E5\u671F\uFF09\u3002").addToggle((t) => t.setValue(s.includeDueDate).onChange(async (v) => {
      s.includeDueDate = v;
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u66FF\u6362\u6240\u6709\u72B6\u6001").addToggle((t) => t.setValue(s.replaceAll).onChange(async (v) => {
      s.replaceAll = v;
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u9ED8\u8BA4 x\uFF08\u975E\u6570\u5B57\u6807\u7B7E\u65F6\u4F7F\u7528\uFF09").setDesc("\u6570\u5B57\u6807\u7B7E\u4F1A\u6309\u590D\u4E60\u8F6E\u6B21\u81EA\u52A8\u63A8\u8350\u95F4\u9694\uFF1B\u5F39\u7A97\u4E2D\u7684\u5929\u6570\u4ECD\u53EF\u624B\u52A8\u4FEE\u6539\u3002").addText((t) => t.setValue(String(s.defaultDays)).onChange(async (v) => {
      const n = Number(v);
      if (Number.isInteger(n) && n >= 0) {
        s.defaultDays = n;
        await this.plugin.saveSettings();
      }
    }));
    new Setting(containerEl).setName("\u9ED8\u8BA4 y").addText((t) => t.setValue(s.defaultStatus).onChange(async (v) => {
      s.defaultStatus = v;
      await this.plugin.saveSettings();
    }));
    new Setting(containerEl).setName("\u6267\u884C\u540E\u6253\u5F00\u76EE\u6807\u65E5\u8BB0").addToggle((t) => t.setValue(s.openTarget).onChange(async (v) => {
      s.openTarget = v;
      await this.plugin.saveSettings();
    }));
  }
};
module.exports = class CalendarStatusScheduler extends Plugin {
  async onload() {
    await this.loadSettings();
    this.addCommand({ id: "schedule-current-note", name: "\u5B89\u6392\u5F53\u524D\u7B14\u8BB0\u5230\u672A\u6765\u65E5\u5386\u5E76\u66F4\u65B0\u72B6\u6001", callback: () => this.scheduleCurrentNote() });
    this.addRibbonIcon("calendar-plus", "\u5B89\u6392\u5F53\u524D\u7B14\u8BB0\u5230\u672A\u6765\u65E5\u5386", () => this.scheduleCurrentNote());
    this.addCommand({ id: "mark-zero-and-review-tomorrow", name: "\u6807\u8BB0\u4E3A 0 \u5E76\u5B89\u6392 3\uFF5E7 \u5929\u540E\u590D\u4E60", callback: () => this.markZeroAndReviewTomorrow() });
    this.addRibbonIcon("tag", "\u6807\u8BB0\u4E3A 0 \u5E76\u5B89\u6392 3\uFF5E7 \u5929\u540E\u590D\u4E60", () => this.markZeroAndReviewTomorrow());
    this.addCommand({ id: "batch-reschedule-reviews", name: "\u6309\u65E5\u671F\u8303\u56F4\u6279\u91CF\u5206\u6563\u590D\u4E60\u4EFB\u52A1", callback: () => new BatchScheduleModal(this.app, this).open() });
    this.addRibbonIcon("circle", "\u6279\u91CF\u5206\u6563\u590D\u4E60\u4EFB\u52A1\uFF08\u65E5\u671F\u548C\u5929\u6570\u53EF\u8BBE\u7F6E\uFF09", () => new BatchScheduleModal(this.app, this).open());
    this.addSettingTab(new SchedulerSettingTab(this.app, this));
  }
  async loadSettings() {
    this.settings = Object.assign({}, DEFAULT_SETTINGS, await this.loadData());
    if (isAutoStatus(this.settings.statusFrom)) this.settings.statusFrom = "[[\u6570\u5B57]]";
  }
  async saveSettings() {
    await this.saveData(this.settings);
  }
  async rescheduleRange(input) {
    if (this.batchRunning) throw new Error("\u6B63\u5728\u6279\u91CF\u6392\u7A0B\uFF0C\u8BF7\u7A0D\u5019");
    this.batchRunning = true;
    let backupPath;
    try {
      const options = { ...input, heading: this.settings.insertionHeading.trim() || "## \u590D\u4E60" };
      batch.validateOptions(options);
      if (batch.shiftDay(options.start, 3660) < options.end) throw new Error("\u4E00\u6B21\u6700\u591A\u5904\u7406\u5341\u5E74\u7684\u65E5\u671F\u8303\u56F4");
      const daily = this.getDailyOptions();
      const pathFor = (day) => {
        const name = window.moment(day, "YYYY-MM-DD", true).format(daily.format) + ".md";
        return [daily.folder.replace(/\\/g, "/").replace(/^\/+|\/+$/g, ""), name].filter(Boolean).join("/");
      };
      const files = [];
      for (let day = options.start; day <= options.end; day = batch.shiftDay(day, 1)) {
        const path = pathFor(day);
        const file = this.app.vault.getAbstractFileByPath(path);
        if (file?.extension === "md") files.push({ day, path, content: await this.app.vault.read(file) });
      }
      const plan = batch.makePlan(files, options);
      if (!plan.length) return { count: 0, uniqueCount: 0, plan: [] };
      const changes = [];
      let templateContent = "";
      if (daily.template) {
        const template = this.app.vault.getAbstractFileByPath(daily.template) || this.app.vault.getAbstractFileByPath(daily.template + ".md");
        if (!template) throw new Error("\u627E\u4E0D\u5230\u65E5\u8BB0\u6A21\u677F\uFF1A" + daily.template);
        templateContent = await this.app.vault.read(template);
      }
      for (const day of [...new Set(plan.map((t) => t.targetDay))].sort()) {
        const path = pathFor(day);
        const file = this.app.vault.getAbstractFileByPath(path);
        if (file && file.extension !== "md") throw new Error("\u76EE\u6807\u8DEF\u5F84\u4E0D\u662F Markdown \u6587\u4EF6\uFF1A" + path);
        const before = file ? await this.app.vault.read(file) : null;
        const initial = before ?? this.renderTemplate(templateContent, window.moment(day, "YYYY-MM-DD", true).toDate(), daily.format);
        changes.push({ path, before, after: batch.insertReview(initial, plan.filter((t) => t.targetDay === day), options.heading) });
      }
      for (const file of files) {
        const entries = plan.filter((t) => t.sourcePath === file.path);
        if (entries.length) changes.push({ path: file.path, before: file.content, after: batch.checkOriginal(file.content, entries, options.today) });
      }
      const backupFolder = `${this.app.vault.configDir}/plugins/${this.manifest.id}/backups`;
      const adapter = this.app.vault.adapter;
      if (!await adapter.exists(backupFolder)) await adapter.mkdir(backupFolder);
      backupPath = `${backupFolder}/batch-${Date.now()}-${Math.random().toString(36).slice(2, 8)}.json`;
      await adapter.write(backupPath, JSON.stringify({ options, plan, changes }, null, 2));
      const checkUnchanged = async (change) => {
        const file = this.app.vault.getAbstractFileByPath(change.path);
        if (change.before === null ? !!file : !file || await this.app.vault.read(file) !== change.before) {
          throw new Error("\u65E5\u5386\u5728\u6392\u7A0B\u8FC7\u7A0B\u4E2D\u53D1\u751F\u53D8\u5316\uFF0C\u8BF7\u91CD\u65B0\u6267\u884C\uFF1A" + change.path);
        }
        return file;
      };
      for (const change of changes) await checkUnchanged(change);
      for (const change of changes) {
        const file = await checkUnchanged(change);
        if (file) await this.app.vault.modify(file, change.after);
        else {
          const parent = change.path.split("/").slice(0, -1).join("/");
          if (parent) await this.ensureFolder(parent);
          await this.app.vault.create(change.path, change.after);
        }
      }
      return { count: plan.length, uniqueCount: new Set(plan.map((t) => t.link)).size, plan, backupPath };
    } catch (error) {
      if (backupPath) error.message += `\uFF1B\u672C\u6B21\u5907\u4EFD\uFF1A${backupPath}`;
      throw error;
    } finally {
      this.batchRunning = false;
    }
  }
  getDailyOptions() {
    const periodic = this.app.plugins?.getPlugin?.("periodic-notes");
    const legacyDaily = periodic?.settings?.daily;
    if (legacyDaily?.enabled) {
      return {
        folder: this.settings.dailyFolder || legacyDaily.folder || "",
        format: this.settings.dateFormat || legacyDaily.format || "YYYY-MM-DD",
        template: this.settings.templatePath || legacyDaily.template || ""
      };
    }
    if (periodic?.calendarSetManager) {
      try {
        const config = periodic.calendarSetManager.getActiveConfig("day") || {};
        const format = periodic.calendarSetManager.getFormat("day") || "YYYY-MM-DD";
        return {
          folder: this.settings.dailyFolder || config.folder || "",
          format: this.settings.dateFormat || format,
          template: this.settings.templatePath || config.templatePath || ""
        };
      } catch (_) {
      }
    }
    const daily = this.app.internalPlugins?.getPluginById?.("daily-notes");
    const options = daily?.instance?.options || {};
    return {
      folder: this.settings.dailyFolder || options.folder || "",
      format: this.settings.dateFormat || options.format || "YYYY-MM-DD",
      template: this.settings.templatePath || options.template || ""
    };
  }
  async ensureFolder(path) {
    const parts = path.split("/").filter(Boolean);
    let current = "";
    for (const part of parts) {
      current = current ? `${current}/${part}` : part;
      if (!this.app.vault.getAbstractFileByPath(current)) await this.app.vault.createFolder(current);
    }
  }
  async getOrCreateDailyNote(date) {
    const periodic = this.app.plugins?.getPlugin?.("periodic-notes");
    const opts = this.getDailyOptions();
    const name = formatDate(date, opts.format) + ".md";
    const path = opts.folder ? `${opts.folder}/${name}` : name;
    let file = this.app.vault.getAbstractFileByPath(path);
    if (file) return file;
    if (opts.folder) await this.ensureFolder(opts.folder);
    let content = "";
    if (opts.template) {
      const template = this.app.vault.getAbstractFileByPath(opts.template);
      if (template) content = this.renderTemplate(await this.app.vault.read(template), date, opts.format);
    }
    file = await this.app.vault.create(path, content);
    return file;
  }
  renderTemplate(content, date, format) {
    const m = window.moment(date);
    return content.replace(/{{\s*date\s*}}/gi, m.format(format)).replace(/{{\s*title\s*}}/gi, m.format(format)).replace(/{{\s*date\s*:\s*([^}]+)}}/gi, (_, f) => m.format(f.trim())).replace(/{{\s*yesterday\s*}}/gi, m.clone().subtract(1, "day").format(format)).replace(/{{\s*tomorrow\s*}}/gi, m.clone().add(1, "day").format(format));
  }
  insertTask(content, line) {
    const heading = this.settings.insertionHeading.trim();
    if (!heading) return content.replace(/\s*$/, "") + "\n" + line + "\n";
    const lines = content.split("\n");
    const index = lines.findIndex((l) => l.trim() === heading);
    if (index < 0) return content.replace(/\s*$/, "") + `

${heading}
${line}
`;
    lines.splice(index + 1, 0, line);
    return lines.join("\n");
  }
  makeReviewLine(source) {
    const link = `[[${source.path.replace(/\\/g, "/").replace(/\.md$/i, "")}]]`;
    const dateMarker = this.settings.includeDueDate ? ` \u{1F4C5} ${formatDate(/* @__PURE__ */ new Date(), this.getDailyOptions().format)}` : "";
    return `${this.settings.taskPrefix.trim()} ${link}${dateMarker}`.trim();
  }
  async addNoteToReviewDate(source, targetDate) {
    const target = await this.getOrCreateDailyNote(targetDate);
    const line = this.makeReviewLine(source);
    const targetContent = await this.app.vault.read(target);
    if (!targetContent.split("\n").some((existing) => existing.trim() === line.trim())) {
      await this.app.vault.modify(target, this.insertTask(targetContent, line));
    }
    return target;
  }
  async markZeroAndReviewTomorrow() {
    const source = this.app.workspace.getActiveFile();
    if (!source || source.extension !== "md") {
      new Notice("\u8BF7\u5148\u6253\u5F00\u8981\u5904\u7406\u7684 Markdown \u7B14\u8BB0");
      return;
    }
    const sourceContent = await this.app.vault.read(source);
    if (findNumericStatus(sourceContent)) {
      new Notice("\u5DF2\u7ECF\u6709\u6807\u7B7E\u4E86~");
      return;
    }
    const lines = sourceContent.split(/\r?\n/);
    const firstContentLine = lines.findIndex((line) => line.trim() !== "");
    if (firstContentLine < 0 || !/^#\s*\[\]\s*$/.test(lines[firstContentLine].trim())) {
      new Notice("\u7B2C\u4E00\u884C\u6CA1\u6709\u627E\u5230 # []\uFF0C\u672A\u6267\u884C");
      return;
    }
    lines[firstContentLine] = lines[firstContentLine].replace(/\[\]/, "[[0]]");
    const actualDays = 3 + Math.floor(Math.random() * 5);
    const target = await this.addNoteToReviewDate(source, addDays(/* @__PURE__ */ new Date(), actualDays));
    await this.app.vault.modify(source, lines.join("\n"));
    new Notice(`\u5DF2\u6DFB\u52A0 [[0]]\uFF0C\u5E76\u5B89\u6392\u5230 ${target.path} \u7684\u590D\u4E60\u533A\uFF08${actualDays} \u5929\u540E\uFF09`);
    if (this.settings.openTarget) await this.app.workspace.getLeaf(false).openFile(target);
  }
  async scheduleCurrentNote() {
    const source = this.app.workspace.getActiveFile();
    if (!source || source.extension !== "md") {
      new Notice("\u8BF7\u5148\u6253\u5F00\u8981\u5B89\u6392\u7684 Markdown \u7B14\u8BB0");
      return;
    }
    const sourceContent = await this.app.vault.read(source);
    const autoStatus = isAutoStatus(this.settings.statusFrom);
    const sourceStatus = autoStatus ? findNumericStatus(sourceContent) : sourceContent.includes(this.settings.statusFrom) ? this.settings.statusFrom : null;
    if (!sourceStatus) {
      new Notice(autoStatus ? "\u5F53\u524D\u7B14\u8BB0\u627E\u4E0D\u5230\u975E\u8D1F\u6574\u6570\u72B6\u6001\u6807\u7B7E\uFF0C\u5982 [[0]]\u3001[[12]]" : `\u5F53\u524D\u7B14\u8BB0\u627E\u4E0D\u5230 ${this.settings.statusFrom}\uFF0C\u672A\u6267\u884C`);
      return;
    }
    const input = await new ScheduleModal(this.app, this, sourceStatus).waitForResult();
    if (!input) return;
    const actualDays = input.days + (input.fuzzyDates ? Math.floor(Math.random() * 8) : 0);
    const targetDate = addDays(/* @__PURE__ */ new Date(), actualDays);
    const target = await this.addNoteToReviewDate(source, targetDate);
    const replacement = `[[${input.status}]]`;
    const updated = this.settings.replaceAll ? sourceContent.split(sourceStatus).join(replacement) : sourceContent.replace(sourceStatus, replacement);
    await this.app.vault.modify(source, updated);
    new Notice(`\u5DF2\u5B89\u6392\u5230 ${target.path}\uFF08${actualDays} \u5929\u540E\uFF09\uFF0C\u5E76\u5C06\u72B6\u6001\u66F4\u65B0\u4E3A ${replacement}`);
    if (this.settings.openTarget) await this.app.workspace.getLeaf(false).openFile(target);
  }
};
