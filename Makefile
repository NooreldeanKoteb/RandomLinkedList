# simple Makefile
# Nooreldean Koteb G01085380
# CS262, lab section 209
# Lab11

CC= gcc
CFLAGS=-g -o0 -Wall
TARGET= RandomLinkedList

all:$(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
	rm $(TARGET)
