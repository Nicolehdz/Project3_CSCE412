#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <queue>
#include "Request.h"

class WebServer {
private:
    std::queue<Request> requestQueue;
    int server_id;

public:
    WebServer(int id) : server_id(id) {}
    void addRequest(const Request& req);
    void processRequest();
    bool isIdle() const;
};

#endif // WEBSERVER_H
