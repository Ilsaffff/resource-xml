cmake_minimum_required(VERSION 3.26)
project(resource_xml)

set(CMAKE_CXX_STANDARD 23)

add_executable(resource_xml main.cpp
        src/forest/ForestInterface.h
        src/forest/ForestXML.h
        src/forest/ForestXML.cpp
        src/parser/ParserInterface.h
        src/parser/ParserXML.cpp
        src/parser/ParserXML.h
        src/forest/node/NodeXML.cpp
        src/forest/node/NodeXML.h)
