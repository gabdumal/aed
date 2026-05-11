#include "externalHashNode.hpp"

#include <format>

std::string ExternalHashNode::print() {
    return std::format("( key: {}, value: {} )", this->key, this->value);
}
