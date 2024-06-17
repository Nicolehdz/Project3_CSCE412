#include "LoadBalancer.h"
#include <iostream>

LoadBalancer::LoadBalancer(int num_servers) : clock_cycles(0) {
    for (int i = 0; i < num_servers; ++i) {
        webServers.emplace_back(i + 1);
    }
}

void LoadBalancer::addRequest(const Request& req) {
    std::cout << "Adding new request: " << req.ip_in << " time to process " << req.time << " cycles" << std::endl;
    requestQueue.push(req);
}

void LoadBalancer::distributeRequests() {
    for (auto& server : webServers) {
        if (server.isIdle() && !requestQueue.empty()) {
            Request req = requestQueue.front();
            requestQueue.pop();
            server.addRequest(req);
            std::cout << "Distributing request from " << req.ip_in << " to server " << server.getId() << std::endl;
        }
        server.processRequest();
    }
}

void LoadBalancer::run(int cycles) {
    for (int t = 0; t < cycles; ++t) {
        std::cout << "Clock cycle: " << t + 1 << std::endl;
        distributeRequests();
        // Simulate adding new requests at random times
        if (t % 5 == 0) {
            addRequest(Request("192.168.0." + std::to_string(t % 256), "10.0.0." + std::to_string(t % 256), (t % 10) + 1));
        }
    }
}
