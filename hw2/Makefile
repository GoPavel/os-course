CC=gcc
CC_FLAGS=-m32
PROJECT=jit
OBJ=jit.o

all: $(PROJECT)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(PROJECT): $(OBJ)
	$(CC) $(CC_FLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(OBJ) $(PROJECT)

run: clean $(PROJECT)
	./$(PROJECT)


check:  $(PROJECT)
	valgrind ./$(PROJECT)
