#include "logger/Logger.h"
#include "flag/Parser.h"
#include "daemon/Daemon.h"

int main(int argc, char *argv[]) {
    auto flags = Parser::parse(argc, argv);
    auto daemon = new Daemon(
            new Logger("./success.log", "./warning.log", "./error.log")
    );

    daemon->execute();

    return 0;
}
