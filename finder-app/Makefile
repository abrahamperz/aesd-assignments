# Makefile - AESD Assignment 2
# Builds the "writer" application.
#
#   make                         -> native build (uses gcc)
#   make CROSS_COMPILE=aarch64-none-linux-gnu-   -> cross build for aarch64
#   make clean                   -> remove the writer app and all .o files

CROSS_COMPILE ?=
CC      := $(CROSS_COMPILE)gcc
CFLAGS  ?= -Wall -Werror -g

TARGET  := writer
OBJS    := writer.o

.PHONY: all clean

# Default target builds the writer application.
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

writer.o: writer.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Remove the writer application and all object files.
clean:
	rm -f $(TARGET) *.o
