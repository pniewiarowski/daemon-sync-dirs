#ifndef DAEMON_SYNC_DIRS_SYNCDAEMON_H
#define DAEMON_SYNC_DIRS_SYNCDAEMON_H

#include <unistd.h>
#include <sys/stat.h>

#include "../logger/Logger.h"
#include "../watcher/Watcher.h"

namespace syncdaemon {
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
