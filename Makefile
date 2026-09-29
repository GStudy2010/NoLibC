CC = gcc
AR = ar

CFLAGS = -ffreestanding -Wall -Wextra -I src/include

BUILD_DIR = build
LIB = $(BUILD_DIR)/libnolibc.a

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)

TEST = tests/bin/test

.PHONY: all clean test

all: $(LIB)

$(LIB): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB)
	@mkdir -p tests/bin
	$(CC) $(CFLAGS) \
		-nostdlib \
		-nostartfiles \
		-nodefaultlibs \
		-Wl,-e,_start \
		tests/main.c \
		$(LIB) \
		-o $(TEST)

clean:
	rm -rf $(BUILD_DIR) tests/bin

