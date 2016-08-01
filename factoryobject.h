#ifndef FACTORYOBJECT_H
#define FACTORYOBJECT_H


enum class FactoryTypes
{
    UNDEFINED = 0
    , WALL
    , ROAD
    , FLOOR
    , GRASS

};

class FactoryObject
{
public:
    FactoryObject(FactoryTypes initType);

    virtual ~FactoryObject() {}

    virtual FactoryTypes get_type() { return type; }

private:

    FactoryTypes type;
};

#endif // FACTORYOBJECT_H
