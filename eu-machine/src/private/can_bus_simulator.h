// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <QCanBusFrame>
#include <QObject>
#include <QTimeLine>


/*!
 * \brief The CanBusSimulator class simulates incoming CAN bus frames.
 */
class CanBusSimulator : public QObject
{
    // The Q_OBJECT macro is necessary for signals and slots.
    Q_OBJECT

public:
    /*!
     * Creates a new CAN bus simulator object with the given \a parent.
     */
    explicit CanBusSimulator(QObject *parent = nullptr);

signals:
    /*!
     * This signal is emitted when new incoming CAN bus frames have been received.
     */
    void newIncomingFrames(const QList<QCanBusFrame> &frameColl);

private slots:
    /*!
     * This slot is called when the RPM time line has changed.
     */
    void onEngineSpeedChanged(qreal value);

    /*!
     * This slot is called when the KPH time line has changed.
     */
    void onVehicleSpeedChanged(qreal value);

private:
    QTimeLine m_rpmTimeLine; //!< Time line for the engine speed.
    QTimeLine m_kphTimeLine; //!< Time line for the vehicle speed.
};
