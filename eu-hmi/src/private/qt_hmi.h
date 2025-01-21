#pragma once

#include <memory>

#include "../hmi.h"

class QtHmi: public Hmi
{
public:
    QtHmi();
    QtHmi(const QtHmi &) = delete;
    QtHmi &operator=(const QtHmi &) = delete;
    virtual ~QtHmi();

    void initialize(const std::string& name, void *value) override;

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};