# A source library xPack with Catch2, a modern, C++-native, test framework for unit-tests

This project provides the **Catch2** source library as an xPack dependency.

The project is hosted on GitHub as
[xpack-3rd-party/catch2-xpack](https://github.com/xpack-3rd-party/catch2-xpack).

## Maintainer info

This page is addressed to developers who plan to include this source
library into their own projects.

For maintainer info, please see the
[README-MAINTAINER-XPACK](README-MAINTAINER-XPACK.md) file.

## Install

As a source library xPack, the easiest way to add it to a project is via
**xpm**, but it can also be used as any Git project, for example as a submodule.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

### xpm

This package is available from npmjs.com as
[`@xpack-3rd-party/catch2`](https://www.npmjs.com/package/@xpack-3rd-party/catch2)
from the `npmjs.com` registry:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @xpack-3rd-party/catch2@latest

ls -l xpacks/xpack-3rd-party-catch2
```

### Git submodule

If, for any reason, **xpm** is not available, the next recommended
solution is to link it as a Git submodule below an `xpacks` folder.

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/xpack-3rd-party/catch2-xpack.git \
  xpacks/xpack-3rd-party-catch2
```

## Branches

There are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch. (Only contributions
related to the xPack integration are accepted, functional contributions
should be addressed to the upstream project.)

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## Developer info

### Overview

This package provides the full Catch2 code, but when
installed via xpm the content is filtered and only the
include folders are used.

In addition to the source files, the
configuration files required to integrate it into
CMake and meson projects, by building a static library.

### Build & integration info

The project is written in C++

For embedded platforms it can be built
on top of an Arm semihosting environment.

#### Include folders

The following folders should be passed to the compiler during the build:

- `single_include`

The header files to be included in user projects are:

```c++
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
```

#### Source files

The source files to be added to user projects are:

- none

#### Preprocessor definitions

There are several proprocessor definitions used to configure the build.

For embedded platfroms, use:

- `-D_POSIX_C_SOURCE=200809L`

This will enable POSIX support in newlib.

#### Compiler options

- `-std=c++20` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- `Catch`

#### C++ Classes

The project includes many classes; see the documentation for details.

#### CMake

To integrate the Google Test source library into a CMake application,
add this folder to the build:

```cmake
add_subdirectory("xpacks/xpack-3rd-party-catch2")`
```

The result is a static library that can be added as an application
dependency with:

```cmake
target_link_libraries(your-target PRIVATE
  ...
  xpack-3rd-party::catch2
)
```

#### meson

To integrate the Google Test source library into a meson application,
add this folder to the build:

```meson
subdir('xpacks/xpack-3rd-party-catch2')
```

The result is a static library and a dependency object that can be added
as an application dependency with:

```meson
exe = executable(
  your-target,

  c_args: xpack_3rd_party_catch2_dependency_c_args,
  cpp_args: xpack_3rd_party_catch2_dependency_cpp_args,
  dependencies: [
    xpack_3rd_party_catch2_dependency,
  ],
)
```

### Example

A simple example showing how to use the Google Test framework is
presented below and is also available in
[tests-xpack/src/sample-test.cpp](tests-xpack/src/sample-test.cpp).

```c++
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// ...

TEST_CASE ("Check various conditions")
{
  CHECK (compute_one () == 1);
  CHECK (strcmp (compute_aaa (), "aaa") == 0);
  CHECK (compute_condition ());
}
```

### Known problems

- none

### Tests

The project is fully tested via GitHub
[Actions](https://github.com/xpack-3rd-party/catch2-xpack/actions/)
on each push.
The test platforms are GNU/Linux, macOS and Windows, the tests are
compiled with GCC, clang and arm-none-eabi-gcc and run natively or
via QEMU.

There are two sets of tests, one that runs on every push, with a
limited number of tests, and a set that is triggered manually,
usually before releases, and runs all tests on all supported
platforms.

The full set can be run manually with the following commands:

```sh
cd ~Work/catch2-xpack.git

xpm run install-all
xpm run test-all
```

### Documentation

Tho original documentation is available on-line:

- <https://github.com/catchorg/Catch2/tree/devel/docs/>

## License

The xPack content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).

The upstream content is provided under the terms of the Boost Software License 1.0.

---

The original README content follows.

<a id="top"></a>
![catch logo](artwork/catch2-logo-small.png)

[![Github Releases](https://img.shields.io/github/release/catchorg/catch2.svg)](https://github.com/catchorg/catch2/releases)
[![Build Status](https://travis-ci.org/catchorg/Catch2.svg?branch=v2.x)](https://travis-ci.org/catchorg/Catch2)
[![Build status](https://ci.appveyor.com/api/projects/status/github/catchorg/Catch2?svg=true)](https://ci.appveyor.com/project/catchorg/catch2)
[![codecov](https://codecov.io/gh/catchorg/Catch2/branch/v2.x/graph/badge.svg)](https://codecov.io/gh/catchorg/Catch2)
[![Try online](https://img.shields.io/badge/try-online-blue.svg)](https://wandbox.org/permlink/6JUH8Eybx4CtvkJS)
[![Join the chat in Discord: https://discord.gg/4CWS9zD](https://img.shields.io/badge/Discord-Chat!-brightgreen.svg)](https://discord.gg/4CWS9zD)


<a href="https://github.com/catchorg/Catch2/releases/download/v2.13.8/catch.hpp">The latest version of the single header can be downloaded directly using this link</a>

## Catch2 is released!

If you've been using an earlier version of Catch, please see the
Breaking Changes section of [the release notes](https://github.com/catchorg/Catch2/releases/tag/v2.0.1)
before moving to Catch2. You might also like to read [this blog post](https://levelofindirection.com/blog/catch2-released.html) for more details.

## What's the Catch?

Catch2 is a multi-paradigm test framework for C++. which also supports
Objective-C (and maybe C).
It is primarily distributed as a single header file, although certain
extensions may require additional headers.

## How to use it
This documentation comprises these three parts:

* [Why do we need yet another C++ Test Framework?](docs/why-catch.md#top)
* [Tutorial](docs/tutorial.md#top) - getting started
* [Reference section](docs/Readme.md#top) - all the details

## More
* Issues and bugs can be raised on the [Issue tracker on GitHub](https://github.com/catchorg/Catch2/issues)
* For discussion or questions please use [the dedicated Google Groups forum](https://groups.google.com/forum/?fromgroups#!forum/catch-forum) or our [Discord](https://discord.gg/4CWS9zD)
* See [who else is using Catch2](docs/opensource-users.md#top)
