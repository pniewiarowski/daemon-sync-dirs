#include "Daemon.h"

/**
 * Daemon constructor return Daemon instance with
 * given `watcher::Watcher` instance.
 *
 * @param watcher: Instance of `watcher::Watcher` class.
 */
daemon::Daemon::Daemon(watcher::Watcher *watcher) :
        watcher(watcher), logger(new logger::Logger()) {}

/**
 * Daemon constructor return Daemon instance with
 * given `watcher::Watcher` instance and `logger::Logger`
 * instance.
 *
 * @param watcher: Instance of `watcher::Watcher` class.
 * @param logger: Instance of `logger::Logger` class.
 */
daemon::Daemon::Daemon(watcher::Watcher *watcher, logger::Logger *logger)
        : watcher(watcher), logger(logger) {}

/**
 * Execute current daemon instance.
 */
void daemon::Daemon::execute() {
    /** NOT IMPLEMENTED YET */
}
