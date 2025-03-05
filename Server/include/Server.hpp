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

Server::Server() : acceptor_(io_context_, tcp::endpoint(tcp::v4(), 12345)), is_running_(false) {}

void Server::start_server() {
    std::cout << "[Server]Server started.\n";
    is_running_ = true;
    while(is_running_) {
        do_accept();
    }
};

void Server::do_accept() {
    std::cout << "[Server]Waiting client...\n";

    auto socket = std::make_shared<tcp::socket>(io_context_);
    boost::system::error_code err;

    acceptor_.accept(*socket, err);
    if (!err) {
        std::cout << "[Server]Client connected.\n";
    } else {
        std::cerr << err.message() << '\n';
    }
}