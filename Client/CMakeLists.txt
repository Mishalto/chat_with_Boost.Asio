cmake_minimum_required(VERSION 3.15)
project(Client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32)
    add_definitions(-D_WIN32_WINNT=0x0A00)
endif()

set(BOOST_ROOT "../boost")
set(BOOST_INCLUDE_DIR "${BOOST_ROOT}")

add_executable(Client
  src/main.cpp)

target_include_directories(Client PRIVATE
  ${BOOST_INCLUDE_DIR}
  include)

target_compile_options(Client PRIVATE -Wall -Wextra -Werror)