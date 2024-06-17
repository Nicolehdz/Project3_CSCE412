#include "WebServer.h"
#include <iostream>

void WebServer::addRequest(const Request& req) {
    requestQueue.push(req);
}

void WebServer::processRequest() {
    if (!requestQueue.empty()) {
        Request req = requestQueue.front();
        requestQueue.pop();
        std::cout << "Server " << server_id << " processing request from " << req.ip_in 
                  << " to " << req.ip_out << " taking " << req.time << " cycles." << std::endl;
    }
}

bool WebServer::isIdle() const {
    return requestQueue.empty();
}
