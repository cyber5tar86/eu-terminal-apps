// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QtGlobal>

#include "quantity_object.h"


/*!
 * \brief The MainModel class represents the main model of the application. The main model provides
 * the engine speed and the vehicle speed to the user interface.
 */
class MainModel : public QObject
{
    // The Q_OBJECT macro is necessary for signals and slots.
    Q_OBJECT
    // The QML_ELEMENT macro makes the class available to QML.
    QML_ELEMENT

    // The Q_PROPERTY macro defines a property that is accessible from QML.
    Q_PROPERTY(QuantityObject *engineSpeed READ engineSpeed CONSTANT)
    Q_PROPERTY(QuantityObject *vehicleSpeed READ vehicleSpeed CONSTANT)

public:
    /*!
     * Creates a new main model object with the given \a parent.
     */
    explicit MainModel(QObject *parent = nullptr);

    /*!
     * Returns the engine speed quantity object.
     */
    QuantityObject *engineSpeed() const;

    /*!
     * Returns the vehicle speed quantity object.
     */
    QuantityObject *vehicleSpeed() const;

    /*!
     * Sets the engine speed to the given \a rpm.
     */
    void setEngineSpeed(std::shared_ptr<QuantityObject> rpm);

    /*!
     * Sets the vehicle speed to the given \a kph.
     */
    void setVehicleSpeed(std::shared_ptr<QuantityObject> kph);

private:
    std::shared_ptr<QuantityObject> m_engineSpeed; //!< Pointer to the engine speed quantity object.
    std::shared_ptr<QuantityObject> m_vehicleSpeed; //!< Pointer to the vehicle speed quantity object.
};
