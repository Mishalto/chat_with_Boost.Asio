#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <array>
#include <boost/asio.hpp>

class Client {
    using tcp = boost::asio::ip::tcp;

private:
    std::shared_ptr<tcp::socket> socket_;
    std::array<char, 1024> data_;
    bool has_message_;
    std::string message_;

public:
    Client();
    Client(std::shared_ptr<tcp::socket> socket);

    void do_read();
    bool has_message() const;
    const std::string& get_message();
    void reset_flag();
};