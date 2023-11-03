#include "ResourceXML.h"

#include <utility>

std::shared_ptr<ResourceXML> ResourceXML::instance = nullptr;

std::shared_ptr<ResourceXML> &ResourceXML::create() {
    if (!instance) {
        instance = std::shared_ptr<ResourceXML>(new ResourceXML);
    }
    return instance;
}

ResourceXML::Iterator::Iterator(ResourceXML::Iterator::pointer ptr): m_ptr(std::move(ptr)) {}

bool operator==(const ResourceXML::Iterator &a, const ResourceXML::Iterator &b) {
    return a.m_ptr->get_depth() == a.m_ptr->get_depth();
}

bool operator!=(const ResourceXML::Iterator &a, const ResourceXML::Iterator &b) {
    return a.m_ptr->get_id() != a.m_ptr->get_id();
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


