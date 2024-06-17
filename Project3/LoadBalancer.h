#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <queue>
#include "Request.h"
#include "WebServer.h"

class LoadBalancer {
private:
    std::queue<Request> requestQueue;
    std::vector<WebServer> webServers;
    int clock_cycles;

public:
    LoadBalancer(int num_servers);
    void addRequest(const Request& req);
    void distributeRequests();
    void run(int cycles);
};

#endif // LOADBALANCER_H
