#include <ClientManager.hpp>

ClientManager::ClientManager() {
    check_message();
}

void ClientManager::check_message() {
    //todo
}

void ClientManager::add_client(const std::string& ip_addr, std::shared_ptr<tcp::socket> socket) {
    std::cout << "[ClientManager]" << ip_addr << " added.\n";
    clients_[ip_addr] = Client{socket};
}

size_t ClientManager::active_client() const {
    return clients_.size();
}