#include <sstream>
#include "NodeXML.h"


NodeXML::NodeXML() : depth(), id(0) {}


void NodeXML::set_tag_name(std::string &name) {
    name_tag = name;
}

void NodeXML::add_attr(std::string &key, std::string &value) {
    attributes[key] = value;
}


void NodeXML::set_body(std::string &new_body) {
    body = new_body;
}


std::string NodeXML::get_tag_name() {
    return name_tag;
}

std::string NodeXML::serialize_attr() {
    std::stringstream str_attr;
    for (auto const &[key, value]: attributes) {
        str_attr << " " << key << "=" << "\"" << value << "\"";
    }
    return str_attr.str();
}

std::string NodeXML::get_body() {
    return body;
}

bool NodeXML::empty_body() {
    return body.empty();
}


void NodeXML::set_parent(std::shared_ptr<NodeXML> &new_parent) {
    parent = new_parent;
}

std::shared_ptr<NodeXML> &NodeXML::get_parent() {
    return parent;
}


void NodeXML::set_first_child(std::shared_ptr<NodeXML> &new_child) {
    first_child = new_child;
}


std::shared_ptr<NodeXML> &NodeXML::get_first_child() {
    return first_child;
}

void NodeXML::set_next_sibling(std::shared_ptr<NodeXML> &new_sibling) {
    next_sibling = new_sibling;
}


std::shared_ptr<NodeXML> &NodeXML::get_next_sibling() {
    return next_sibling;
}

void NodeXML::add_depth() {
    depth++;
}

size_t NodeXML::get_depth() const {
    return depth;
}


bool NodeXML::empty() {
    return static_cast<bool>(this);
}

size_t NodeXML::get_id() const {
    return id;
}

void NodeXML::set_id(size_t &new_id) {
    id = new_id;
}

std::shared_ptr<NodeXML> NodeXML::operator++() {
    if (!this->get_first_child()->empty()){
        return this->get_first_child();
    }
    else if (!this->get_next_sibling()->empty()){
        return this->get_next_sibling();
    }
    return std::shared_ptr<NodeXML>();
}
