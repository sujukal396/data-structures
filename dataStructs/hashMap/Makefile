CC= gcc
DB= -ggdb -g -Wall -Wextra -I./include

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

TARGET = $(BIN_DIR)/output

$(TARGET) : $(SRCS)
	$(CC) $(DB) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

.PHONY: clean


clean:
	@rm -f $(TARGET) $(OBJECTS) core

-include $(DEPS)
