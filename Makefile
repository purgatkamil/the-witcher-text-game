# Kompilator i flagi
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -static-libgcc -static-libstdc++

# Ścieżki
SRC_DIR := App
TEST_DIR := App/Tests
BUILD_DIR := build
GTEST_DIR := googletest
GTEST_BUILD := $(GTEST_DIR)/build
GTEST_INSTALL := $(GTEST_DIR)/install

# Pliki aplikacji
SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp" ! -path "$(TEST_DIR)/*")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
TARGET := $(BUILD_DIR)/app.exe

# GoogleTest
GTEST_INCLUDES := -I$(GTEST_INSTALL)/include
GTEST_LIBS := -L$(GTEST_INSTALL)/lib -lgtest -lgtest_main

# Instalacja GoogleTest
$(GTEST_INSTALL)/lib/libgtest.a:
	git clone https://github.com/google/googletest.git $(GTEST_DIR) || true
	mkdir -p $(GTEST_BUILD)
	cd $(GTEST_BUILD) && \
		cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_INSTALL_PREFIX=../install .. && \
		mingw32-make && mingw32-make install

# Kompilacja aplikacji
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Kompilacja testów
TEST_SOURCES := $(shell find $(TEST_DIR) -type f -name "*.cpp")
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SOURCES))
TEST_BINARY := $(BUILD_DIR)/test_runner.exe

test: $(TEST_BINARY)
	./$(TEST_BINARY)

$(TEST_BINARY): $(TEST_OBJECTS) $(GTEST_INSTALL)/lib/libgtest.a
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) $(TEST_OBJECTS) $(GTEST_LIBS) -pthread -o $(TEST_BINARY)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp $(GTEST_INSTALL)/lib/libgtest.a
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) -c $< -o $@

# Czyszczenie
clean:
	rm -rf $(BUILD_DIR) $(GTEST_DIR)

.PHONY: all test clean
