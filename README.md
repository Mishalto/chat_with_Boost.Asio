# Chat (Boost Asio)
This is a multithreaded asynchronous chat where multiple clients (I tested with up to 4 clients) can simultaneously send requests to the server and receive responses from other clients.  
The server broadcasts received data to all clients.  

## Design
Boost Asio is used with TCP/IP protocols.  
Each client is unique, and only one client can connect from a single IP address.  
All clients are stored in an unordered map (UNo map) with access via their IP addresses.  

## Build
1. Make sure you have CMake, Git, and the release version of CMake installed.  
2. Open the project folder.  
3. CMake will automatically pull all required dependencies, and the project will be ready (this process may take a very long time).  
