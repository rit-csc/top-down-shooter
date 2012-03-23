CXX=g++

LIBRARIES=-lsfml-system -lsfml-graphics -lsfml-window
CFLAGS = -I../SFML/include -L../SFML/lib $(LIBRARIES)
CXXFLAGS = $(CFLAGS)

all: main

main:
	$(CXX) $(CXXFLAGS) main.cpp -o main

clean:
	/bin/rm main
