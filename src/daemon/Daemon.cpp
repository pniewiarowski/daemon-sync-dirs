#include "Daemon.h"

/**
 * Daemon constructor return Daemon instance with
 * default parameters.
 */
Daemon::Daemon() {
    this->logger = new Logger();
}

/**
 * Daemon constructor return Daemon instance with
 * given logger.
 *
 * @param logger Logger instance.
 */
Daemon::Daemon(Logger *logger) {
    this->logger = logger;
}

/**
 * Execute current daemon instance.
 */
void Daemon::execute() {
    /** NOT IMPLEMENTED YET */
}
