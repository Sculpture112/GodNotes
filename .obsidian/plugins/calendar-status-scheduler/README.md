# 日历状态排程器

一个面向 Calendar/Periodic Notes + Tasks 工作流的 Obsidian 插件。命令“安排当前笔记到未来日历并更新状态”会：

1. 输入 `x`（几天后）和 `y`（新状态）。
2. 在目标 daily note 中写入 `- [ ] [[当前笔记]] 📅 YYYY-MM-DD`。
3. 默认自动找到源笔记中唯一出现的 `[[0]]`、`[[1]]`、…、`[[5]]`（也可在设置中改成固定文本），替换为 `[[y]]`。

## 安装（开发版）

把本目录复制到 vault 的 `.obsidian/plugins/calendar-status-scheduler/`，确认其中有 `manifest.json` 和 `main.js`，然后在 Obsidian → 设置 → 社区插件中启用。

## 首次设置

- 如果启用了 Periodic Notes，插件会优先调用它的 daily note API，因此会自动使用活动日历组的 `Daily` 文件夹、日期格式和 `Templates/每日清单.md` 模板；也能在设置中手动覆盖这些选项。
- 如果没有启用 Periodic Notes，才需要手动填写**日记文件夹**和**日期文件名格式**。
- 如果希望未来文件使用和点击 Calendar 一样的模板，填写**日记模板路径**，或者先在 Calendar 中点击目标日期让它创建文件。
- 你的模板使用 `## 今天做了啥`，插件默认会把任务插入这个标题下一行；也可以在设置中改成其他标题。

插件不改变 Calendar 的行为；它只向 Calendar 打开的 daily note 写入 Tasks 可识别的任务行。
