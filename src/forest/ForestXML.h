#pragma once

#include "Forest.h"
#include "../processor_file/ProcessorXML.h"


class ForestXML final : public Forest, std::enable_shared_from_this<ForestXML> {
public:
    template<typename Functor>
    void for_each(Functor &functor);

    void save() override;

    void load(std::string &file_path) override;

    std::shared_ptr<NodeXML> operator[](size_t);


private:
    ProcessorXML processor;
    std::shared_ptr<NodeXML> root;
};
