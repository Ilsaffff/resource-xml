#pragma once

#include <string>
#include <memory>
#include <map>
#include <list>

struct NodeXML {
public:
    NodeXML() = default;
    void setTagName(std::string& newName);
    void setBody(std::string& newBody);
    void addAttribute(std::string& key, std::string& value);
    void addChild(std::shared_ptr<NodeXML>& child);
    void setNextNode(std::shared_ptr<NodeXML>& nextNode);
    std::shared_ptr<NodeXML>& getNextNode();

private:
    std::string name;
    std::map<std::string, std::string> attributes;
    std::string body;
    std::shared_ptr<NodeXML> next;
    std::list<std::shared_ptr<NodeXML>> children;
};
