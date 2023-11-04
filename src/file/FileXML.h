#pragma once

#include "File.h"
#include "../processor_file/ProcessorXML.h"


class FileXML final : public File, std::enable_shared_from_this<FileXML> {
public:
    template<typename Functor>
    void for_each(Functor &functor);

    void save() override;

    void load(std::string &file_path) override;

    std::shared_ptr<NodeXML> operator[](size_t);

    std::shared_ptr<NodeXML>& get_root();

    std::shared_ptr<NodeXML>& get_last();

private:
    ProcessorXML processor;
    std::shared_ptr<NodeXML> root;
};
