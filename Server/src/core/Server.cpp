#include <Server.hpp>

Server::Server() : acceptor_(io_context_, tcp::endpoint(tcp::v4(), 12345)), is_running_(false), commands_thread(&Server::check_commands, this) {}

Server::~Server() {
    commands_thread.join();
    std::cout << "The server has shutdown.\n";
}

void Server::start_server() {
    try {
        std::cout << "[Server]Server started.\n";
        is_running_ = true;
        while (is_running_) {
            do_accept();
        }
    } catch (const std::exception &e) {
        std::cerr << "[Server]" << "[Critical]" << e.what() << '\n';
    }
};

void Server::do_accept() {
    std::cout << "[Server]Active clients -> " << client_manager_.active_client() << '\n';
    std::cout << "[Server]Waiting client...\n";

    auto socket = std::make_shared<tcp::socket>(io_context_);
    boost::system::error_code err;

    acceptor_.accept(*socket, err);
    if (!err) {
        std::cout << "[Server]Client connected.\n";
        std::string addr = socket->remote_endpoint().address().to_string();
        client_manager_.add_client(addr, socket);
    } else {
        std::cerr << "[Server]" << err.message() << '\n';
    }
}

void Server::check_commands() {
    std::this_thread::sleep_for(std::chrono::milliseconds(300));    // Baaaaad!!!!
    std::cout << "You can use /stop to stop the server\n";
    while(true) {
        std::string command;
        std::cin >> command;
        if (command == "/stop") {
            is_running_ = false;
            std::exit(0);
            break;
        } else {
            std::cout << "Invalid input\n";
        }
    }
}