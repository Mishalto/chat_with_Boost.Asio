#include <iostream>
#include <array>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void receive_message(tcp::socket& socket) {
    for (;;) {
        std::array<char, 1024> data;
        size_t length = socket.read_some(boost::asio::buffer(data));
        std::cout << std::string(data.data(), length);
    }
}

void send_message(tcp::socket& socket) {
    for (;;) {
        std::string mess;
        std::cin >> mess;
        boost::asio::write(socket, boost::asio::buffer(mess));
    }
}

int main() {

    boost::asio::io_context io_context;
    tcp::socket socket(io_context);
    tcp::endpoint ep(boost::asio::ip::make_address_v4("92.101.12.97"), 12345);
    boost::system::error_code err;
    socket.connect(ep, err);
    if (!err) {
        std::cout << "Connected\n";
    } else {
        std::cerr << "Error!\n";
    }

    std::thread send_thread(&send_message, std::ref(socket));
    std::thread receive_thread(&receive_message, std::ref(socket));
    for (;;) {

    }
    send_thread.join();
    receive_thread.join();

    return 0;
}

