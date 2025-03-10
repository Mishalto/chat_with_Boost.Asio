#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <cstdlib>
#include <boost/asio.hpp>
#include <ClientManager.hpp>

class Server {
using tcp = boost::asio::ip::tcp;

private:
    boost::asio::io_context io_context_;
    tcp::acceptor acceptor_;
    bool is_running_;
    ClientManager client_manager_;
    std::thread commands_thread;

    void do_accept();
    void check_commands();
public:
    Server();
    ~Server();
    void start_server();
};