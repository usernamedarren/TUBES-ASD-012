CC = gcc
CFLAGS = -Wall
TARGET = purrmart

SRCS = src/ADT/arraybarang/arraybarang.c \
       src/ADT/circular_queue/circular_queue.c \
       src/main.c \
       src/ADT/mesinkata/mesinkata.c \
       src/ADT/mesinkarakter/mesinkarakter.c \
       src/ADT/arrayuser/arrayuser.c \
       src/console.c
       
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	del /Q *.o purrmart
