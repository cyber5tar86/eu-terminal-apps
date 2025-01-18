// FILE: eu-business-logic/EmUse/Models/main_view_model.h

#pragma once

#include <QObject>
#include <memory>
#include "quantity_object.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QuantityObject* engineSpeed READ engineSpeed NOTIFY engineSpeedChanged)
    Q_PROPERTY(QuantityObject* vehicleSpeed READ vehicleSpeed NOTIFY vehicleSpeedChanged)

public:
    explicit MainViewModel(std::shared_ptr<Machine> machine, QObject *parent = nullptr);

    QuantityObject* engineSpeed() const;
    QuantityObject* vehicleSpeed() const;

signals:
    void engineSpeedChanged();
    void vehicleSpeedChanged();

private:
    std::shared_ptr<Machine> m_machine;
    std::shared_ptr<QuantityObject> m_engineSpeed;
    std::shared_ptr<QuantityObject> m_vehicleSpeed;
};