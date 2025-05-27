cmake_minimum_required(VERSION 3.15)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_PROGRESS TRUE
  GIT_TAG boost-1.87.0
)
FetchContent_MakeAvailable(Boost)

add_executable(Server
  src/main.cpp
  src/core/Client.cpp
  src/core/ClientManager.cpp
  src/core/Server.cpp)

target_include_directories(Server PRIVATE ${Boost_INCLUDE_DIRS})
target_include_directories(Server PRIVATE include)

target_link_libraries(Server PRIVATE Boost::asio)

target_compile_options(Server PRIVATE -Wall -Wextra -Werror)