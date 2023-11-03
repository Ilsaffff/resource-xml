#pragma once

#include <fstream>
#include <memory>

template<typename T>
class ProcessorFIle {
public:
    virtual void read(std::ifstream &, std::shared_ptr<T> &) = 0;
    virtual void write(std::ofstream &, const std::shared_ptr<T> &) = 0;
};