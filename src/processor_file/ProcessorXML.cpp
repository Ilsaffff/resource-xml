#include <stack>
#include <iostream>
#include "ProcessorXML.h"


void ProcessorXML::read(std::ifstream &file, std::shared_ptr<NodeXML> &root) {
    std::string line;
    size_t id = 0;
    std::stack<std::shared_ptr<NodeXML>> node_stack;
    node_stack.push(root);
    std::shared_ptr<NodeXML> current_node = root;

    while (std::getline(file, line)) {
        line = line.substr(line.find_first_not_of(" \t"), line.find_last_not_of(" \t") + 1);

        if (line.empty()) {
            continue;
        }

        if (line[0] == '<') {
            if (line[1] == '/') {
                if (current_node && line.size() > 2) {
                    std::string tag_name = line.substr(2, line.find_first_of('>') - 2);
                    if (current_node->get_tag_name() == tag_name) {
                        current_node = node_stack.top();
                        node_stack.pop();
                    }
                }
            } else {
                std::string tag_name = line.substr(1, line.find_first_of(" \t>") - 1);
                std::shared_ptr<NodeXML> new_node = std::make_shared<NodeXML>();
                new_node->set_id(++id);
                new_node->set_tag_name(tag_name);
                if (current_node) {
                    current_node->set_first_child(new_node);
                    new_node->set_parent(current_node);
                }
                current_node = new_node;

                node_stack.push(new_node);

                size_t pos = line.find(tag_name) + tag_name.size();
                while (pos != std::string::npos) {
                    pos = line.find_first_of(" \t=", pos);
                    if (pos != std::string::npos) {
                        pos = line.find_first_not_of(" \t=", pos);
                        if (pos != std::string::npos && line[pos] != '>') {
                            size_t endPos = line.find("\"", pos + 1);
                            if (endPos != std::string::npos) {
                                std::string attr_name = line.substr(pos, endPos - pos);
                                pos = endPos + 1;
                                endPos = line.find("\"", pos);
                                if (endPos != std::string::npos) {
                                    std::string attrValue = line.substr(pos, endPos - pos);
                                    new_node->add_attr(attr_name, attrValue);
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (current_node) {
                current_node->set_body(line);
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
