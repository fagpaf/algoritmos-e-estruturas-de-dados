CC = gcc
CFLAGS = -I./include
DEPS = List.h
OBJ = teste.o List.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o teste

# make
# ./teste
