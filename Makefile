CC = gcc

CFLAGS = -Wall -Wextra -std=c99


TARGET = student_registry


all: $(TARGET)


$(TARGET): main.o student_registry.o
	$(CC) $(CFLAGS) main.o student_registry.o -o $(TARGET)


main.o: main.c student_registry.h
	$(CC) $(CFLAGS) -c main.c


student_registry.o: student_registry.c student_registry.h
	$(CC) $(CFLAGS) -c student_registry.c



run: $(TARGET)
	./$(TARGET)



clean:
	rm -f *.o $(TARGET)
