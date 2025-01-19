// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include "machine.h"

/**
 * @brief Create a Machine object
 *
 * @param configuration
 * @return Machine*
 */
Machine *createMachine(Machine::Configuration configuration);
