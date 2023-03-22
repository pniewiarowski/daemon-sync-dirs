#include "Logger.h"

Logger::Logger(const std::string &path) {
    this->successPath = path;
    this->warningPath = path;
    this->errorPath = path;

    this->_createFiles();
}

Logger::Logger(const std::string &successPath,
               const std::string &warningPath,
               const std::string &errorPath) {
    this->successPath = successPath;
    this->warningPath = warningPath;
    this->errorPath = errorPath;

    this->_createFiles();
}

void Logger::_createFiles() {
    auto paths = {
            this->successPath,
            this->warningPath,
            this->errorPath
    };

    auto mode =
            std::fstream::in |
            std::fstream::out |
            std::fstream::trunc;

    std::fstream filestream;
    for (const std::string &path: paths) {
        filestream.open(path, mode);
        filestream.close();
    }
}

void Logger::_log(const std::string &message, const std::string &path) {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    auto time = std::put_time(&tm, "%d-%m-%Y %H-%M-%S");

    std::fstream filestream;

    filestream.open(path, std::fstream::app);
    if (!filestream.is_open()) {
        return;
    }

    filestream << "[ " << time << " ] " << message << std::endl;
    filestream.close();
}

void Logger::success(const std::string &message) {
    auto formatMessage = "[ SUCCESS ]: " + message;

    this->_log(formatMessage, this->successPath);
}

void Logger::warning(const std::string &message) {
    auto formatMessage = "[ Warning ]: " + message;

    this->_log(formatMessage, this->warningPath);
}

void Logger::error(const std::string &message) {
    auto formatMessage = "[ Error ]: " + message;

    this->_log(formatMessage, this->errorPath);
}
