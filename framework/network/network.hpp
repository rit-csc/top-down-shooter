#ifndef NETWORK_H
#define NETWORK_H

#include "TCPServer.hpp"
#include "TCPClient.hpp"

#define SERVER_LISTEN_PORT 44453

extern Service *server;
extern sf::Thread *serverThread;

extern Service *client;
extern sf::Thread *clientThread;

void setupServer();
void setupClient();

void teardownServer();
void teardownClient();

#endif
