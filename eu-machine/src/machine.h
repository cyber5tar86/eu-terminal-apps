// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <cstdint>

// Forward declarations
class EngineTwin;

/*!
 * \brief The Machine class represents a machine in the business logic. The machine provides the
 * engine twin to the business logic.
 */
class Machine
{
public:
    /*!
     * \brief The Configuration enum class represents the configuration of the machine.
     */
    enum class Configuration : std::uint8_t
    {
        Product,
        Simulator,
    };

    /*!
     * Destroys the machine object.
     */
    virtual ~Machine();

    /*!
     * Returns the engine twin of the machine.
     */
    virtual EngineTwin *engine() const = 0;
};
