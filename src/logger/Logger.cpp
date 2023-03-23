#include "Logger.h"

#include <utility>

/**
 * Logger constructor, return instance that will be log all
 * types of messages to the default file declared as a
 * const variable.
 */
Logger::Logger() :
        Logger(this->DEFAULT_PATH) {}

/**
 * Logger constructor, returns instance that will be log all
 * types of messages to the same given file.
 *
 * @param path: Path to log all messages.
 */
Logger::Logger(const std::string &path) :
        Logger(path, path, path) {}

/**
 * Logger constructor, returns instance that will be log all
 * types of messages to the different files given as an arguments.
 *
 * @param successPath: Path to log success messages.
 * @param warningPath: Path to log warning messages.
 * @param errorPath: Path to log error messages.
 */
Logger::Logger(std::string successPath, std::string warningPath, std::string errorPath)
        : successPath(std::move(successPath)),
          warningPath(std::move(warningPath)),
          errorPath(std::move(errorPath)) { this->_createFiles(); }

/**
 * Save given message in to file with given path.
 *
 * @param message: Message to save.
 * @param path: Path to file.
 */
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

/**
 * Static method create file with given path and mode.
 *
 * @param path: Path for new file.
 * @param mode: Mode for filestream object instance.
 */
void Logger::_createFile(const std::string &path, const std::_Ios_Openmode &mode) {
    std::fstream filestream;

    filestream.open(path, mode);
    filestream.close();
}

/**
 * Create files, ih they does not exists, using current
 * instance path fields.
 */
void Logger::_createFiles() {
    auto paths = {this->successPath, this->warningPath, this->errorPath};
    auto mode = std::fstream::in | std::fstream::out | std::fstream::trunc;

    for (auto &path: paths) {
        this->_createFile(path, mode);
    }
}

/**
 * Save given message, as a success type, into correct log file.
 *
 * @param message: Success message to save.
 */
void Logger::success(const std::string &message) {
    auto formatMessage = this->SUCCESS_TAG + " : " + message;

    this->_log(formatMessage, this->successPath);
}


/**
 * Save given message, as a warning type, into correct log file.
 *
 * @param message: Warning message to save.
 */
void Logger::warning(const std::string &message) {
    auto formatMessage = this->WARNING_TAG + " : " + message;

    this->_log(formatMessage, this->warningPath);
}


/**
 * Save given message, as an error type, into correct log file.
 *
 * @param message: Error message to save.
 */
void Logger::error(const std::string &message) {
    auto formatMessage = this->ERROR_TAG + " : " + message;

    this->_log(formatMessage, this->errorPath);
}
