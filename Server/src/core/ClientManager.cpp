#include <ClientManager.hpp>

ClientManager::ClientManager() {
    check_message();
}

void ClientManager::check_message() {
    //todo
}

void ClientManager::add_client(const std::string& ip_addr, std::shared_ptr<tcp::socket> socket) {
    auto find_it = clients_.find(ip_addr);
    if (find_it == clients_.end()) {
        std::cout << "[ClientManager]" << ip_addr << " added.\n";
        clients_[ip_addr] = Client{socket};
    } else {
        std::cout << "[ClientManager]" << ip_addr << " already here.\n";
    }
}

size_t ClientManager::active_client() const {
    return clients_.size();
}