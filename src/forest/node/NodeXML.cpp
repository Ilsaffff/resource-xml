#include "NodeXML.h"

void NodeXML::setTagName(std::string &newName) {
    name = newName;
}

void NodeXML::addAttribute(std::string &key, std::string &value) {
    attributes[key] = value;
}

void NodeXML::addChild(std::shared_ptr<NodeXML> &child) {
    children.push_back(child);
}

std::shared_ptr<NodeXML> &NodeXML::getNextNode() {
    return next;
}

void NodeXML::setBody(std::string &newBody) {
    body = newBody;
}

void NodeXML::setNextNode(std::shared_ptr<NodeXML> &nextNode) {
    next = nextNode;
}
