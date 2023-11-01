#pragma once

#include <fstream>
#include <memory>

template<typename T>
class ParserInterface {
public:
    virtual void parse(std::ifstream &, std::shared_ptr<T> &) = 0;
};