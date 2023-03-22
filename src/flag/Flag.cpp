#include "Flag.h"

/**
 * Constructor create instance with key and value
 * where key = value, use to contains single parameters
 * flag for example: --flag, or -flag.
 *
 * @param value: Flag value.
 */
Flag::Flag(const std::string &value) :
        Flag(value, value) {}

/**
 * Constructor create instance with pair of key and value,
 * use for contains flag with parameters for example:
 * key="value".
 *
 * @param key: Flag key world.
 * @param value: Flag value for key.
 */
Flag::Flag(const std::string &key, const std::string &value) {
    this->key = key;
    this->value = value;
}

/**
 * Get current key instance.
 *
 * @return Current key instance.
 */
std::string Flag::getKey() {
    return this->key;
}

/**
 * Get current value instance.
 *
 * @return Current value instance.
 */
std::string Flag::getValue() {
    return this->value;
}
