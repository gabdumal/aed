#include "externalHashNode.hpp"

#include <format>

ExternalHashNode::ExternalHashNode(ExternalHashNode::Key key, ExternalHashNode::Value value) {
    this->key = key;
    this->value = value;
}

ExternalHashNode::~ExternalHashNode() {
    this->key = default_key;
    this->value = default_value;
    this->next_node = nullptr;
}

ExternalHashNode::Value ExternalHashNode::getKey() {
    return this->key;
}

ExternalHashNode::Value ExternalHashNode::getValue() {
    return this->value;
}

void ExternalHashNode::setValue(ExternalHashNode::Value value) {
    this->value = value;
}

ExternalHashNode *ExternalHashNode::getNextNode() {
    return this->next_node;
}

void ExternalHashNode::setNextNode(ExternalHashNode *next_node) {
    this->next_node = next_node;
}

std::string ExternalHashNode::print() {
    return std::format("( key: {}, value: {} )", this->key, this->value);
}
