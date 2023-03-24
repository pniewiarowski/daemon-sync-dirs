#ifndef DAEMON_SYNC_DIRS_DAEMON_H
#define DAEMON_SYNC_DIRS_DAEMON_H

#include "../logger/Logger.h"
#include "../watcher/Watcher.h"

namespace daemon {
    class Daemon {
    private:
        logger::Logger *logger{};
        watcher::Watcher *watcher{};
    public:
        explicit Daemon(watcher::Watcher *watcher);
        explicit Daemon(watcher::Watcher *watcher, logger::Logger *logger);

        void execute();
    };
}

#endif //DAEMON_SYNC_DIRS_DAEMON_H
