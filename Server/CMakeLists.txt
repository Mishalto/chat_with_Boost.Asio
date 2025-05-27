cmake_minimum_required(VERSION 3.15)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32)
    add_definitions(-D_WIN32_WINNT=0x0A00)
endif()

set(BOOST_ROOT "../boost")  # или "../boost_1_87_0", если папка так называется
set(BOOST_INCLUDE_DIR "${BOOST_ROOT}")

add_executable(Server
  src/main.cpp
  src/core/Client.cpp
  src/core/ClientManager.cpp
  src/core/Server.cpp)

target_include_directories(Server PRIVATE
  ${BOOST_INCLUDE_DIR}
  include)

target_compile_options(Server PRIVATE -Wall -Wextra -Werror)