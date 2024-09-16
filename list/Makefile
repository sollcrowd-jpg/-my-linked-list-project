# Makefile for list implementation and test file

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable name
TARGET = list

# Source files
SRCS = list.c main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
