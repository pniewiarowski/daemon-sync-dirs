#include "logger/Logger.h"
#include "flag/Parser.h"
#include "daemon/Daemon.h"

int main(int argc, char *argv[]) {
    auto flags = flag::Parser::parse(argc, argv);
    auto daemon = new daemon::Daemon(
            new logger::Logger("./success.log", "./warning.log", "./error.log")
    );

    daemon->execute();

    return 0;
}
