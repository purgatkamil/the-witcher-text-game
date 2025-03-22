# Witcher Text RPG (C++)

**A fan text game inspired by _The Witcher 1_. The goal was to combine the hobby with gaining experience in object-oriented C++.**

This project is a console-based RPG game written in C++, structured using modern OOP principles. It includes automated unit testing with Google Test and continuous integration via GitHub Actions. The build system is based on a robust `Makefile` that supports compiling both the game and its test suite.

## 📁 Project Structure

```
.
├── App/
│   ├── Character/
│   │   ├── character.cpp
│   │   └── character.hpp
│   ├── Descriptions/
│   ├── Fight/
│   ├── Map/
│   ├── Tests/
│   ├── App.cpp
│   └── types.hpp
├── build/
├── external/
├── .github/
├── .vscode/
├── .gitignore
├── .gitmodules
├── Makefile
└── README.md
```

## ⚙️ Requirements

- GCC / G++ with C++17 support
- `make`
- `cmake`
- (Windows) MinGW with `mingw32-make`
- Git (for cloning submodules)

## 🧱 Building the Project

1. **Clone the repository with submodules**:

   ```bash
   git clone --recurse-submodules <repository-url>
   ```

2. **Build the application and tests**:

   ```bash
   make all
   ```

3. **Run tests**:

   ```bash
   make test
   ```

4. **Clean build artifacts**:

   ```bash
   make clean
   ```

## 🧪 Testing with Google Test

Unit tests are written using [Google Test](https://github.com/google/googletest) and are located in `App/Tests/`. The build system automatically builds Google Test if it hasn't been built already. When `make test` is executed, the test binary is compiled and run.

## 🛠️ Makefile Overview

- Compiles all `.cpp` files from `App/` (excluding test files) into an executable `build/app.exe`.
- Builds unit tests from `App/Tests/` and links them with Google Test.
- Automatically initializes and builds Google Test from the `external/googletest/` submodule.
- Supports the following targets:
  - `make all` – build both application and tests
  - `make app` – build the main application only
  - `make test` – build and run unit tests
  - `make clean` – remove all build artifacts

## 🚀 CI/CD with GitHub Actions

The project includes a GitHub Actions workflow for Windows that automates:

- Setting up the MinGW environment
- Building the application and unit tests
- Running all tests
- Uploading the final `app.exe` binary as an artifact

The workflow triggers automatically on pushes to the `main` branch or any branch starting with `jobs/` or `tests/`.

You can find the workflow file at `.github/workflows/build.yml`.

---
