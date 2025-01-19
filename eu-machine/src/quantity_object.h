// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <memory>

#include <QObject>
#include <QString>
#include <QtGlobal>


/*!
 * \brief The QuantityObject class represents a quantity object in the business logic.
 */
class QuantityObject : public QObject
{
    // The Q_OBJECT macro is necessary for signals and slots.
    Q_OBJECT

    // The Q_PROPERTY macro defines a property that is accessible from QML.
    Q_PROPERTY(qreal value READ value NOTIFY valueChanged)
    Q_PROPERTY(QString valueString READ valueString NOTIFY valueChanged)
    Q_PROPERTY(QString unit READ unit CONSTANT)
    Q_PROPERTY(qreal minimum READ minimum CONSTANT)

public:
    /*!
     * Creates a new quantity object with the given \a minimum, \a maximum, \a precision, \a unit, and
     * \a parent.
     */
    explicit QuantityObject(qreal minimum, qreal maximum,
                            int precision, const QString &unit,
                            QObject *parent = nullptr);

    /*!
     * Destroys the quantity object.
     */
    virtual ~QuantityObject();

    /*!
     * Returns the value of the quantity.
     */
    qreal value() const;

    /*!
     * Returns the value of the quantity as a string.
     */
    QString valueString() const;

    /*!
     * Sets the value of the quantity to the given \a value.
     */
    void setValue(qreal value);

    /*!
     * Returns the unit of the quantity.
     */
    QString unit() const;

    /*!
     * Returns the minimum value of the quantity.
     */
    qreal minimum() const;

signals:
    /*!
     * This signal is emitted when the value of the quantity has changed.
     */
    void valueChanged();

private:
    struct Impl; //!< Forward declaration of the implementation class.
    std::unique_ptr<Impl> m_impl; //!< Pointer to the implementation class.
    qreal m_minimum; //!< Minimum value of the quantity.
};
