#include <ClientManager.hpp>

ClientManager::ClientManager() {
    check_message();
}

void ClientManager::add_client(const std::string& ip_addr, std::shared_ptr<tcp::socket> socket) {
    clients_[ip_addr] = Client{std::move(socket)};
}

void ClientManager::check_message() {

}