#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

class Service
{
public:
    virtual void tick() {}
    virtual void run() {}
    virtual void shutdown() {}
};

#endif
