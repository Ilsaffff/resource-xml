#include "ResourceXML.h"


ResourceXML &ResourceXML::create() {
    if (instance == nullptr){
        instance.reset(new ResourceXML);
    }
    return *instance;
}

