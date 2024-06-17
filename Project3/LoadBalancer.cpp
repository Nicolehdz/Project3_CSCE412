// #include "LoadBalancer.h"
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// LoadBalancer::LoadBalancer(int num_servers) {
//     for (int i = 0; i < num_servers; ++i) {
//         webServers.emplace_back(i + 1);
//     }
//     clock_cycles = 0;
//     std::srand(std::time(nullptr)); // Seed for random number generation
// }

// void LoadBalancer::addRequest(const Request& req) {
//     requestQueue.push(req);
// }

// void LoadBalancer::distributeRequests() {
//     while (!requestQueue.empty()) {
//         for (auto& server : webServers) {
//             if (server.isIdle() && !requestQueue.empty()) {
//                 server.addRequest(requestQueue.front());
//                 requestQueue.pop();
//             }
//         }
//     }
// }

// void LoadBalancer::run(int cycles) {
//     for (int i = 0; i < cycles; ++i) {
//         std::cout << "Clock cycle: " << i + 1 << std::endl;
//         distributeRequests();
//         for (auto& server : webServers) {
//             server.processRequest();
//         }
//         if (i % 100 == 0) { // Add new requests every 100 cycles as an example
//             addRequest(Request("192.168.0.1", "192.168.0.2", std::rand() % 20 + 1));
//         }
//     }
// }

#include "LoadBalancer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

LoadBalancer::LoadBalancer(int num_servers) {
    for (int i = 0; i < num_servers; ++i) {
        webServers.emplace_back(i + 1);
    }
    clock_cycles = 0;
    std::srand(std::time(nullptr)); // Seed for random number generation
}

void LoadBalancer::addRequest(const Request& req) {
    requestQueue.push(req);
    std::cout << "Added request from " << req.ip_in << " to " << req.ip_out << std::endl;
}

void LoadBalancer::distributeRequests() {
    while (!requestQueue.empty()) {
        for (auto& server : webServers) {
            if (server.isIdle() && !requestQueue.empty()) {
                server.addRequest(requestQueue.front());
                std::cout << "Distributed request from " << requestQueue.front().ip_in << " to server " << server.getId() << std::endl;
                requestQueue.pop();
            }
        }
    }
}

void LoadBalancer::run(int cycles) {
    for (int i = 0; i < cycles; ++i) {
        std::cout << "Clock cycle: " << i + 1 << std::endl;
        distributeRequests();
        for (auto& server : webServers) {
            server.processRequest();
        }
        if (i % 100 == 0) { // Add new requests every 100 cycles as an example
            addRequest(Request("192.168.0.1", "192.168.0.2", std::rand() % 20 + 1));
        }
    }
}