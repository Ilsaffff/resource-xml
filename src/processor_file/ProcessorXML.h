#pragma once
#include "ProcessorFIle.h"
#include "../file/node/NodeXML.h"


class ProcessorXML: ProcessorFIle<NodeXML> {
public:
    void read(std::ifstream &file, std::shared_ptr<NodeXML>& targetNode) override;
    void write(std::ofstream &file, const std::shared_ptr<NodeXML> &targetNode) override;
};


