CC = gcc
override CFLAGS += -g -Wno-unused-result -Wno-everything -pthread -lm

SRCS = $(shell find . \( -name '.ccls-cache' -o -name 'tests' \) -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . \( -name '.ccls-cache' -o -name 'tests' \)  -prune -o -type f -name '*.h' -print)

TEST_SRCS = $(shell find . \( -name '.ccls-cache' -o -name 'main.c' \) -prune -o -type f -name '*.c' -print)

TEST_HEADERS = $(shell find . \( -name '.ccls-cache' -o -name 'main.c' \) -prune -o -type f -name '*.h' -print)

TARGET = vector_operations
TEST_TARGET = test_vector_operations

.DEFAULT_GOAL := all
all: $(TEST_TARGET) $(TARGET)

.PHONY: run

run: 

	./test_vector_operations 

	./vector_operations 

$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

$(TARGET)-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@" 

$(TEST_TARGET): $(TEST_SRCS) $(TEST_HEADERS)
	$(CC) $(CFLAGS) $(TEST_SRCS) -o "$@" ./test_vector_operations

clean:
	rm -f $(TARGET) $(TARGET).o vector.o $(TARGET)-debug $(TEST_TARGET) $(TEST_TARGET).o
