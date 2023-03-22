#ifndef DAEMON_SYNC_DIRS_LOGGER_H
#define DAEMON_SYNC_DIRS_LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

/**
 * Tool for _log are type of message from daemon.
 */
class Logger {
private:
    /**
     * Path to .log file for _log success messages from daemon.
     */
    std::string successPath;

    /**
     * Path to .log file for _log warning messages from daemon.
     */
    std::string warningPath;

    /**
     * Path to .log file for _log error message from daemon.
     */
    std::string errorPath;

    /**
     * Create files if not exists using instance
     * path fields.
     */
    void _createFiles();


    /**
     * Log message to file at given path.
     *
     * @param message Message to log.
     * @param path Path to file.
     */
    static void _log(
            const std::string &message,
            const std::string &path
    );

public:
    /**
     * Constructor return instance that will be _log all type of
     * messages into one file.
     *
     * @param path Path to ._log file.
     */
    explicit Logger(const std::string &path);

    /**
     * Constructor return instance that will be _log all type of
     * messages into separated files.
     *
     * @param successPath Path to ._log file for success messages.
     * @param warningPath Path to ._log file for warning messages.
     * @param errorPath Path to ._log file for error messages.
     */
    explicit Logger(
            const std::string &successPath,
            const std::string &warningPath,
            const std::string &errorPath
    );

    /**
     * Log success message.
     *
     * @param message Success message.
     */
    void success(const std::string &message);

    /**
     * Log warning message.
     *
     * @param message Warning message.
     */
    void warning(const std::string &message);

    /**
     * Log error message.
     *
     * @param message Error message.
     */
    void error(const std::string &message);
};

#endif //DAEMON_SYNC_DIRS_LOGGER_H
