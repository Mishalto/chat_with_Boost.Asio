#pragma once

#include <iostream>
#include <memory>
#include <boost/asio.hpp>

class Server {
using tcp = boost::asio::ip::tcp;

private:
    boost::asio::io_context io_context_;
    tcp::acceptor acceptor_;
    bool is_running_;

public:
    Server();

    void start_server();
    void do_accept();
};