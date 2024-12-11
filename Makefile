# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lcurl

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and target definitions
SRC = $(SRC_DIR)/simple_https.c
TARGET = $(BUILD_DIR)/simple_https

# Default target
all: $(TARGET)

# Create the build directory and compile the executable
$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
