cmake_minimum_required(VERSION 3.24)
project(daemon_sync_dirs)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        daemon_sync_dirs
        ./src/main.cpp
        src/logger/Logger.cpp
        src/logger/Logger.h
        src/flag/Flag.cpp
        src/flag/Flag.h
        src/flag/Parser.cpp
        src/flag/Parser.h
        src/flag/Manager.cpp
        src/flag/Manager.h
        src/watcher/Status.h
        src/watcher/Watcher.cpp
        src/watcher/Watcher.h
        src/syncdaemon/Daemon.cpp
        src/syncdaemon/Daemon.h
)
