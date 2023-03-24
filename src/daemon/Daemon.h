#ifndef DAEMON_SYNC_DIRS_DAEMON_H
#define DAEMON_SYNC_DIRS_DAEMON_H

#include "../logger/Logger.h"

namespace daemon {
    class Daemon {
    private:
        logger::Logger *logger;
    public:
        explicit Daemon();
        explicit Daemon(logger::Logger *logger);

        void execute();
    };
}

#endif //DAEMON_SYNC_DIRS_DAEMON_H
