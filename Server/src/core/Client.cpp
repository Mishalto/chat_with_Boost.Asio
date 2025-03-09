#include <Client.hpp>

Client::Client() {}

Client::Client(std::shared_ptr<tcp::socket> socket) : socket_(socket) {
    std::cout << "[Client]" << socket->remote_endpoint().address().to_string() << " initialized\n";
}

// void Client::do_read() {
//     bool is_connected = true;
//     for(is_connected) {

//     }
// }