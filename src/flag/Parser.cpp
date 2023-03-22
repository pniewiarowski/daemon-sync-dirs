#include "Parser.h"

/**
 * Format default console input to vector of strings.
 *
 * @param argc: Number of given arguments.
 * @param argv: All given arguments.
 *
 * @return All provided arguments in vector of strings.
 */
std::vector<std::string> Parser::_parseToArgs(int argc, char **argv) {
    std::vector<std::string> args;

    if (argc > 1) {
        args.assign(argv + 1, argv + argc);
    }

    return args;
}

/**
 * Format given vector of strings to vector of
 * flags.
 *
 * @param args: Vector with strings of arguments.
 *
 * @return Vector with Flags.
 */
std::vector<Flag> Parser::_parseToFlags(const std::vector<std::string> &args) {
    std::vector<Flag> flags;
    std::string out;

    for (const auto &arg: args) {
        auto stream = std::stringstream(arg);
        std::vector<std::string> flag;

        while (std::getline(stream, out, '=')) {
            flag.push_back(out);
        }

        if (flag.size() == 2) {
            flags.push_back(*new Flag(flag[0], flag[1]));
        }

        if (flag.size() == 1) {
            flags.push_back(*new Flag(flag[0], flag[0]));
        }
    }

    return flags;
}

/**
 * Parse default arguments from entry point to vector of Flags.
 *
 * @param argc: Number of given arguments.
 * @param argv: All given arguments.
 *
 * @return Vector of flags.
 */
std::vector<Flag> Parser::parse(int argc, char **argv) {
    return Parser::_parseToFlags(Parser::_parseToArgs(argc, argv));
}
