// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <memory>
#include <QObject>

#include "quantity_object.h"

class CanBusRouter;


/*!
 * \brief The EngineTwin class represents the engine twin of a machine. The engine twin receives
 * engine data from the CAN bus and provides the engine data to the business logic.
 */
class EngineTwin : public QObject
{
    Q_OBJECT

public:
    /*!
     * EngineTwin does not take ownership of \a impl.
     */
    explicit EngineTwin(CanBusRouter *router);
    virtual ~EngineTwin();

    /*!
     * Returns the engine speed quantity object.
     */
    std::shared_ptr<QuantityObject> engineSpeed() const;

    /*!
     * Returns the vehicle speed quantity object.
     */
    std::shared_ptr<QuantityObject> vehicleSpeed() const;

    /*!
     * Returns the actual engine percent torque quantity object.
     */
    std::shared_ptr<QuantityObject> actualEnginePercentTorque() const;


signals:
    void errorMessage(const QString &message);

private:
    class Impl; //!< Forward declaration of the implementation class.
    std::unique_ptr<Impl> m_impl; //!< Pointer to the implementation class.
};
