CC = gcc
CFLAGS = -Wall -g -fPIC

LIB_SRCS := error_functions.c get_num.c

LIB_OBJS := $(LIB_SRCS:%.c=%.o)

STATIC_LIB := mylib.a
DYNAMIC_LIB := mylib.so

all: $(STATIC_LIB) 
# $(DYNAMIC_LIB)

$(STATIC_LIB): $(LIB_OBJS)
	ar rcs $@ $^

$(DYNAMIC_LIB): $(LIB_OBJS)
	$(CC) -shared -o $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_OBJS) $(STATIC_LIB) $(DYNAMIC_LIB)