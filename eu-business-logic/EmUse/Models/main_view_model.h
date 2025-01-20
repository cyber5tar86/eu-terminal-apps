// FILE: eu-business-logic/EmUse/Models/main_view_model.h

#pragma once

#include <QObject>
#include <QQmlEngine>
#include <memory>

#include "machine.h"
#include "quantity_object.h"


/*!
 * \brief The MainViewModel class represents the main view model of the application. The main view
 * model provides the engine speed and the vehicle speed to the user interface.
 */
class MainViewModel : public QObject
{
    // The Q_OBJECT macro is necessary for signals and slots.
    Q_OBJECT
    // The QML_ELEMENT macro makes the class available to QML.
    QML_ELEMENT

    // The Q_PROPERTY macro defines a property that is accessible from QML.
    Q_PROPERTY(QuantityObject* engineSpeed READ engineSpeed NOTIFY engineSpeedChanged)
    Q_PROPERTY(QuantityObject* vehicleSpeed READ vehicleSpeed NOTIFY vehicleSpeedChanged)

public:
    /*!
     * Creates a new main view model object with the given \a machine and \a parent.
     */
    explicit MainViewModel(std::shared_ptr<Machine> machine, QObject *parent = nullptr);

    /*!
     * Returns the engine speed quantity object.
     */
    QuantityObject* engineSpeed() const;

    /*!
     * Returns the vehicle speed quantity object.
     */
    QuantityObject* vehicleSpeed() const;

    /*!
     * Sets the engine speed to the given \a rpm.
     */
    void setEngineSpeed(std::shared_ptr<QuantityObject> rpm);

    /*!
     * Sets the vehicle speed to the given \a kph.
     */
    void setVehicleSpeed(std::shared_ptr<QuantityObject> kph);

signals:
    /*!
     * This signal is emitted when the engine speed has changed.
     */
    void engineSpeedChanged();

    /*!
     * This signal is emitted when the vehicle speed has changed.
     */
    void vehicleSpeedChanged();

private:
    std::shared_ptr<Machine> m_machine; //!< Pointer to the machine object.
    std::shared_ptr<QuantityObject> m_engineSpeed;  //!< Pointer to the engine speed quantity object.
    std::shared_ptr<QuantityObject> m_vehicleSpeed; //!< Pointer to the vehicle speed quantity object.
};