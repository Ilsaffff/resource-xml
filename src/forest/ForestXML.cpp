#include <iostream>
#include "ForestXML.h"


void ForestXML::load(std::string &file_path) {
    std::ifstream inFile(file_path);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open XML file: " << file_path << std::endl;
        return;
    }
    std::shared_ptr<NodeXML> tmp_node; // For Exception Guarantee
    processor.read(inFile, tmp_node);
    root = tmp_node;
}

void ForestXML::save() {
    std::string fileName;
    std::ofstream outFile;
    std::cout << "Enter the name_tag of a new xml file" << "\n";
    std::cin >> fileName;
    fileName += ".xml";


}

std::shared_ptr<NodeXML> ForestXML::operator[](size_t) {

    return std::shared_ptr<NodeXML>();
}

template<typename Functor>
void ForestXML::for_each(Functor &functor) {
    Forest::for_each(functor);
}


