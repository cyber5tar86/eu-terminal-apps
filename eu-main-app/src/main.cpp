// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#include <memory>

#include <QGuiApplication>

#include "machine_creator.h"
#include "business_logic.h"
#include "hmi_creator.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Q_INIT_RESOURCE(hmi);

    std::shared_ptr<Machine> machine{createMachine(Machine::Configuration::Simulator)};
    std::shared_ptr<BusinessLogic> businessLogic{new BusinessLogic{machine}};
    std::shared_ptr<Hmi> hmi{createHmi(Hmi::Configuration::Qt)};

    hmi->initialize("BusinessLogic", businessLogic.get());

    return app.exec();
}
