#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <queue>
#include <set>

#include "Service.hpp"
#include "Session.hpp"

class TCPClient : public Service
{
private:
    bool isAlive;
    std::shared_ptr<Session> session;

    std::queue<sf::Packet*> incomingMessages;
    sf::Mutex queueMutex;
    
    sf::TcpSocket socket;
    volatile sf::Socket::Status status;
    
public:

    TCPClient();

    sf::Socket::Status connect(const sf::IpAddress remoteAddress, unsigned short remotePort, sf::Time timeout);
    void disconnect();

    virtual void tick();
    virtual void run();
    virtual void shutdown();
};

#endif
