##########################################################################
## DEPENDENCIAS DEL PROGRAMA.
##########################################################################

	BIN = bin
	SRC = src
	INC = include
	OBJ = obj

	CXX = g++
	CXXFLAGS = -Wall -g -I$(INC) -c
	LDXFLAGS = -std=c++03

# ************ Creación de todo ************

all: juego

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Creación de ejecutables ************

juego: jugador.o tablero.o matriz.o main.o
	$(CXX) $(OBJ)/matriz.o $(OBJ)/tablero.o $(OBJ)/jugador.o $(OBJ)/main.o -o $(BIN)/juego $(LDXFLAGS)

# ************ Compilación de módulos ************

tablero.o: $(INC)/tablero.h $(SRC)/tablero.cpp 
	$(CXX) $(CXXFLAGS) $(SRC)/tablero.cpp -o $(OBJ)/tablero.o

jugador.o : $(INC)/jugador.h $(SRC)/jugador.cpp 
	$(CXX) $(CXXFLAGS) $(SRC)/jugador.cpp -o $(OBJ)/jugador.o

matriz.o : $(INC)/matriz.h $(SRC)/matriz.cpp 
	$(CXX) $(CXXFLAGS) $(SRC)/matriz.cpp -o $(OBJ)/matriz.o

main.o : $(SRC)/main.cpp 
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

# ************ Limpieza ************

clean:
	echo "Limpiado..."
	-rm $(OBJ)/* 

mrproper: clean
	-rm -R $(BIN)/* doc/html doc/latex doc/rtf *.txt
 

