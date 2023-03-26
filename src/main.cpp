#include "flag/Parser.h"
#include "flag/Manager.h"
#include "flag/Flag.h"
#include "watcher/Watcher.h"
#include "logger/Logger.h"
#include "syncdaemon/Daemon.h"

int main(int argc, char *argv[]) {
    auto watcher = new watcher::Watcher("./dir-to-sync");
    auto logger = new logger::Logger("./logs.log");
    auto flags = flag::Parser::parse(argc, argv);
    auto flagManager = flag::Manager(&flags);

    auto sourceDir = flagManager.get("source").getValue();
    auto targetDir = flagManager.get("target").getValue();

    (new syncdaemon::Daemon(
            watcher,
            logger
    ))->execute();

    return 0;
}
