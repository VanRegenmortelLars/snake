CC=g++
CFLAGS=
DEPS = point.h snake.h
OBJ = point.o snake.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
