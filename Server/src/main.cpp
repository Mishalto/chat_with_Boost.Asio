#include <iostream>
#include <boost/asio.hpp>
#include <Server.hpp>

int main() {
    Server server;
    server.start_server();

    return 0;
}