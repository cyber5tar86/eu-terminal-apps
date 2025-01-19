// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <QByteArray>
#include <QObject>
#include <QString>
#include <QtGlobal>

// TODO: Rename to J1939SpnValue
class Quantity
{
    // The Q_GADGET macro is necessary for the Q_ENUM macro.
    Q_GADGET

public:
    // The Q_ENUM macro makes the enum class available to QML.
    enum class Id : std::uint16_t
    {
        Undefined = 0U,
        VehicleSpeed = 84U,
        EngineSpeed = 190U,
        ActualEnginePercentTorque = 513U,
        NominalLevelRequestRearAxle = 1750U,
        NominalLevelRequestFrontAxle = 1751U,
        KneelingRequestRightSide = 1748U,
        KneelingRequestLeftSide = 1749U,
    };
    Q_ENUM(Id) // The Q_ENUM macro makes the enum class available to QML.

    /*!
     * Creates a new quantity object with the given \a id and \a rawBytes.
     */
    Quantity() = default;

    /*!
     * Creates a new quantity object with the given \a id and \a rawBytes.
     */
    Quantity(Id id, const QByteArray &rawBytes);

    /*!
     * Returns the ID of the quantity.
     */
    Id id() const;

    /*!
     * Returns the raw bytes of the quantity.
     */
    QByteArray rawBytes() const;

private:
    Id m_id{Id::Undefined}; //!< ID of the quantity.
    QByteArray m_rawBytes; //!< Raw bytes of the quantity.
};

/*!
 * \brief The QuantityObject class represents a quantity object in the business logic.
 */
inline bool operator==(const Quantity &q1, const Quantity &q2)
{
    return q1.id() == q2.id() && q1.rawBytes() == q2.rawBytes();
}

/*!
 * \brief The QuantityObject class represents a quantity object in the business logic.
 */
inline bool operator!=(const Quantity &q1, const Quantity &q2)
{
    return !(q1 == q2);
}
