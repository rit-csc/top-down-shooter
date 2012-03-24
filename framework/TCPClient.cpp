#include "TCPClient.h"
#include <iostream>

using namespace std;
using namespace sf;

TCPClient::TCPClient()
{
    isAlive = true;
    socket.setBlocking(false);
    status = Socket::Status::NotReady;
}

void TCPClient::tick()
{
    queueMutex.lock();
    while(!incomingMessages.empty())
    {
        sf::Packet* element = incomingMessages.front();
        incomingMessages.pop();

        session->onReceive(element);
        delete element;
    }
    queueMutex.unlock();
}

Socket::Status TCPClient::connect(const IpAddress remoteAddress, unsigned short remotePort, Time timeout)
{
    status = socket.connect(remoteAddress, remotePort, timeout);
}

void TCPClient::disconnect()
{
    socket.disconnect();
}

void TCPClient::shutdown()
{
    isAlive = false;
}

void TCPClient::run()
{
    while(isAlive)
    {
        if(status == Socket::Status::Done)
        {
            Packet* p = new Packet();
            status = session->receive(p);
            if(status != Socket::Status::Done)
            {
                delete p;
            }
            else
            {
                queueMutex.lock();
                incomingMessages.push(p);
                queueMutex.unlock();
            }
        }
        else
        {
            sleep(0.5f);
        }
        sleep(0.05f);
    }
}
