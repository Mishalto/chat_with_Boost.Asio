# 🚀 Multithreaded Asynchronous Chat (Boost.Asio)

A high-performance TCP/IP chat server with Boost.Asio. Supports multiple concurrent clients with real-time message broadcasting.

## Features

- **Real-time messaging**  Clients receive messages instantly
- **Multithreaded server**  Handles 4+ clients simultaneously
- **IP-based uniqueness**  Only one client per IP is allowed
- **Broadcast system**  All clients receive all messages

### 🔧 Prerequisites

- [CMake 3.15+](https://cmake.org/)
- [Git](https://git-scm.com/)

## Build

1. **Download Boost 1.87+ and place it into the project root and rename the folder from Boost_x_xx to boost:**
    - /boost
    - /Client
    - /Server
2. **Go to `/Server` and build the project:**
3. **Repeat the same for /Client**

## Tests
1. Start ./Server
2. After Server start ./Client
3. Try to send a message

