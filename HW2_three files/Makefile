SRCS := main.c func.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS := -c -Wall

main : $(OBJS)
        $(CC) -o $@ $^

clean :
        -rm $(OBJS)
        rm main

dep :
        gccmakedep $(SRCS)
