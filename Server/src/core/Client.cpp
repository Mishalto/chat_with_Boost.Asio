#include <Client.hpp>

Client::Client(std::shared_ptr<tcp::socket> socket) : socket_(std::move(socket)) {}