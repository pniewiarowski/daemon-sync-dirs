#ifndef DAEMON_SYNC_DIRS_FLAG_H
#define DAEMON_SYNC_DIRS_FLAG_H

#include <string>
#include <utility>

namespace flag {
    class Flag {
    private:
        std::string key;
        std::string value;
    public:
        explicit Flag(const std::string &value);
        explicit Flag(std::string key, std::string value);

        std::string getKey();
        std::string getValue();
    };
}

#endif //DAEMON_SYNC_DIRS_FLAG_H
