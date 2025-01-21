#pragma once

#include <string>

class Hmi
{
public:
    enum class Configuration
    {
        Qt
    };

    virtual ~Hmi();

    virtual void initialize(const std::string& name, void *value) = 0;
};
