cmake_minimum_required(VERSION 3.15)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
  boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.87.0
)
FetchContent_MakeAvailable(boost)

find_package(Boost REQUIRED COMPONENTS asio)

add_executable(Server main.cpp)

target_include_directories(Server PRIVATE ${Boost_INCLUDE_DIRS})
target_include_directories(Server PRIVATE include)

target_link_libraries(Server PRIVATE Boost::asio)

target_compile_options(Server PRIVATE -Wall -Wextra -Werror)
