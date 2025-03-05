cmake_minimum_required(VERSION 3.15)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BOOST_ROOT "D:/Libs/boost_1_87_0")

add_executable(Server src/main.cpp src/core/Server.cpp src/core/Client.cpp src/core/ClientManager.cpp)

add_definitions(-D_WIN32_WINNT=0x0A00) # win 10

target_include_directories(Server PRIVATE ${BOOST_ROOT})
target_include_directories(Server PRIVATE include)
target_include_directories(Server PRIVATE %{CMAKE_SOURCE_DIR}/include)

target_compile_options(Server PRIVATE -Wall -Wextra -Werror)
