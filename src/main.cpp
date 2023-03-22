#include "logger/Logger.h"

int main(int argc, char *argv[]) {
    auto logger = new Logger(
            "./success.log",
            "./warning.log",
            "./error.log"
    );

    logger->success("Good job bro!");
    logger->warning("It's work, but why?!?");
    logger->error("Everything is fucked up...:C");

    return 0;
}
