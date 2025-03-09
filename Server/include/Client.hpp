#pragma once

#include <iostream>
#include <memory>
#include <boost/asio.hpp>

class Client {
    using tcp = boost::asio::ip::tcp;

private:
    std::shared_ptr<tcp::socket> socket_;
    // std::string name_;
    // bool has_message_;
    // std::string message_;
public:
    Client();
    Client(std::shared_ptr<tcp::socket> socket);
};