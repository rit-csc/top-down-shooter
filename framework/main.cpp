#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "TCPServer.h"
#include "TCPClient.h"

TCPServer *server;
sf::Thread *serverThread;

TCPClient *client;
sf::Thread *clientThread;

void teardownServer() 
{
    if(server != nullptr)
    {
        server->shutdown();
        serverThread->wait();
        delete server;
        delete serverThread;
    }
}

void teardownClient()
{
    if(client != nullptr)
    {
        client->shutdown();
        clientThread->wait();
        delete client;
        delete clientThread;
    }
}

void setupServer()
{
    if(server != nullptr)
    {
        teardownServer();
    } 
    server = new TCPServer(44453);
    serverThread = new sf::Thread(&TCPServer::run, server);
    serverThread->launch();
}

void setupClient()
{
    if(client != nullptr)
    {
        teardownClient();
    }
    client = new TCPClient();
    clientThread = new sf::Thread(&TCPClient::run, client);
    clientThread->launch();
}

// 16 ms tick time
const long TICK = 16;

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        printf("Starting server...\n");
        setupServer();
    }
    else
    {
        printf("Starting client...\n");
        setupClient();
        client->connect("127.0.0.1", 44453, sf::seconds(30.0f));
    }

    //Setup Window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Window");
	app.setFramerateLimit(60);

    //Setup clock
	sf::Clock clock;
	sf::Time prevTime = clock.getElapsedTime();
	sf::Time now = clock.getElapsedTime();

    //Prep Elements
	sf::Color cornflowerBlue(100, 149, 237);
	sf::Text txtMessage("Hello World!", sf::Font::getDefaultFont(), 20);

    //Begin the game loop
	long accum = 0;
	while (app.isOpen())
	{
	    //Adjust the times and the accumulator
		now = clock.getElapsedTime();
		accum += (now - prevTime).asMilliseconds();
		prevTime = now;

        //Prevent sync issues by doing the game loop multiple times, if necessary.
		while (accum >= TICK)
		{
			accum -= TICK;

			sf::Event event;
			while (app.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					app.close();
				}

				if ((event.type == sf::Event::KeyPressed) &&
						(event.key.code == sf::Keyboard::Escape))
				{
					app.close();
				}
			}
		}

        //Clear and redraw the screen
		app.clear(cornflowerBlue);
		app.draw(txtMessage);
		app.display();
	}

    teardownServer();
    teardownClient();

	return EXIT_SUCCESS;
}
