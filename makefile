CC = g++
CFLAGS = -g -Wall --std=c++17
OBJ = ./obj/vector.o ./obj/posicion.o ./obj/movimiento.o ./obj/celda.o ./obj/reglas.o ./obj/hormiga.o ./obj/mundo.o ./obj/mundofinito.o ./obj/mundoinfinito.o ./obj/universo.o ./obj/main_functions.o ./obj/main_hormiga.o 
EXEC = ./bin/hormiga

all: $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $^

./obj/%.o: ./src/%.cpp 
	$(CC) -c -o $@ $<

run: clean all
	$(EXEC)

.PHONY: clean

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o