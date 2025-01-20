// FILE: eu-business-logic/EmUse/Models/main_view_model.cpp

#include <memory>
#include "main_view_model.h"
#include "machine.h"
#include "quantity_object.h"


MainViewModel::MainViewModel(std::shared_ptr<Machine> machine, QObject *parent)
    : QObject(parent), m_machine(machine)
{
    m_engineSpeed = m_machine->engine()->engineSpeed();
    m_vehicleSpeed = m_machine->engine()->vehicleSpeed();
}

QuantityObject* MainViewModel::engineSpeed() const
{
    return m_machine->engine()->engineSpeed().get();
}

QuantityObject* MainViewModel::vehicleSpeed() const
{
    return m_machine->engine()->vehicleSpeed().get();
}

void MainModel::setEngineSpeed(std::shared_ptr<QuantityObject> rpm)
{
    m_machine->engine()->engineSpeed() = rpm;
}

void MainModel::setVehicleSpeed(std::shared_ptr<QuantityObject> kph)
{
    m_machine->engine()->vehicleSpeed() = kph;
}