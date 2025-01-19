// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#pragma once

#include <memory>
#include <QObject>

#include "machine.h"
#include "main_view_model.h"


/*!
 * \brief The BusinessLogic class represents the business logic of the application. The business
 * logic connects the machine to the user interface.
 */
class BusinessLogic : public QObject
{
    // The Q_OBJECT macro is necessary for signals and slots.
    Q_OBJECT

    // The Q_PROPERTY macro defines a property that is accessible from QML.
    Q_PROPERTY(MainViewModel* mainViewModel READ mainViewModel CONSTANT)

public:
    /*!
     * Creates a new business logic object with the given \a machine and \a parent.
     */
    explicit BusinessLogic(std::shared_ptr<Machine> machine, QObject *parent = nullptr);

    /*!
     * Destroys the business logic object.
     */
    virtual ~BusinessLogic();

    /*!
     * Returns the main view model.
     */
    MainViewModel* mainViewModel();

private:
    std::shared_ptr<Machine> m_machine; //!< Pointer to the machine object.
    MainViewModel* m_mainViewModel{nullptr}; //!< Pointer to the main view model.
};
