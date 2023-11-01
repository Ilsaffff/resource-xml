#pragma once
#include "ParserInterface.h"
#include "../forest/node/NodeXML.h"


class ParserXML: ParserInterface<NodeXML> {
public:
    void parse(std::ifstream &file, std::shared_ptr<NodeXML>& targetNode) override;
};


