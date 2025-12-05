---

# LeetCode Practice Repository

本仓库用于持续练习 LeetCode 题目，记录解题思路、实现代码、调试环境配置，以及复盘总结。项目基于 **C++ + CMake + MinGW64 + VSCode** 的开发环境构建，可按题号持续扩展。

---

## 目录结构

```
.
├── CMakeLists.txt        # 顶层 CMake 配置
├── doc/                  # 题解文档（Markdown）
│   ├── solution_notes.md # 全局解题思路记录
│   └── p0001_two_sum.md  # 每题独立分析（可选）
├── src/
│   ├── p0001/
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   ├── p0002/
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   └── ...
└── build/                # CMake 构建目录（已加入 .gitignore）
```

---

## 环境说明

* **操作系统**：Windows
* **编译器**：MinGW64 (g++)
* **构建系统**：CMake
* **编辑器**：VSCode
* **扩展**：

  * CMake Tools
  * C/C++
  * CMake

---

## 如何添加新题目

1. 在 `src/` 下创建题目目录，例如：

```
src/p0002/
    main.cpp
    CMakeLists.txt
```

题目目录下的 `CMakeLists.txt` 示例：

```cmake
add_executable(p0002 main.cpp)
```

2. 在顶层 `CMakeLists.txt` 中引用：

```cmake
add_subdirectory(src/p0002)
```

3. VSCode 左下角：
   **CMake: 重新配置** → 生成可执行文件。

---

## VSCode 调试方法

1. 左下角选择要调试的目标，例如：`p0002`
2. 点击 “调试”（小虫子图标）
3. 若目标不更新，执行：
   **CMake: 重新配置** → **重新选择目标**

---
