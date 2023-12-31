#include <iostream>
#include "FileXML.h"


void FileXML::load(std::string &file_path) {
    try {
        std::ifstream inFile(file_path);
        if (!inFile.is_open()) {
            std::cerr << "Failed to open XML file: " << file_path << std::endl;
            return;
        }
        std::shared_ptr<NodeXML> tmp_node; // For Exception Guarantee
        processor.read(inFile, tmp_node);
        root = tmp_node;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void FileXML::save() {
    try {
        std::string file_name;
        std::cout << "Введи название нового файла" << "\n";
        std::cin >> file_name;
        file_name += ".xml";
        std::ofstream out_file(file_name);
        processor.write(out_file, root);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

std::shared_ptr<NodeXML> FileXML::operator[](size_t) {

    return std::shared_ptr<NodeXML>();
}

std::shared_ptr<NodeXML> &FileXML::get_root() {
    return root;
}

std::shared_ptr<NodeXML> &FileXML::get_last() {
    std::shared_ptr<NodeXML> tmp = root;
    if (tmp->get_first_child()->get_next_sibling()->empty()) {
        return tmp->get_first_child();
    }
    while (!tmp->get_first_child()->empty()) {
        tmp = tmp->get_first_child();
        while (!tmp->get_next_sibling()->empty()) {
            if (tmp->get_next_sibling()->get_first_child()->empty()) {
                return tmp->get_next_sibling();
            }
            tmp = tmp->get_next_sibling();
        }
    }
}

template<typename Functor>
void FileXML::for_each(Functor &functor) {
    File::for_each(functor);
}


