#pragma once

#include <iostream>
#include <unordered_map>
#include <boost/asio.hpp>

class ClientManager {
    using tcp = boost::asio::ip::tcp;

public:
    ClientManager();
};