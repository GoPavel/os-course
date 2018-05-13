CXX=g++
CXXFLAGS= -std=c++14 -Wunreachable-code -Wall -Wextra -fsanitize=address,undefined
PROJECT=shell
OBJ=shell.o

all: $(PROJECT)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(PROJECT)

run: $(PROJECT)
	./$(PROJECT)

regen: clean run
