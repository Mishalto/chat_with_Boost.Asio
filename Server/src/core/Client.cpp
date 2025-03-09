#include <Client.hpp>

Client::Client() {}

Client::Client(std::shared_ptr<tcp::socket>& socket) : socket_(socket) {
    std::cout << "[Client]" << socket_->remote_endpoint().address().to_string() << " initialized\n";
    std::thread read_thread(&Client::do_read, this);
    read_thread.detach();
}

void Client::do_read() {
    bool is_connected = true;
    std::cout << "[ClientManager]Listen started.\n";
    while (is_connected)
    {
        boost::system::error_code err;
        size_t length = socket_->read_some(boost::asio::buffer(data_), err);
        if (!err) {
            message_ = std::string(data_.data(), length);
            has_message_ = true;
        } else {
            std::cerr << "[Client]" << err.message() << '\n';
        }
    }

}

bool Client::has_message() const {
    return has_message_;
}

const std::string& Client::get_message() {
    return message_;
}

void Client::reset_flag() {
    has_message_ = false;
}