# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -static-libgcc -static-libstdc++

# Directories
SRC_DIR := App
TEST_DIR := App/Tests
BUILD_DIR := build
GTEST_DIR := external/googletest
GTEST_BUILD := $(GTEST_DIR)/build

# Application source files
SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp" ! -path "$(TEST_DIR)/*")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/app_%.o, $(SOURCES))
TARGET := $(BUILD_DIR)/app.exe

# GoogleTest (submodule version)
GTEST_INCLUDES := -I$(GTEST_DIR)/googletest/include
GTEST_LIB_PATH := -L$(GTEST_BUILD)/lib
GTEST_LIBS := -lgtest -lgtest_main -pthread

# Ensure submodule is initialized
$(GTEST_DIR):
	git submodule update --init --recursive

# Build Google Test if not built
$(GTEST_BUILD)/lib/libgtest.a: $(GTEST_DIR)
	mkdir -p $(GTEST_BUILD)
	cd $(GTEST_BUILD) && cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ .. && mingw32-make

# Application compilation
.PHONY: all
all: app test

.PHONY: app
app: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/app_%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test compilation
TEST_SOURCES := $(shell find $(TEST_DIR) -type f -name "*.cpp")
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/test_%.o, $(TEST_SOURCES))
TEST_BINARY := $(BUILD_DIR)/test_runner.exe

.PHONY: test
test: $(GTEST_BUILD)/lib/libgtest.a $(TEST_BINARY)

$(TEST_BINARY): $(TEST_OBJECTS) $(GTEST_BUILD)/lib/libgtest.a
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) $(GTEST_LIB_PATH) $(TEST_OBJECTS) $(GTEST_LIBS) -o $(TEST_BINARY)

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp $(GTEST_BUILD)/lib/libgtest.a
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) -c $< -o $@

# Cleanup
clean:
	rm -rf $(BUILD_DIR) $(GTEST_BUILD)
