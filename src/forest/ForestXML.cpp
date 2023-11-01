#include "ForestXML.h"


void ForestXML::load(std::string &filePath) {
    std::ifstream inFile(filePath);
    std::shared_ptr<NodeXML> tmpNode; // For Exception Guarantee
    parser.parse(inFile, tmpNode);
    node = tmpNode;
}

void ForestXML::save() {

}

template<typename Functor>
void ForestXML::for_each(Functor &functor) {
    ForestInterface::for_each(functor);
}


