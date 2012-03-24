#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <queue>
#include <list>
#include <set>

#include "Service.hpp"
#include "Session.hpp"

class TCPServer : public Service
{
private:
    volatile bool isAlive;
    
    std::list<std::shared_ptr<Session>> sessions;
    
    std::queue<std::pair<std::shared_ptr<Session>, sf::Packet*>> incomingMessages;
    sf::Mutex queueMutex;
    
    sf::TcpListener listener;
    
public:
    TCPServer(unsigned short listeningPort);
    
    virtual void tick();
    
    bool isShutdown();

    //Request a graceful shutdown
    virtual void shutdown();
    
    void run();
};

#endif
