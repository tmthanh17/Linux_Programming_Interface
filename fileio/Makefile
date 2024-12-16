# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I$(LIB_DIR)

LIBRARY := $(LIB_DIR)/*.a

# Name of the executable
MAIN_EXE := program

# The main source file to compile
MAIN_SRC := $(MAIN)
ifeq ($(MAIN_SRC),)
	MAIN_SRC = copy.c
endif
MAIN_OBJ := $(MAIN_SRC:%.c=%.o)

# Default target to build the executable
all: $(MAIN_EXE)

# Rule to build the executable
$(MAIN_EXE): $(MAIN_OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile main source files
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(MAIN_EXE) *.o