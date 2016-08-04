#pragma once

#include <cstddef>

enum class FactoryTypes
{
    UNDEFINED = 0
    , WALL
    , ROAD
    , FLOOR
    , GRASS

};

class ObjectPos
{
public:
    ObjectPos() = default;
    ObjectPos(const ObjectPos&) = default;

    ObjectPos(std::size_t initX, std::size_t initY)
        : X(initX), Y(initY)
    {}

    std::size_t X;
    std::size_t Y;
};


class FactoryObject
{
public:
    FactoryObject(FactoryTypes initType, std::size_t X, std::size_t Y);

    virtual ~FactoryObject() { }

    virtual FactoryTypes get_type() { return type; }

    ObjectPos get_pos() { return pos; }

private:
    FactoryTypes type;

    ObjectPos pos;

};

