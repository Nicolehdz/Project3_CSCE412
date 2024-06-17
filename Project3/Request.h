#ifndef REQUEST_H
#define REQUEST_H

#include <string> // Add the necessary include directive for the <string> header file

struct Request {
    std::string ip_in;
    std::string ip_out;
    int time; // Processing time in clock cycles

    Request(const std::string& in, const std::string& out, int t)
        : ip_in(in), ip_out(out), time(t) {}
};

#endif // REQUEST_H
