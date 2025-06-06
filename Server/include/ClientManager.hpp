#pragma once

#include <iostream>
#include <unordered_map>
#include <thread>
#include <memory>
#include <chrono>
#include <boost/asio.hpp>
#include <Client.hpp>

class ClientManager {
    using tcp = boost::asio::ip::tcp;

private:
    std::unordered_map<std::string, std::shared_ptr<Client>> clients_;
    std::thread check_thread;
    std::mutex mtx_clients_;

    void check_message();
    bool check_message_started;
public:
    ClientManager();
    ~ClientManager();

    void add_client(const std::string& ip_addr, std::shared_ptr<tcp::socket> socket);
    size_t active_client();
    void echo(std::string_view msg, std::string_view addr_sender);
};