cmake_minimum_required(VERSION 3.10)
project(contestdraw)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenSSL 1.1.0 REQUIRED)

set(CONTESTDRAW_SOURCES
		src/version.h
		src/main.cpp
		src/crypto/seed-hasher.cpp src/crypto/seed-hasher.h
		src/crypto/salt.cpp src/crypto/salt.h)

add_executable(contestdraw ${CONTESTDRAW_SOURCES})

target_link_libraries(contestdraw ssl crypto)
