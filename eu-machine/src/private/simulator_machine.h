// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <memory>
#include "../machine.h"


/*!
 * \brief The MachineCreator class creates a machine object.
 */
class SimulatorMachine : public Machine
{
public:
    /*!
     * Creates a new simulator machine object.
     */
    SimulatorMachine();

    /*!
     * Deletes the copy constructor.
     */
    SimulatorMachine(const SimulatorMachine &) = delete;

    /*!
     * Deletes the assignment operator.
     */
    SimulatorMachine &operator=(const SimulatorMachine &) = delete;

    /*!
     * Destroys the simulator machine object.
     */
    virtual ~SimulatorMachine();

    /*!
     * Returns the engine twin of the simulator machine.
     */
    EngineTwin *engine() const override;

private:
    struct Impl; //!< Forward declaration of the implementation class.
    std::unique_ptr<Impl> m_impl; //!< Pointer to the implementation class.
};
