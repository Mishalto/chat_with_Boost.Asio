#include <iostream>
#include <boost/asio.hpp>
#include <Server.hpp>

int main() {
    setlocale(LC_ALL, "");
    try {
        Server server;
        server.start_server();
    } catch (const std::exception& e) {
        std::cerr << "[Main]" << e.what() << '\n';
    }

    return 0;
}