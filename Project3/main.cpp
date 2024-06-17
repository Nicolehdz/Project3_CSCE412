#include "LoadBalancer.h"
#include <iostream>

int main() {
    int num_servers;
    int run_time;

    std::cout << "Enter the number of web servers: ";
    std::cin >> num_servers;
    std::cout << "Enter the time to run the load balancer (in clock cycles): ";
    std::cin >> run_time;

    LoadBalancer lb(num_servers);

    // Initial requests
    for (int i = 0; i < num_servers * 10; ++i) {
        lb.addRequest(Request("192.168.1." + std::to_string(i), "10.0.0." + std::to_string(i), (i % 10) + 1));
    }

    lb.run(run_time);

    return 0;
}
