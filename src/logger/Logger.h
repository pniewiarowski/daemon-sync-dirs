#ifndef DAEMON_SYNC_DIRS_LOGGER_H
#define DAEMON_SYNC_DIRS_LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

class Logger {
private:
    const std::string DEFAULT_PATH = "messages.log";
    const std::string SUCCESS_TAG = "[ SUCCESS ]";
    const std::string WARNING_TAG = "[ WARNING ]";
    const std::string ERROR_TAG = "[ ERROR ]";

    std::string successPath;
    std::string warningPath;
    std::string errorPath;

    static void _log(const std::string &message, const std::string &path);
    static void _createFile(const std::string &path, const std::_Ios_Openmode &mode);

    void _createFiles();

public:
    explicit Logger();
    explicit Logger(const std::string &path);
    explicit Logger(const std::string &successPath, const std::string &warningPath, const std::string &errorPath);

    void success(const std::string &message);
    void warning(const std::string &message);
    void error(const std::string &message);
};

#endif //DAEMON_SYNC_DIRS_LOGGER_H
