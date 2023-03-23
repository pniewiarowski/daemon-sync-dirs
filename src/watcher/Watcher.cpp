#include "Watcher.h"

/**
 * Constructor create instance which will be watch for
 * given path, in default delay time.
 *
 * @param path: Path to watch.
 */
Watcher::Watcher(std::string path)
        : path(std::move(path)) {
    this->delay = this->DEFAULT_DELAY;
}

/**
 * Constructor create instance which will be watch for
 * given path, in given delay time.
 *
 * @param path: Path to watch.
 * @param delay Delay after single check.
 */
Watcher::Watcher(std::string path, const std::chrono::duration<int, std::milli> &delay)
        : path(std::move(path)), delay(delay) {}

/**
 * Start watching using current watcher instances.
 *
 * @param action Callback function to subscribe file status changes.
 */
void Watcher::start(const std::function<void(std::string, Status)> &action) {
    /** NOT IMPLEMENTED YET */
}
