#include "flag/Parser.h"
#include "watcher/Watcher.h"
#include "logger/Logger.h"
#include "daemon/Daemon.h"

int main(int argc, char *argv[]) {
    auto flags = flag::Parser::parse(argc, argv);
    auto watcher = new watcher::Watcher("./dir-to-sync");
    auto logger = new logger::Logger("./logs.log");
    auto daemon = new daemon::Daemon(watcher, logger);

    return 0;
}
