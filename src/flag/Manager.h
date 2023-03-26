#ifndef DAEMON_SYNC_DIRS_MANAGER_H
#define DAEMON_SYNC_DIRS_MANAGER_H


#include <vector>
#include <stdexcept>

#include "Flag.h"

namespace flag {
    class Manager {
    private:
        std::vector<Flag> *flags;
    public:
        Manager();
        Manager(std::vector<Flag> *flags);

        void add(Flag flag);
        void clear();
        Flag get(std::string key);
    };
}


#endif //DAEMON_SYNC_DIRS_MANAGER_H
