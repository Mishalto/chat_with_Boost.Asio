#include <Client.hpp>

Client::Client() {}

Client::~Client() {
    read_thread.join();
}

Client::Client(std::shared_ptr<tcp::socket> socket) : socket_(socket), read_thread(&Client::do_read, this) {
    client_addr_ = socket_->remote_endpoint().address().to_string();
    std::cout << "[Client]" << client_addr_ << " initialized\n";
    is_connected_ = true;
}

void Client::do_read() {
    while (is_connected_)
    {
        boost::system::error_code err;
        size_t length = socket_->read_some(boost::asio::buffer(data_), err);
        if (!err) {
            message_ = std::string(data_.data(), length);
            has_message_ = true;
        } else {
            if(err == boost::asio::error::eof) {
                std::cout << "[Client]" << socket_->remote_endpoint().address().to_string() << " disconected.\n";
                is_connected_ = false;
            } else {
                std::cerr << "[Client][" << socket_->remote_endpoint().address().to_string() << "]" << err.message() << '\n';
                is_connected_ = false;
            }
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

bool Client::is_connected() {
    return is_connected_;
}

const std::string& Client::get_addr() {
    return client_addr_;
}

std::shared_ptr<boost::asio::ip::tcp::socket> Client::get_socket() {
    return socket_;
}