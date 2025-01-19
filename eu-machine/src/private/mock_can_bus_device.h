// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <QObject>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include <QList>
#include <QString>

/*!
 * \brief The MockCanBusDevice class simulates a CAN bus device for testing purposes.
 */
class MockCanBusDevice : public QCanBusDevice
{
    // The Q_OBJECT macro is necessary for signals and slots.
    Q_OBJECT

public:
    /*!
     * Creates a new mock CAN bus device object with the given \a parent.
     */
    explicit MockCanBusDevice(QObject *parent = nullptr);

public slots:
    /*!
     * This slot is called when new incoming CAN bus frames have been received.
     */
    void appendIncomingFrame(const QCanBusFrame &frame);

    /*!
     * This slot is called when new incoming CAN bus frames have been received.
     */
    void appendIncomingFrames(const QList<QCanBusFrame> &frames);

public:

    /*!
     * Returns the current state of the CAN bus device.
     */
    bool writeFrame(const QCanBusFrame &frame) override;

    /*!
     * Returns the current state of the CAN bus device.
     */
    QString interpretErrorFrame(const QCanBusFrame &errorFrame) override;

protected:

    /*!
     * Returns the current state of the CAN bus device.
     */
    bool open() override;

    /*!
     * Returns the current state of the CAN bus device.
     */
    void close() override;
};
