# Android Native / 内核学习资源

最后检查：2026-08-25。以下优先收录官方文档与仍在维护的 GitHub 仓库，按 Android Native ELF -> 内核模块 -> KernelPatch / 启动镜像的学习路径排列。

## 使用方式

不要同时学习所有内容。每阶段完成“先看”资源后再进入下一阶段。第一遍建议按此顺序：

1. ELF 格式与 ARM64 调用约定
2. Android `.so` / JNI 与动态链接器
3. Frida Native API 与小型示例
4. Linux 字符设备与 `ioctl`
5. Linux 可加载内核模块
6. KernelPatch KPM 源码与构建脚手架
7. KernelSU、Magisk 与 Android 启动镜像

这些资料仅用于学习你拥有或获授权分析的软件。

## 1. ELF、ARM64 与 Android Native 库

| 先看什么 | 链接 | 学什么 |
| --- | --- | --- |
| ELF 64 可视化入门 | [corkami ELF101 PDF](https://github.com/corkami/pics/blob/master/binary/elf101/elf101-64.pdf) | ELF 头、程序头、节、符号和重定位。建议最先阅读。 |
| ELF 参考手册 | [man7: elf(5)](https://man7.org/linux/man-pages/man5/elf.5.html) | `readelf` 中 ELF 字段的准确含义。 |
| AArch64 ABI | [ARM AAPCS64](https://github.com/ARM-software/abi-aa/blob/main/aapcs64/aapcs64.rst) | 函数参数、返回值、栈对齐、被调用方保存寄存器。读 ARM64 伪代码前必须理解。 |
| ARM64 指令参考 | [Arm A64 instruction index](https://developer.arm.com/documentation/ddi0596/latest/Base-Instructions) | 查询 `ADRP`、`LDR`、`BL`、`RET`、条件跳转等单条指令。 |
| Android NDK 概览 | [Android NDK guides](https://developer.android.com/ndk/guides) | Android Native `.so` 库的构建和打包方式。 |
| JNI 实用指南 | [Android JNI tips](https://developer.android.com/training/articles/perf-jni) | Java/Kotlin 与原生 C/C++ 的边界。 |
| Android linker 源码 | [AOSP bionic linker](https://android.googlesource.com/platform/bionic/+/refs/heads/main/linker/) | Android 动态链接器（`linker` / `linker64`）的真实实现。先掌握 ELF 基础再读。 |
| Ghidra | [NationalSecurityAgency/ghidra](https://github.com/NationalSecurityAgency/ghidra) | 免费打开 ARM64 ELF / Android `.so` 文件的 IDA 替代工具。 |

看完后可用的搜索词：

```text
ELF 文件格式 入门
ARM64 汇编 函数调用约定
Android so 文件结构
readelf objdump nm 教程
Ghidra Android so ARM64
```

练习：自己编译一个很小的 C 动态库，再用 `file`、`readelf -h -l -S -s`、`nm -D`、`objdump -d` 查看它。分析大型受保护文件前，先完成这一步。

## 2. 使用 Frida 做 Android Native 动态分析

| 先看什么 | 链接 | 学什么 |
| --- | --- | --- |
| Frida 项目 | [frida/frida](https://github.com/frida/frida) | 源码、发布版本和 Frida 生态入口。 |
| JavaScript API | [Frida JavaScript API](https://frida.re/docs/javascript-api/) | `Process`、`Module`、`Interceptor`、`NativeFunction`、内存 API 与 Stalker。这是首要参考文档。 |
| Android 使用方式 | [Frida Android examples](https://frida.re/docs/examples/android/) | attach/spawn 与 Android 基础用法。 |
| JNI Hook 辅助项目 | [Areizen/JNI-Frida-Hook](https://github.com/Areizen/JNI-Frida-Hook) | 观察 JNI 到 Native 调用的专用示例。阅读脚本即可，不要将它当成通用方案。 |
| Native 跟踪工具 | [xbyl1234/android_analysis](https://github.com/xbyl1234/android_analysis) | Native/JNI 跟踪示例与辅助 Android 分析工具。 |
| 最小 Native Hook 示例 | [0x3xploit/frida-android-jni-hooking](https://github.com/0x3xploit/frida-android-jni-hooking) | 小型 Native 函数 Hook 示例及说明。 |

建议顺序：

```text
Frida JavaScript API：Module + Interceptor
-> NativePointer / NativeFunction
-> 在测试 App 中观察一次 JNI 调用
-> 只有常规函数 Hook 不够时才学习 Stalker
```

更容易搜到实际示例的词：

```text
Frida Interceptor.attach Android so
Frida Module.findExportByName tutorial
Frida NativeFunction Android
Frida hook JNI native function
Frida Stalker ARM64 tutorial
```

## 3. Linux 字符设备、ioctl 与内核模块

| 先看什么 | 链接 | 学什么 |
| --- | --- | --- |
| 内核模块教材 | [The Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/) | 构建、加载与卸载最小模块。它是本阶段的入门主线。 |
| 教材源码 | [sysprog21/lkmpg](https://github.com/sysprog21/lkmpg) | 可运行示例及教材源文件。 |
| Linux 驱动 API | [Kernel driver API docs](https://docs.kernel.org/driver-api/) | 官方文档索引。 |
| 字符设备 | [Kernel char-device infrastructure](https://docs.kernel.org/core-api/kernel-api.html#char-devices) | 设备号、`cdev` 与基础注册概念。 |
| ioctl 用户态/内核态接口 | [Kernel ioctl docs](https://docs.kernel.org/driver-api/ioctl.html) | 如何安全、兼容地设计 `ioctl` ABI。 |
| 用户空间访问辅助函数 | [uaccess.h source](https://github.com/torvalds/linux/blob/master/include/linux/uaccess.h) | `copy_to_user`、`copy_from_user` 的上下文；搭配字符设备样例阅读。 |
| 进程地址空间相关类型 | [Linux `sched.h` source](https://github.com/torvalds/linux/blob/master/include/linux/sched.h) | `task_struct` 所在位置；适合作为参考，不是入门教程。 |
| 内存管理相关类型 | [Linux `mm_types.h` source](https://github.com/torvalds/linux/blob/master/include/linux/mm_types.h) | `mm_struct` 与虚拟内存数据结构。 |
| ARM64 内存文档 | [Linux ARM64 memory layout](https://docs.kernel.org/arch/arm64/memory.html) | ARM64 架构特有的虚拟地址背景。 |
| 内核符号 | [Kernel symbol namespaces](https://docs.kernel.org/core-api/symbol-namespaces.html) | 为什么并非每个内核函数都是稳定、已导出的模块 API。 |
| 模块兼容性 | [Kernel modules docs](https://docs.kernel.org/kbuild/modules.html) | 外部模块构建，以及版本和 `vermagic` 的注意事项。 |

按这个顺序搜索：

```text
Linux 内核模块 入门
Linux 字符设备驱动 file_operations
Linux ioctl 驱动 示例
copy_to_user copy_from_user
Linux task_struct mm_struct
ARM64 Linux virtual memory page table
```

重要边界：驱动数据结构和已导出的 API 会随内核版本变化。不要直接套教程代码；先对比 `.ko` 的 `vermagic` 与目标内核的源码、配置是否匹配。

## 4. KernelPatch KPM 与内核插桩

KPM 是 KernelPatch 专用格式，因此可靠路径是先读其上游源码，再看小型构建/示例仓库。进入本节前，应先掌握普通 Linux 内核模块的基本概念。

| 先看什么 | 链接 | 学什么 |
| --- | --- | --- |
| KernelPatch 上游 | [bmax121/KernelPatch](https://github.com/bmax121/KernelPatch) | 主源码、文档、API 与 issue。KPM 和 `kptools` 的定义从这里开始看。 |
| KPM 开发脚手架 | [jiqiu2022/kpm-spore](https://github.com/jiqiu2022/kpm-spore) | KPM 模块的起步结构与开发说明。 |
| 跨环境构建 | [liankong233/KPM-Build-Anywhere](https://github.com/liankong233/KPM-Build-Anywhere) | 跨环境构建 KPM 的流程。使用前检查它支持的 KernelPatch 版本。 |
| Kernel Trace 示例 | [AndroidReverser-Test/Kernel-Trace](https://github.com/AndroidReverser-Test/Kernel-Trace) | 基于 uprobe 的进阶 KPM 示例；用于阅读项目架构，而不是第一个应运行的 KPM 模块。 |
| ftrace | [Kernel ftrace docs](https://docs.kernel.org/trace/ftrace.html) | 内核支持的跟踪机制；比临时修改代码更稳妥的概念基础。 |
| kprobes | [Kernel kprobes docs](https://docs.kernel.org/trace/kprobes.html) | 动态插桩的概念和限制。 |
| procfs | [Kernel procfs docs](https://docs.kernel.org/filesystems/proc.html) | `/proc` 接口以及 `/proc/<pid>/maps` 的背景知识。 |

搜索词：

```text
KernelPatch KPM module development
KernelPatch kptools
KernelPatch KPM API
Linux kprobe ftrace tutorial
Linux proc pid maps source
ARM64 inline hook principle
```

源码级示例均与版本强相关。针对一个具体 `.kpm`，先确定它对应的 KernelPatch 版本，再把其导入的符号/API 映射回该版本的上游源码。

## 5. KernelSU、Magisk 与 Android 启动镜像

| 先看什么 | 链接 | 学什么 |
| --- | --- | --- |
| KernelSU 上游 | [tiann/KernelSU](https://github.com/tiann/KernelSU) | KernelSU 架构、支持设备、安装与模块行为。 |
| KernelSU 文档 | [KernelSU docs](https://kernelsu.org/guide/introduction.html) | 比源码更适合作为安装和模块概念的起点。 |
| Magisk 上游 | [topjohnwu/Magisk](https://github.com/topjohnwu/Magisk) | Magisk / `magiskboot` 的源码和发布信息。 |
| Magisk 模块指南 | [Magisk module guides](https://topjohnwu.github.io/Magisk/guides.html) | 模块目录、脚本、`module.prop` 与执行生命周期。 |
| Android 启动镜像规范 | [AOSP boot image header](https://source.android.com/docs/core/architecture/bootloader/boot-image-header) | 官方的 boot/vendor_boot/init_boot 结构与头部版本。 |
| 通用 boot 分区 | [AOSP generic boot docs](https://source.android.com/docs/core/architecture/partitions/generic-boot) | 为什么新设备可能使用 `init_boot`，而非仅使用 `boot`。 |
| 启动镜像编辑器 | [cfig/Android_boot_image_editor](https://github.com/cfig/Android_boot_image_editor) | 检查/重新打包 `boot.img`、`vbmeta.img` 及相关文件。 |
| Unpackbootimg 工具 | [anestisb/android-unpackbootimg](https://github.com/anestisb/android-unpackbootimg) | 较小的启动镜像解包/回包工具集。 |

建议按此顺序搜索：

```text
Android boot image structure
boot img init_boot vendor_boot difference
KernelSU module guide
Magisk module development
magiskboot unpack repack
Android Verified Boot AVB overview
```

不要因为镜像能成功解包就直接刷入。先保存原始镜像，确认设备型号、代号、分区布局，并了解该设备对应的 AVB 和回滚保护。

## 6. 陌生文件名速查

| 名称 | 含义 |
| --- | --- |
| ELF | Executable and Linkable Format（可执行与可链接格式）。Android Native 可执行文件和 `.so` 动态库通常采用它。 |
| `.so` | Shared Object（共享对象）/ 动态库。在 Android 上通常包含 NDK/JNI/Native C 或 C++ 代码。 |
| ARM64 / AArch64 | 当前大多数 Android 设备使用的 64 位 ARM 指令集架构。 |
| `.ko` | Linux 可加载内核模块，必须与目标内核高度匹配。 |
| `ioctl` | 用户态通过文件描述符向设备驱动发送命令的接口。 |
| KPM / `.kpm` | KernelPatch Module 格式，不是通用 Linux 标准。 |
| boot.img / init_boot.img | Android 启动链镜像；具体职责取决于 Android 版本和设备代际。 |

## 最小学习检查清单

- [ ] 能解释 ELF 程序头与节头的区别。
- [ ] 能根据 AAPCS64 判断 ARM64 函数的输入/输出（`x0`-`x7`、`x0`）。
- [ ] 能在 Ghidra 中打开自行构建的 Android `.so`，找到一个导出函数。
- [ ] 能使用 Frida 观察一个已获授权测试 App 的 Native 函数。
- [ ] 能在合适的测试虚拟机中构建并加载无害的 "hello" Linux 模块。
- [ ] 能读懂字符驱动的 `file_operations`，并解释其 `unlocked_ioctl` 路径。
- [ ] 在检查 KPM 二进制文件前，先读 KernelPatch 上游文档。
- [ ] 操作镜像前，能确认设备是否使用 `boot`、`vendor_boot`、`init_boot`。
