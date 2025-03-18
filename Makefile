CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -static-libgcc -static-libstdc++

SRC_DIR := App
TEST_DIR := App/Tests
BUILD_DIR := build
GTEST_DIR := googletest
GTEST_BUILD := $(GTEST_DIR)/build

SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp" ! -path "$(TEST_DIR)/*")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
TARGET := $(BUILD_DIR)/app

# ---- Google Test ----
GTEST_LIBS := $(GTEST_BUILD)/lib/libgtest.a $(GTEST_BUILD)/lib/libgtest_main.a
GTEST_INCLUDES := -I$(GTEST_DIR)/googletest/include

$(GTEST_LIBS):
	git clone https://github.com/google/googletest.git || true
	mkdir -p $(GTEST_BUILD) && cd $(GTEST_BUILD) && cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ .. && mingw32-make

# ---- App compilation----
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ---- Tests compilation ----
TEST_SOURCES := $(shell find $(TEST_DIR) -type f -name "*.cpp")
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SOURCES))
TEST_BINARY := $(BUILD_DIR)/test_runner

$(TEST_BINARY): $(TEST_OBJECTS) $(GTEST_LIBS)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) $(TEST_OBJECTS) $(GTEST_LIBS) -pthread -o $(TEST_BINARY)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) -c $< -o $@

.PHONY: test
test: $(TEST_BINARY)
	./$(TEST_BINARY)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(GTEST_DIR)