# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR = src
INCLUDE_DIR = inc
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Target executable
TARGET = rush_02

# Default target (the first one defined in the Makefile)
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
fclean:
	rm -rf $(BUILD_DIR); rm -f $(TARGET)

.PHONY: all, fclean
