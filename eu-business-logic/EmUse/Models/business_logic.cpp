// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#include <memory>
#include <QObject>

#include "engine_twin.h"
#include "machine.h"
#include "business_logic.h"
#include "main_view_model.h"


BusinessLogic::BusinessLogic(std::shared_ptr<Machine> machine, QObject *parent)
    : QObject(parent)
    , m_machine{std::move(machine)}
{
}

BusinessLogic::~BusinessLogic() = default;


MainViewModel *BusinessLogic::mainViewModel()
{
    if (m_mainViewModel == nullptr)
    {
        m_mainViewModel = new MainViewModel{this};
        m_mainViewModel->setEngineSpeed(m_machine->engine()->engineSpeed());
        m_mainViewModel->setVehicleSpeed(m_machine->engine()->vehicleSpeed());
    }
    return m_mainViewModel;
}
