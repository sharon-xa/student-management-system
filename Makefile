# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source and Object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Output executable inside the build directory
TARGET = $(BUILD_DIR)/student_mgmt

# Default target
all: $(TARGET)

# Build the executable in the build directory
$(TARGET): $(OBJS) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $^ -o $@

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Clean the build directory
clean:
	@rm -rf $(BUILD_DIR)

# Run the program
run: $(TARGET)
	@./$(TARGET)

# Phony targets
.PHONY: all clean run test
