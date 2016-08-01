#pragma once


enum class BuildType
{
    UNDEFINED = 0
    , IRON_BUYER
};


class BuildItem
{
public:
    BuildItem(BuildType initType);

    virtual ~BuildItem() {}

    BuildType get_type() { return type; }

private:
    BuildType type;
};

