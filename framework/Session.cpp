#include "Session.h"
#include <iostream>

using namespace std;
using namespace sf;

bool Session::receive(Packet* p)
{
    Lock lock(socketMutex);
    return socket->receive(*p) == Socket::Done;
}

void Session::send(Packet& packet) 
{
    Lock lock(socketMutex);
    socket->send(packet);
}

void Session::onReceive(Packet* packet)
{
    printf("I got a packet!");
}
