#=========================================================
#  Project : Student Record Management System
#  Author  : Prabhu
#=========================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = student_db

SRC = main.c \
      menu.c \
      utils.c \
      file.c \
      add.c \
      delete.c \
      modify.c \
      display.c \
      sort.c \
      reverse.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

rebuild: clean all