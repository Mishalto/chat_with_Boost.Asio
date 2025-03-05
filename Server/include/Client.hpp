#pragma once

#include <iostream>
#include <boost/asio.hpp>

class Client {
    using tcp = boost::asio::ip::tcp;

public:
    Client();
};