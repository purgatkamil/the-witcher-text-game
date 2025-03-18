CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -static-libgcc -static-libstdc++

# Directories
SRC_DIR := App
TEST_DIR := App/Tests
BUILD_DIR := build
GTEST_DIR := googletest
GTEST_BUILD := $(GTEST_DIR)/build

# Find all application source files (excluding test files)
SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp" ! -path "$(TEST_DIR)/*")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/app_%.o, $(SOURCES))
TARGET := $(BUILD_DIR)/app.exe  # Ensure .exe extension on Windows

# ---- Google Test ----
GTEST_LIBS := $(GTEST_BUILD)/lib/libgtest.a $(GTEST_BUILD)/lib/libgtest_main.a
GTEST_INCLUDES := -I$(GTEST_DIR)/googletest/include

$(GTEST_LIBS):
	git clone https://github.com/google/googletest.git || true
	mkdir -p $(GTEST_BUILD) && cd $(GTEST_BUILD) && cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ .. && mingw32-make

# ---- Build Everything ----
.PHONY: all
all: app test  # Now `make` alone will build both app and test

# ---- Application Compilation ----
.PHONY: app
app: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Compile application object files
$(BUILD_DIR)/app_%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ---- Tests Compilation ----
TEST_SOURCES := $(shell find $(TEST_DIR) -type f -name "*.cpp")
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/test_%.o, $(TEST_SOURCES))
TEST_BINARY := $(BUILD_DIR)/test_runner.exe  # Ensure .exe extension on Windows

.PHONY: test
test: $(TEST_BINARY)

# Compile test binary
$(TEST_BINARY): $(TEST_OBJECTS) $(GTEST_LIBS)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) $(TEST_OBJECTS) $(GTEST_LIBS) -pthread -o $(TEST_BINARY)

# Compile test object files
$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) -c $< -o $@

# ---- Cleanup ----
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(GTEST_DIR)
