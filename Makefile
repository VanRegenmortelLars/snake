CC=g++
CFLAGS=
DEPS = point.h snake.h
OBJ = point.o snake.o main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o snake.out
