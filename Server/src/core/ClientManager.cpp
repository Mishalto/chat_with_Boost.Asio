#include <ClientManager.hpp>

ClientManager::ClientManager() : check_thread(&ClientManager::check_message, this) {
    check_message_started = true;
}

ClientManager::~ClientManager() {
    check_thread.join();
}

void ClientManager::check_message() {
    for (;;) {
        while (check_message_started) {
            for (auto& s : clients_) {
                if (s.second->has_message()) {
                    std::cout << s.second->get_message() << '\n';
                    std::lock_guard<std::mutex> lock(mtx_clients_);
                    echo(s.second->get_message(), s.second->get_socket()->remote_endpoint().address().to_string());
                    s.second->reset_flag();
                } else if (!s.second->is_connected()) {
                    std::string addr_client = s.second->get_addr();
                    clients_.erase(addr_client);
                    std::cout << "[ClientManager]Active clients -> " << active_client() << '\n';
                    if (clients_.empty()) {
                        check_message_started = false;
                        std::cout << "[ClientManager]Waiting client...\n";
                        break;
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void ClientManager::add_client(const std::string& ip_addr, std::shared_ptr<tcp::socket> socket) {
    auto find_it = clients_.find(ip_addr);
    if (find_it == clients_.end()) {
        std::lock_guard<std::mutex> lock(mtx_clients_);

        std::cout << "[ClientManager]" << ip_addr << " added.\n";
        auto client = std::make_shared<Client>(socket);
        clients_[ip_addr] = client;
        if (!check_message_started) {
            check_message_started = true;
        }
    } else {
        std::cout << "[ClientManager]" << ip_addr << " already here.\n";
    }
}

size_t ClientManager::active_client() {
    std::lock_guard<std::mutex> lock(mtx_clients_);
    return clients_.size();
}

void ClientManager::echo(std::string_view msg, std::string_view addr_sender) {
    if (!clients_.empty()) {
        for(auto& s : clients_) {
            if(s.second->get_addr() != addr_sender) {
                boost::asio::write(*(s.second->get_socket()), boost::asio::buffer(msg));
                std::cout << "[ClientManager]Echo\n";
            }
        }
    }
}