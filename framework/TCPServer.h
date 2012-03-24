#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <queue>
#include <list>
#include <set>

#include "Session.h"

class TCPServer
{
private:
    volatile bool isAlive;
    
    std::list<std::shared_ptr<Session>> sessions;
    
    std::queue<std::pair<std::shared_ptr<Session>, sf::Packet*>> incomingMessages;
    sf::Mutex queueMutex;
    
    sf::TcpListener listener;
    
public:
    TCPServer(short listeningPort);
    
    void tick();
    
    bool isShutdown();

    //Request a graceful shutdown
    void shutdown();
    
    void run();
};

#endif
