#include "Daemon.h"

/**
 * Daemon constructor return Daemon instance with
 * given `watcher::Watcher` instance.
 *
 * @param watcher: Instance of `watcher::Watcher` class.
 */
syncdaemon::Daemon::Daemon(watcher::Watcher *watcher) :
        watcher(watcher), logger(new logger::Logger()) {}

/**
 * Daemon constructor return Daemon instance with
 * given `watcher::Watcher` instance and `logger::Logger`
 * instance.
 *
 * @param watcher: Instance of `watcher::Watcher` class.
 * @param logger: Instance of `logger::Logger` class.
 */
syncdaemon::Daemon::Daemon(watcher::Watcher *watcher, logger::Logger *logger)
        : watcher(watcher), logger(logger) {}

/**
 * Execute current daemon instance.
 */
void syncdaemon::Daemon::execute() {
    auto processID = fork();

    if (processID > 0) {
        exit(EXIT_SUCCESS);
    }

    if (processID < 0) {
        exit(EXIT_FAILURE);
    }

    auto sessionID = setsid();

    if (sessionID < 0) {
        this->logger->error("could not generate id for child");
        exit(EXIT_FAILURE);
    }

    umask(0);
}
