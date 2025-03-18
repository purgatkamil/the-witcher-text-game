# Kompilator i flagi
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -static-libgcc -static-libstdc++

# Ścieżki do katalogów
SRC_DIR := App
TEST_DIR := App/Tests
BUILD_DIR := build
GTEST_DIR := googletest
GTEST_BUILD := $(GTEST_DIR)/build
GTEST_INSTALL := $(GTEST_DIR)/install

# Pliki źródłowe aplikacji
SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp" ! -path "$(TEST_DIR)/*")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
TARGET := $(BUILD_DIR)/app.exe

# ---- Google Test ----
GTEST_INCLUDES := -I$(GTEST_INSTALL)/include
GTEST_LIBS := -L$(GTEST_INSTALL)/lib -lgtest -lgtest_main

$(GTEST_INSTALL):
	@if [ ! -d "$(GTEST_DIR)" ]; then git clone https://github.com/google/googletest.git $(GTEST_DIR); fi
	mkdir -p $(GTEST_BUILD)
	cd $(GTEST_BUILD) && cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_INSTALL_PREFIX=$(GTEST_INSTALL) ..
	cd $(GTEST_BUILD) && mingw32-make && mingw32-make install

# ---- Kompilacja aplikacji ----
all: $(GTEST_INSTALL) $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ---- Kompilacja testów ----
TEST_SOURCES := $(shell find $(TEST_DIR) -type f -name "*.cpp")
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SOURCES))
TEST_BINARY := $(BUILD_DIR)/test_runner.exe

$(TEST_BINARY): $(TEST_OBJECTS) $(GTEST_LIBS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) $(TEST_OBJECTS) $(GTEST_LIBS) -pthread -o $(TEST_BINARY)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(GTEST_INSTALL)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) -c $< -o $@

# ---- Reguły Make ----
.PHONY: test
test: $(TEST_BINARY)
	./$(TEST_BINARY)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(GTEST_DIR)
