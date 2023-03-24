#ifndef DAEMON_SYNC_DIRS_WATCHER_H
#define DAEMON_SYNC_DIRS_WATCHER_H

#include <string>
#include <chrono>
#include <functional>
#include <utility>

namespace watcher {
    enum class Status {
        CREATED,
        MODIFIED,
        DELETED,
    };

    class Watcher {
    private:
        const std::chrono::duration<int, std::milli> DEFAULT_DELAY = std::chrono::milliseconds(5000);

        std::string path;
        std::chrono::duration<int, std::milli> delay{};
    public:
        explicit Watcher(std::string path);
        explicit Watcher(std::string path, const std::chrono::duration<int, std::milli> &delay);
        void start(const std::function<void(std::string, Status)> &action);
    };
}

#endif //DAEMON_SYNC_DIRS_WATCHER_H
