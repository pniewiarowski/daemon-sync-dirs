#include "Daemon.h"

/**
 * Daemon constructor return Daemon instance with
 * default parameters.
 */
daemon::Daemon::Daemon() {
    this->logger = new logger::Logger();
}

/**
 * Daemon constructor return Daemon instance with
 * given logger.
 *
 * @param logger Logger instance.
 */
daemon::Daemon::Daemon(logger::Logger *logger) {
    this->logger = logger;
}

/**
 * Execute current daemon instance.
 */
void daemon::Daemon::execute() {
    /** NOT IMPLEMENTED YET */
}
