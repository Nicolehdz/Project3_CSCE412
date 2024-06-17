#ifndef REQUEST_H
#define REQUEST_H

#include <string>

struct Request {
    std::string ip_in;
    std::string ip_out;
    int time;

    Request(const std::string& in, const std::string& out, int t)
        : ip_in(in), ip_out(out), time(t) {}
};

#endif // REQUEST_H
