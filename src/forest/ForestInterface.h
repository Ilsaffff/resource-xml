#pragma once

#include "string"

class ForestInterface {
protected:
    virtual void save() = 0;

    virtual void load(std::string &filename) = 0;

    virtual void print() = 0;

    template<typename Functor>
    void for_each(Functor &functor){};
};
