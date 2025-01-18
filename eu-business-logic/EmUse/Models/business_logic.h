// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <memory>
#include <QObject>
#include "main_view_model.h"

class Machine;

class BusinessLogic : public QObject
{
    Q_OBJECT

    Q_PROPERTY(MainViewModel* mainViewModel READ mainViewModel CONSTANT)

public:
    explicit BusinessLogic(std::shared_ptr<Machine> machine, QObject *parent = nullptr);
    virtual ~BusinessLogic();

    MainViewModel* mainViewModel();

private:
    std::shared_ptr<Machine> m_machine;
    MainViewModel* m_mainViewModel{nullptr};
};
