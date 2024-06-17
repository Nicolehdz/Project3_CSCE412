#include "WebServer.h"
#include <iostream>

void WebServer::addRequest(const Request& req) {
    requestQueue.push(req);
    std::cout << "Server " << server_id << " received request from " << req.ip_in << " to " << req.ip_out << std::endl;
}

void WebServer::processRequest() {
    if (!requestQueue.empty()) {
        Request& req = requestQueue.front();
        if (current_time == 0) {
            current_time = req.time;
            std::cout << "Server " << server_id << " processing request from " << req.ip_in 
                      << " to " << req.ip_out << " taking " << req.time << " cycles." << std::endl;
        }
        current_time--;
        if (current_time <= 0) {
            std::cout << "Server " << server_id << " finished request from " << req.ip_in << std::endl;
            requestQueue.pop();
        }
    }
}

bool WebServer::isIdle() const {
    return requestQueue.empty();
}

int WebServer::getId() const {
    return server_id;
}
