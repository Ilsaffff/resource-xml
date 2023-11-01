#pragma once

#include <memory>



class ResourceXML {
private:
    static std::unique_ptr<ResourceXML> instance;

    ResourceXML() = default;

public:
    static ResourceXML &create();
};
