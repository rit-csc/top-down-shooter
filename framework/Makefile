CXX=g++
RM=rm

LIBRARIES=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-network
CFLAGS = -I../SFML/include -L../SFML/lib
CXXFLAGS = $(CFLAGS) -std=gnu++0x

all: main

main:
	$(CXX) $(CXXFLAGS) main.cpp Session.cpp TCPServer.cpp -o main $(LIBRARIES)

clean:
	$(RM) main
