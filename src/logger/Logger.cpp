#include "Logger.h"

/**
 * Constructor return instance that will be _log all type of
 * messages into one file.
 *
 * @param path Path to ._log file.
 */
Logger::Logger(const std::string &path) {
    this->successPath = path;
    this->warningPath = path;
    this->errorPath = path;

    this->_createFiles();
}

/**
 * Constructor return instance that will be _log all type of
 * messages into separated files.
 *
 * @param successPath Path to ._log file for success messages.
 * @param warningPath Path to ._log file for warning messages.
 * @param errorPath Path to ._log file for error messages.
 */
Logger::Logger(
        const std::string &successPath,
        const std::string &warningPath,
        const std::string &errorPath
) {
    this->successPath = successPath;
    this->warningPath = warningPath;
    this->errorPath = errorPath;

    this->_createFiles();
}

/**
 * Create files if not exists using instance
 * path fields.
 */
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

/**
 * Log message to file at given path.
 *
 * @param message Message to log.
 * @param path Path to file.
 */
void Logger::_log(
        const std::string &message,
        const std::string &path
) {
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

/**
 * Log success message.
 *
 * @param message Success message.
 */
void Logger::success(const std::string &message) {
    auto formatMessage = "[ SUCCESS ]: " + message;

    this->_log(formatMessage, this->successPath);
}

/**
 * Log warning message.
 *
 * @param message Warning message.
 */
void Logger::warning(const std::string &message) {
    auto formatMessage = "[ Warning ]: " + message;

    this->_log(formatMessage, this->warningPath);
}

/**
 * Log error message.
 *
 * @param message Error message.
 */
void Logger::error(const std::string &message) {
    auto formatMessage = "[ Error ]: " + message;

    this->_log(formatMessage, this->errorPath);
}
