CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = magic_square

SRC = magic_square.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

