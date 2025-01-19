// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <memory.h>

#include <QList>
#include <QObject>
#include "quantity.h"
// Forward declarations
class QCanBusDevice;


/*!
 * \brief The CanBusRouter class routes CAN bus frames to the appropriate engine quantities.
 */
class CanBusRouter : public QObject
{
    // The Q_OBJECT macro is necessary for signals and slots.
    Q_OBJECT

public:
    /*!
     * Creates a new CAN bus router object with the given \a canBus and \a parent.
     */
    explicit CanBusRouter(QCanBusDevice *canBus, QObject *parent = nullptr);

    /*!
     * Destroys the CAN bus router object.
     */
    virtual ~CanBusRouter();

signals:
    /*!
     * This signal is emitted when new engine quantities have been received.
     */
    void newEngineQuantities(const QList<Quantity> &quantityColl);

private:
    class Impl; //!< Forward declaration of the implementation class.
    std::unique_ptr<Impl> m_impl;   //!< Pointer to the implementation class.
};
