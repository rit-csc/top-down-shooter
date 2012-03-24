#include "Session.hpp"
#include <iostream>

using namespace std;
using namespace sf;

Socket::Status Session::receive(Packet* p)
{
    Lock lock(socketMutex);
    return socket->receive(*p);
}

void Session::send(Packet& packet) 
{
    Lock lock(socketMutex);
    socket->send(packet);
}

void Session::onReceive(Packet* packet)
{
    printf("I got a packet!\n");
}
