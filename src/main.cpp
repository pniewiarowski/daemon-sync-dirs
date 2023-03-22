#include "logger/Logger.h"
#include "flag/Parser.h"

int main(int argc, char *argv[]) {
    auto flags = Parser::parse(argc, argv);

    auto logger = new Logger(
            "./success.log",
            "./warning.log",
            "./error.log"
    );

    for (auto flag: flags) {
        std::cout << flag.getKey() << ": " << flag.getValue() << std::endl;
    }

    logger->success("Good job bro!");
    logger->warning("It's work, but why?!?");
    logger->error("Everything is fucked up...:C");

    return 0;
}
