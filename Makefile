CC = gcc

IPATH =
LPATH =

CFLAGS = $(IPATH) -g -Wall -Werror
LDFLAGS = $(LPATH) -lGL -lGLU -lm

all: matrix4x4.o

matrix4x4.o: matrix4x4.c matrix4x4.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf matrix4x4.o

.PHONY: all clean

