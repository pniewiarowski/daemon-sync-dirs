#ifndef DAEMON_SYNC_DIRS_DAEMON_H
#define DAEMON_SYNC_DIRS_DAEMON_H

#include "../logger/Logger.h"

class Daemon {
private:
    Logger *logger;
public:
    explicit Daemon();
    explicit Daemon(Logger *logger);

    void execute();
};

#endif //DAEMON_SYNC_DIRS_DAEMON_H
