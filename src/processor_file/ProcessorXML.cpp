#include <stack>
#include <iostream>
#include "ProcessorXML.h"


void ProcessorXML::read(std::ifstream &file, std::shared_ptr<NodeXML> &root) {
    std::string line;
    int i = 0;
    std::stack<std::shared_ptr<NodeXML>> nodeStack;
    nodeStack.push(root);
    std::shared_ptr<NodeXML> currentNode = root;

    while (std::getline(file, line)) {
        line = line.substr(line.find_first_not_of(" \t"), line.find_last_not_of(" \t") + 1);

        if (line.empty()) {
            continue;
        }

        if (line[0] == '<') {
            if (line[1] == '/') {
                if (currentNode && line.size() > 2) {
                    std::string tag_name = line.substr(2, line.find_first_of('>') - 2);
                    if (currentNode->get_tag_name() == tag_name) {
                        currentNode = nodeStack.top();
                        nodeStack.pop();
                    }
                }
            } else {
                std::string tag_name = line.substr(1, line.find_first_of(" \t>") - 1);
                std::shared_ptr<NodeXML> newNode = std::make_shared<NodeXML>();
                newNode->set_id(++i);
                newNode->set_tag_name(tag_name);
                if (currentNode) {
                    currentNode->set_first_child(newNode);
                    newNode->set_parent(currentNode);
                }
                currentNode = newNode;

                nodeStack.push(newNode);

                size_t pos = line.find(tag_name) + tag_name.size();
                while (pos != std::string::npos) {
                    pos = line.find_first_of(" \t=", pos);
                    if (pos != std::string::npos) {
                        pos = line.find_first_not_of(" \t=", pos);
                        if (pos != std::string::npos && line[pos] != '>') {
                            size_t endPos = line.find("\"", pos + 1);
                            if (endPos != std::string::npos) {
                                std::string attrName = line.substr(pos, endPos - pos);
                                pos = endPos + 1;
                                endPos = line.find("\"", pos);
                                if (endPos != std::string::npos) {
                                    std::string attrValue = line.substr(pos, endPos - pos);
                                    newNode->add_attr(attrName, attrValue);
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (currentNode) {
                currentNode->set_body(line);
            }
        }
    }
}

void ProcessorXML::write(std::ofstream &file, const std::shared_ptr<NodeXML> &targetNode) {
    file << std::string(targetNode->get_depth(), '\t');
    file << "<" << targetNode->get_tag_name() << targetNode->serialize_attr() << ">" << "\n";
    if (!targetNode->empty_body()) {
        file << targetNode->get_body() << "\n";
    }
    if (!targetNode->get_first_child()->empty()) {
        write(file, targetNode->get_first_child());

        file << "</" << targetNode->get_tag_name() << ">" << "\n";
        if (!targetNode->get_next_sibling()->empty()) {
            write(file, targetNode->get_next_sibling());
        }
    }
}
