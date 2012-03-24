#include "TCPServer.h"
#include <iostream>

using namespace std;
using namespace sf;

TCPServer::TCPServer(unsigned short listeningPort)
    : isAlive(true)
{
    listener.listen(listeningPort);
}

void TCPServer::tick() {
    queueMutex.lock();
    while(!incomingMessages.empty())
    {
        std::pair<std::shared_ptr<Session>, sf::Packet*> element = incomingMessages.front();
        incomingMessages.pop();
        
        element.first->onReceive(element.second);
        delete element.second;
    }
    queueMutex.unlock();
}

bool TCPServer::isShutdown() 
{
    return isAlive;
}

void TCPServer::shutdown() 
{
    isAlive = false;
}

void TCPServer::run() 
{
    SocketSelector selector;
    selector.add(listener);

    int numberSocketsReady = 0;
    while(isAlive) 
    {
        //Make the selector wait for anything
        if(selector.wait())
        {
            if(selector.isReady(listener))
            {
                //Add New Connection
                TcpSocket* client = new TcpSocket;
                if(listener.accept(*client) == Socket::Done)
                {
                    std::shared_ptr<Session> session = std::make_shared<Session>(client);
                    sessions.push_back(session);
                    printf("Got connection!\n");
                }
            }
            else
            {
                auto it = sessions.begin(), end = sessions.end();
                for(;it != end; ++it)
                {
                    Packet* p = new Packet();
                    if(!(*it)->receive(p) == Socket::Done)
                    {
                        //Disconnected
                        sessions.erase(it);
                        delete p;
                    }
                    else
                    {
                        queueMutex.lock();
                        incomingMessages.push(std::make_pair(*it, p));
                        queueMutex.unlock();
                    }
                }
            }
        }
    }
    
}
