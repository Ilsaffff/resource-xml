#pragma once

#include "ForestInterface.h"
#include "../parser/ParserXML.h"



class ForestXML final : public ForestInterface, std::enable_shared_from_this<ForestXML> {
public:
    template<typename Functor>
    void for_each(Functor &functor);

    void save() override;

    void load(std::string &filePath) override;


private:
    ParserXML parser;
    std::shared_ptr<NodeXML> node;
};
