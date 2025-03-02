CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

SRC_DIR := App

BUILD_DIR := build

SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp")

OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

TARGET := $(BUILD_DIR)/app

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
