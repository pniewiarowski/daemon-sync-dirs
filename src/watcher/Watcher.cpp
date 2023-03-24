#include "Watcher.h"

/**
 * Constructor create instance which will be watch for
 * given path, in default delay time.
 *
 * @param path: Path to watch.
 */
watcher::Watcher::Watcher(const std::string &path)
        : path(path) {
    this->delay = this->DEFAULT_DELAY;
}

/**
 * Constructor create instance which will be watch for
 * given path, in given delay time.
 *
 * @param path: Path to watch.
 * @param delay Delay after single check.
 */
watcher::Watcher::Watcher(const std::string &path, const std::chrono::duration<int, std::milli> &delay)
        : path(path), delay(delay) {
    for (auto &file: std::filesystem::recursive_directory_iterator(path)) {
        this->_paths[file.path().string()] = std::filesystem::last_write_time(file);
    }
}

/**
 * Start watching using current watcher instances. Watch for changes in
 * class context directory.
 *
 * @param action: Callback function to subscribe file status changes.
 */
void watcher::Watcher::start(const std::function<void(std::string, Status)> &action) {
    while (this->_running) {
        /**
         * Delay current thread.
         */
        std::this_thread::sleep_for(this->delay);

        /**
         * Watch for delete event.
         */
        auto iterator = this->_paths.begin();
        while (iterator != this->_paths.end()) {
            if (!std::filesystem::exists(iterator->first)) {
                action(iterator->first, Status::DELETED);
                iterator = this->_paths.erase(iterator);
                continue;
            }

            iterator++;
        }

        /**
         * Watch for created and modified event.
         */
        for (auto &file: std::filesystem::recursive_directory_iterator(path)) {
            auto current = std::filesystem::last_write_time(file);

            if (this->_paths.contains(file.path().string())) {
                this->_paths[file.path().string()] = current;
                action(file.path().string(), Status::CREATED);

                continue;
            }

            if (this->_paths[file.path().string()] != current) {
                this->_paths[file.path().string()] = current;
                action(file.path().string(), Status::MODIFIED);

                continue;
            }
        }
    }
}
