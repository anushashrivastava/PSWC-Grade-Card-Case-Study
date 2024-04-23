CC = gcc
CFLAGS = -Wall -Wextra -I.

SRCS = main2.c student2.c
OBJS = $(SRCS:.c=.o)
EXECUTABLE = finalgrade

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXECUTABLE) $(OBJS)
