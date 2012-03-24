CXX=g++
RM=rm

LIBRARIES=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-network
CFLAGS = -I../SFML/include -L../SFML/lib
CXXFLAGS = $(CFLAGS) -std=gnu++0x

all: main

main:
	$(CXX) $(CXXFLAGS) main.cpp network/network.cpp network/Session.cpp network/TCPServer.cpp network/TCPClient.cpp -o main $(LIBRARIES)

clean:
	$(RM) main
