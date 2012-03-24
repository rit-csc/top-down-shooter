#include "network.hpp"

Service *server = new Service();
sf::Thread *serverThread = nullptr;

Service *client = new Service();
sf::Thread *clientThread = nullptr;

void teardownServer() 
{
    if(server != nullptr)
    {
        server->shutdown();
        delete server;
    }
    
    if(serverThread != nullptr)
    {
        serverThread->wait();
        delete serverThread;
    }
}

void teardownClient()
{
    if(client != nullptr)
    {
        client->shutdown();
        delete client;
    }
    
    if(clientThread != nullptr)
    {
        clientThread->wait();
        delete clientThread;
    }
}

void setupServer()
{
    if(server != nullptr)
    {
        teardownServer();
    } 
    TCPServer* tempServer = new TCPServer(SERVER_LISTEN_PORT);
    server = tempServer;
    serverThread = new sf::Thread(&TCPServer::run, tempServer);
}

void setupClient()
{
    if(client != nullptr)
    {
        teardownClient();
    }
    TCPClient* tempClient = new TCPClient();
    client = tempClient;
    clientThread = new sf::Thread(&TCPClient::run, tempClient);
}
