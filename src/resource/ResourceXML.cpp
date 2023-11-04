#include "ResourceXML.h"

#include <utility>

std::shared_ptr<ResourceXML> ResourceXML::instance = nullptr;

std::shared_ptr<ResourceXML> &ResourceXML::create() {
    if (!instance) {
        instance = std::shared_ptr<ResourceXML>(new ResourceXML);
    }
    return instance;
}

ResourceXML::Iterator::Iterator(ResourceXML::Iterator::pointer ptr) : m_ptr(std::move(ptr)) {}

bool operator==(const ResourceXML::Iterator &a, const ResourceXML::Iterator &b) {
    return a.m_ptr->get_id() == a.m_ptr->get_id();
}

bool operator!=(const ResourceXML::Iterator &a, const ResourceXML::Iterator &b) {
    return a.m_ptr->get_id() != a.m_ptr->get_id();
}

ResourceXML::Iterator ResourceXML::begin() const {
    return Iterator(file->get_root());
}

ResourceXML::Iterator ResourceXML::end() const {
    return Iterator(file->get_last());
}

ResourceXML::Iterator ResourceXML::find(const std::string &name_tag) {
    auto target_node = std::find_if(begin(), end(), [name_tag](std::shared_ptr<NodeXML> &node) {
        return node->get_tag_name() == name_tag;
    });
    return target_node;
}

bool ResourceXML::erase(const std::string &name_tag) {
    auto target_node = find(name_tag);
    auto tmp = target_node;
    if (!target_node->empty()) {
        if (!target_node->get_parent()->empty()) {
            if (!target_node->get_first_child()->empty()) {
                target_node->get_parent()->set_first_child(target_node->get_first_child());
                tmp = target_node->get_first_child();
                if (!target_node->get_next_sibling()->empty()) {
                    while (!tmp->get_next_sibling()->empty()) {
                        tmp = tmp->get_next_sibling();
                    }
                    tmp->set_next_sibling(target_node->get_next_sibling());
                }
            }
        } else {
            if (!target_node->get_first_child()->empty()) {
                if (!target_node->get_next_sibling()->empty()) {
                    while (!tmp->get_next_sibling()->empty()) {
                        tmp = tmp->get_next_sibling();
                    }
                    auto last_sibling = *tmp;
                    last_sibling->set_next_sibling(target_node->get_first_child());
                } else {
                    *target_node = target_node->get_first_child();
                }
            }
            if (target_node->get_first_child()->empty() &&
                target_node->get_next_sibling()->empty()) {
                *target_node = nullptr;
            }
        }
        return true;
    }
    return false;
}

ResourceXML::Iterator
ResourceXML::add(std::string &name_tag, std::map<std::string, std::string> &attributes,
                 ResourceXML::Iterator &iterator) {
    auto new_node = std::make_shared<NodeXML>(name_tag, attributes);
    if (iterator->get_first_child()->empty()) {
        iterator->set_first_child(new_node);
        return iterator->get_first_child();
    } else {
        iterator = iterator->get_first_child();
        while (!iterator->get_next_sibling()->empty())
            iterator = iterator->get_next_sibling();
        iterator->set_next_sibling(new_node);
        return iterator->get_next_sibling();
    }
}


ResourceXML::Iterator ResourceXML::Iterator::operator++(int) {
    ResourceXML::Iterator tmp = *this;
    if (!m_ptr->get_first_child()->empty()) {
        m_ptr = m_ptr->get_first_child();
    } else if (!m_ptr->get_next_sibling()->empty()) {
        m_ptr = m_ptr->get_next_sibling();
    } else {
        while (!m_ptr->empty() && m_ptr->get_next_sibling()->empty())
            m_ptr = m_ptr->get_parent();
    }
    if (!m_ptr->empty()) {
        m_ptr = m_ptr->get_next_sibling();
    }
    return tmp;
}

std::shared_ptr<NodeXML> &ResourceXML::Iterator::operator*() {
    return m_ptr;
}

ResourceXML::Iterator &ResourceXML::Iterator::operator++() {
    if (!m_ptr->get_first_child()->empty()) {
        m_ptr = m_ptr->get_first_child();
    } else if (!m_ptr->get_next_sibling()->empty()) {
        m_ptr = m_ptr->get_next_sibling();
    } else {
        while (!m_ptr->empty() && m_ptr->get_next_sibling()->empty())
            m_ptr = m_ptr->get_parent();
    }
    if (!m_ptr->empty()) {
        m_ptr = m_ptr->get_next_sibling();
    }
    return *this;
}

ResourceXML::Iterator::pointer ResourceXML::Iterator::operator->() {
    return m_ptr;
}



