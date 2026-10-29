CXX := g++
CXXFLAGS := -Iinclude

SRC_DIR := src
BUILD_DIR := build

SRCS := $(shell find $(SRC_DIR) -name "*.cpp")
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
EXEC_FILE := xml.out

$(EXEC_FILE): $(OBJS)
	@$(CXX) -static -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf build
