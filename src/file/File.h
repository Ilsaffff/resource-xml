#pragma once

#include "string"
#include "memory"


class File {
protected:
    virtual void save() = 0;

    virtual void load(std::string &filename) = 0;

    virtual void print() = 0;

    template<typename Functor>
    static void for_each(Functor &functor){};
};
