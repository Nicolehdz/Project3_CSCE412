#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <queue>
#include "Request.h"

class WebServer {
private:
    std::queue<Request> requestQueue;
    int server_id;
    int current_time;

public:
    WebServer(int id) : server_id(id), current_time(0) {}
    void addRequest(const Request& req);
    void processRequest();
    bool isIdle() const;
    int getId() const;  // Add this line
};

#endif // WEBSERVER_H
