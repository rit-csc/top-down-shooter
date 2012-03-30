CXX=g++
RM=rm

LIBRARIES=-lsfml-system -lsfml-graphics -lsfml-window
CFLAGS = -I../SFML/include -L../SFML/lib
CXXFLAGS = $(CFLAGS)

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) helpers/faststring.cpp main.cpp -o main $(LIBRARIES)

clean:
	$(RM) main
