#pragma once

#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include <ClientManager.hpp>

class Server {
using tcp = boost::asio::ip::tcp;

private:
    boost::asio::io_context io_context_;
    tcp::acceptor acceptor_;
    bool is_running_;
    ClientManager client_manager_;

    void do_accept();
public:
    Server();
    void start_server();
};