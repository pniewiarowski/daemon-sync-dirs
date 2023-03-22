#ifndef DAEMON_SYNC_DIRS_FLAG_H
#define DAEMON_SYNC_DIRS_FLAG_H

#include <string>

class Flag {
private:
    std::string key;
    std::string value;
public:
    Flag(const std::string &key, const std::string &value);

    std::string getKey();
    std::string getValue();
};

#endif //DAEMON_SYNC_DIRS_FLAG_H
