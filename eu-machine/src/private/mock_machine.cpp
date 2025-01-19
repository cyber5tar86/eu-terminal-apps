// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#include "engine_twin.h"
#include "private/mock_machine.h"
#include "../machine.h"


struct MockMachine::Impl
{
    EngineTwin m_engine{nullptr};
};

MockMachine::MockMachine()
    : Machine{}
    , m_impl{new Impl{}}
{
}

MockMachine::~MockMachine() = default;

EngineTwin *MockMachine::engine() const
{
    return &m_impl->m_engine;
}
