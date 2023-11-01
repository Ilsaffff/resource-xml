#pragma once

#include <string>
#include <memory>
#include <map>
#include <list>

struct NodeXML {
    NodeXML() = default;

    std::string tagName;
    std::map<std::string, std::string> attributes;
    std::string body;
    std::shared_ptr<NodeXML> next;
    std::list<std::shared_ptr<NodeXML>> children;
};
