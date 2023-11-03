cmake_minimum_required(VERSION 3.26)
project(resource_xml)

set(CMAKE_CXX_STANDARD 23)

add_executable(resource_xml main.cpp
        src/forest/Forest.h
        src/forest/ForestXML.h
        src/forest/ForestXML.cpp
        src/processor_file/ProcessorFIle.h
        src/processor_file/ProcessorXML.cpp
        src/processor_file/ProcessorXML.h
        src/forest/node/NodeXML.cpp
        src/forest/node/NodeXML.h
        src/resource/ResourceXML.cpp
        src/resource/ResourceXML.h
)
