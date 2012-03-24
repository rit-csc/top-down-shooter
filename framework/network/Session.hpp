#ifndef SESSION_H
#define SESSION_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <memory>

class Session
{
private:
    sf::TcpSocket* socket;
    sf::Mutex socketMutex;
public:

    Session(sf::TcpSocket* s)
    {
        socket = s;
    }
    
    virtual ~Session() 
    {
        delete socket;
    }

    void send(sf::Packet& packet);
    sf::Socket::Status receive(sf::Packet* p);

    virtual void onReceive(sf::Packet* packet);

};

#endif