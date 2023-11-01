#include "ParserXML.h"


void ParserXML::parse(std::ifstream &file, std::shared_ptr<NodeXML>& targetNode) {
    std::string line;
    std::getline(file, line);


    while (std::getline(file, line)) {
        line = line.substr(line.find_first_not_of(" \t\n\r\f\v"));
        line = line.substr(0, line.find_last_not_of(" \t\n\r\f\v") + 1);

        if (line.empty()) {
            continue;
        }

        if (line[0] == '<') {
            if (line[1] == '/') {
                targetNode = targetNode->next;
            } else {
                std::size_t endTagPos = line.find('>');
                std::string tag = line.substr(1, endTagPos - 1);
                std::shared_ptr<NodeXML> newNode = std::make_shared<NodeXML>();
                newNode->tagName = tag;
                targetNode->children.push_back(newNode);
                newNode->next = targetNode;
                targetNode = newNode;

                while (line[endTagPos] != '>') {
                    std::size_t attrStart = line.find_first_not_of(" \t", endTagPos + 1);
                    std::size_t attrEnd = line.find('=', attrStart);
                    std::string attributeName = line.substr(attrStart, attrEnd - attrStart);
                    attrStart = line.find('"', attrEnd) + 1;
                    attrEnd = line.find('"', attrStart);
                    std::string attributeValue = line.substr(attrStart, attrEnd - attrStart);
                    newNode->attributes[attributeName] = attributeValue;
                    endTagPos = line.find(' ', attrEnd);
                }
            }
        } else {
            targetNode->body = line;
        }
    }
}
