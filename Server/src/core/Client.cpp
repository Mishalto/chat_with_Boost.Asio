#include <Client.hpp>

Client::Client() {}

Client::Client(std::shared_ptr<tcp::socket> socket) : socket_(socket) {}