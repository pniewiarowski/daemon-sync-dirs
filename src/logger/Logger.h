#ifndef DAEMON_SYNC_DIRS_LOGGER_H
#define DAEMON_SYNC_DIRS_LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

class Logger {
private:
    std::string successPath;
    std::string warningPath;
    std::string errorPath;

    void _createFiles();

    static void _log(const std::string &message, const std::string &path);

public:
    explicit Logger(const std::string &path);

    explicit Logger(const std::string &successPath,
                    const std::string &warningPath,
                    const std::string &errorPath);

    void success(const std::string &message);

    void warning(const std::string &message);

    void error(const std::string &message);
};

#endif //DAEMON_SYNC_DIRS_LOGGER_H
