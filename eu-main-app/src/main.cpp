// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#include <memory>

#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "machine_creator.h"
#include "business_logic.h"

// The main function creates a machine object and a business logic object and connects the business
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Create a machine object and a business logic object.
    std::shared_ptr<Machine> machine{createMachine(Machine::Configuration::Simulator)};
    std::shared_ptr<BusinessLogic> businessLogic{new BusinessLogic{machine}};

    QQmlApplicationEngine appEngine;

    // Set the business logic object as a context property for QML.
    appEngine.rootContext()->setContextProperty("BusinessLogic", businessLogic.get());

    // Load the main QML file.
    appEngine.load(u"qrc:/main.qml"_qs);

    return app.exec();
}
