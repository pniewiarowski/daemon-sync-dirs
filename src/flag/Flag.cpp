#include "Flag.h"

/**
 * Constructor create instance with pair of key and value.
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
