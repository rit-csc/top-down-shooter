CXX=g++
RM=rm

LIBRARIES=-lsfml-system -lsfml-graphics -lsfml-window
CFLAGS = -I../SFML/include -L../SFML/lib
CXXFLAGS = $(CFLAGS)

all: main

main:
	$(CXX) $(CXXFLAGS) main.cpp -o main $(LIBRARIES)

clean:
	$(RM) main
