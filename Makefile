CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = filehandling
SRC = filehandling.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) students.dat