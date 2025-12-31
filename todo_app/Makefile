# Compiler & flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -I./include -std=c11
LDFLAGS =
# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := lib
DIST_DIR:= dist
# Files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(DIST_DIR)/todo_app

.PHONY: all clean

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS) | $(DIST_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(DIST_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(DIST_DIR)
