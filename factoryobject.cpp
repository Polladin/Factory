#include "factoryobject.h"

FactoryObject::FactoryObject(FactoryTypes initType, std::size_t X, std::size_t Y)
    : type(initType), pos(X,Y)
{

}

