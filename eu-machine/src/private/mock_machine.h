// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <memory>

// Forward declarations
class Machine;


/*!
 * \brief The MachineCreator class creates a machine object.
 */
class MockMachine : public Machine
{
public:
    /*!
     * Creates a new mock machine object.
     */
    MockMachine();

    /*!
     * Deletes the copy constructor.
     */
    MockMachine(const MockMachine &) = delete;

    /*!
     * Deletes the assignment operator.
     */
    MockMachine &operator=(const MockMachine &) = delete;

    /*!
     * Destroys the mock machine object.
     */
    virtual ~MockMachine();

    /*!
     * Returns the engine twin of the mock machine.
     */
    EngineTwin *engine() const override;

private:
    struct Impl; //!< Forward declaration of the implementation class.
    std::unique_ptr<Impl> m_impl; //!< Pointer to the implementation class.
};
