#pragma once

#include <iostream>
#include <unordered_map>
#include <thread>
#include <boost/asio.hpp>
#include <Client.hpp>

class ClientManager {
    using tcp = boost::asio::ip::tcp;

private:
    std::unordered_map<std::string, Client> clients_;

    void check_message();
public:
    ClientManager();

    void add_client(const std::string& ip_addr, std::shared_ptr<tcp::socket> socket);
    size_t active_client() const;
};