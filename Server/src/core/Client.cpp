#include <Client.hpp>

Client::Client() {}

Client::Client(std::shared_ptr<tcp::socket> socket) : socket_(socket) {
    std::cout << "[Client]" << socket_->remote_endpoint().address().to_string() << " initialized\n";
    std::thread read_thread(&Client::do_read, this);
    read_thread.detach();
    std::cout << "[Client]Desc -> " << socket_->native_handle() << '\n';
}

void Client::do_read() {
    bool is_connected = true;
    std::cout << "[ClientManager]Listen started.\n";
    while (is_connected)
    {
        std::cout << "[Socket_opened]" << socket_->is_open() << '\n';
        std::cout << "[Client]Desc -> " << socket_->native_handle() << '\n';
        boost::system::error_code err;
        size_t length = socket_->read_some(boost::asio::buffer(data_), err);
        if (!err) {
            message_ = std::string(data_.data(), length);
            has_message_ = true;
        } else {
            std::cerr << "[Client]" << err.message() << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(3));
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

void Client::check_valid() {
    std::cout << socket_->native_handle() << '\n';
}