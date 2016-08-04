#pragma once

#include <string>

#include "factoryobject.h"

class FactoryObjectBuilder
{
public:

    static FactoryObject* build(FactoryTypes type, std::size_t X, std::size_t Y);


    // throw with Build Error
    class UndefinedTypeOfObject
    {
    public:
        UndefinedTypeOfObject(std::string str, FactoryTypes type)
            : errorString (str)
            , objectType (type)
        {}

        std::string what()
        {
            return errorString
                    + " " + std::to_string(static_cast<int>(objectType));
        }

    private:
        std::string errorString;

        FactoryTypes objectType;
    };
};

