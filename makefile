CC=g++
CFLAGS=
DEPS = point.h
OBJ = point.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
