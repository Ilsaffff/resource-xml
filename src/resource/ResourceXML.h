#pragma once

#include "iterator"
#include "../file/node/NodeXML.h"
#include "../file/FileXML.h"
#include <memory>
#include <utility>


class ResourceXML {
private:
    static std::shared_ptr<ResourceXML> instance;

    ResourceXML() = default;


public:
    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = NodeXML;
        using pointer = std::shared_ptr<NodeXML>;
        using reference = std::shared_ptr<NodeXML> &;

        Iterator(pointer ptr);

        reference operator*();

        pointer operator->();

        Iterator &operator++();

        Iterator operator++(int);

        friend bool operator==(const Iterator &a, const Iterator &b);
        friend bool operator!=(const Iterator &a, const Iterator &b);
    private:
        pointer m_ptr;
    };
    Iterator begin() const;
    Iterator end() const;

    std::unique_ptr<FileXML> forest_xml;
    static std::shared_ptr<ResourceXML> &create();
};
