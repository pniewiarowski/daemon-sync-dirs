#include "Manager.h"

/**
 * Manager constructor return Manager instance with empty,
 * vector of flags to manage.
 */
flag::Manager::Manager() :
        flags(new std::vector<Flag>()) {}

/**
 * Manager constructor return Manager instance with
 * given vector of flags to manage.
 *
 * @param flags Vector of flags to manage.
 */
flag::Manager::Manager(std::vector<Flag> *flags) :
        flags(flags) {}

/**
 * Add new Flag instance to manager.
 *
 * @param flag Extra flag to manage.
 */
void flag::Manager::add(Flag flag) {
    this->flags->push_back(flag);
}

/**
 * Clear vector of flags.
 */
void flag::Manager::clear() {
    this->flags->clear();
}

/**
 * Search in vector Flag with key field match with
 * given one.
 *
 * @param key Key to look for.
 *
 * @return Match Flag instance.
 */
flag::Flag flag::Manager::get(std::string key) {
    for (auto flag: *this->flags) {
        if (flag.getKey() == key) {
            return flag;
        }
    }

    throw std::invalid_argument("not found flag with given key");
}
