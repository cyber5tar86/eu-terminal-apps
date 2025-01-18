// FILE: eu-business-logic/EmUse/Models/main_view_model.cpp

#include "main_view_model.h"
#include "machine.h"

MainViewModel::MainViewModel(std::shared_ptr<Machine> machine, QObject *parent)
    : QObject(parent), m_machine(machine)
{
    m_engineSpeed = m_machine->engine()->engineSpeed();
    m_vehicleSpeed = m_machine->engine()->vehicleSpeed();
}

QuantityObject* MainViewModel::engineSpeed() const
{
    return m_engineSpeed.get();
}

QuantityObject* MainViewModel::vehicleSpeed() const
{
    return m_vehicleSpeed.get();
}