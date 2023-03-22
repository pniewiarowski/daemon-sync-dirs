#ifndef DAEMON_SYNC_DIRS_PARSER_H
#define DAEMON_SYNC_DIRS_PARSER_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "Flag.h"

class Parser {
private:
    static std::vector<std::string> _parseToArgs(int argc, char *argv[]);
    static std::vector<Flag> _parseToFlags(const std::vector<std::string>&);
public:
    static std::vector<Flag> parse(int argc, char *argv[]);
};

#endif //DAEMON_SYNC_DIRS_PARSER_H
