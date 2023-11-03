#pragma once

#include <string>
#include <memory>
#include <map>

#include <list>

struct NodeXML {
public:
    NodeXML();

    void set_tag_name(std::string &name);

    std::string get_tag_name();

    std::string serialize_attr();

    void set_body(std::string &new_body);

    std::string get_body();

    bool empty_body();

    void add_attr(std::string &key, std::string &value);

    void set_parent(std::shared_ptr<NodeXML> &new_parent);

    std::shared_ptr<NodeXML> &get_parent();

    virtual void set_first_child(std::shared_ptr<NodeXML> &new_child);

    std::shared_ptr<NodeXML> &get_first_child();

    void set_next_sibling(std::shared_ptr<NodeXML> &new_sibling);

    std::shared_ptr<NodeXML> &get_next_sibling();

    void add_depth();

    size_t get_depth() const;

    size_t get_id() const;

    void set_id(int &new_id);

    bool empty();

    std::shared_ptr<NodeXML> operator++();

private:
    std::string name_tag;
    std::map<std::string, std::string> attributes;
    std::string body;
    std::shared_ptr<NodeXML> parent;
    std::shared_ptr<NodeXML> first_child;
    std::shared_ptr<NodeXML> next_sibling;
    size_t depth;
    size_t id;
};
