#ifndef DAEMON_SYNC_DIRS_STATUS_H
#define DAEMON_SYNC_DIRS_STATUS_H

namespace watcher {
    enum class Status {
        CREATED,
        MODIFIED,
        DELETED,
    };
}


#endif //DAEMON_SYNC_DIRS_STATUS_H
