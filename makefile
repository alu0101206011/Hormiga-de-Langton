CC = g++
CFLAGS = -g -Wall --std=c++17
OBJ = ./obj/main_hormiga.o ./obj/mundo.o ./obj/hormiga.o ./obj/celda.o
EXEC = hormiga

all: $(OBJ)
	$(CC) $(CFLAGS) -o ./bin/$(EXEC) $^

./obj/%.o: ./src/%.cpp 
	$(CC) -c -o $@ $<

run: clean all
	./bin/$(EXEC)

.PHONY: clean

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o