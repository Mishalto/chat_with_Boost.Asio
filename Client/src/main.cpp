#include <iostream>
#include <boost/asio.hpp>

int main() {
    using boost::asio::ip::tcp;
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
    std::cout << "Mess: ";
    std::string mess;
    std::cin >> mess;
    boost::asio::write(socket, boost::asio::buffer(mess));

    return 0;
}

