cmake_minimum_required(VERSION 3.24)
project(daemon_sync_dirs)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        daemon_sync_dirs
        ./src/main.cpp
        src/logger/Logger.cpp src/logger/Logger.h)
