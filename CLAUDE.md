# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Current state

This is a bare C project skeleton — four files, all stubs. There is no build system, no test
framework, no git repository, and no dependency manifest. Do not assume a build command exists;
if one is needed, ask the user for their intended toolchain (Makefile, CMake, vendor IDE project,
etc.) before adding one.

## Layout

Source is split across two top-level trees, each following the same `Inc`/`Src` pairing:

- `Core/` — `main.c` / `main.h`; entry point lives in `Core/Src/main.c`.
- `Func/` — functional modules; each module is a `Src/<name>.c` + `Inc/<name>.h` pair
  (`sys.c` / `sys.h` is the only one so far).

Headers are included by bare name (e.g. `#include "sys.h"`), so every `Inc` directory is expected
to be on the include path. A new module means a new `.c`/`.h` pair in `Func/Src` and `Func/Inc`;
declare its prototypes in the header and guard it with `__NAME_H`, matching the existing files.

Cross-tree dependencies currently run one way: `Core` may call into `Func` (via the public
headers), not the reverse. `Func` modules should not include `main.h`.

## 用户要求
1.每次对话需要使用中文与用户交流。
2.本工程目的是学习cmake构建，教会用户使用cmake。
3.你只有读文件权利，其他权限应询问用户。