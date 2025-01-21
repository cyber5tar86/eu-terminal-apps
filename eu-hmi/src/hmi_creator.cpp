#include <QtGlobal>

#include "hmi_creator.h"
#include "private/qt_hmi.h"

Hmi *createHmi(Hmi::Configuration configuration)
{
    switch (configuration)
    {
    case Hmi::Configuration::Qt:
        return new QtHmi{};
    default:
        Q_ASSERT_X(false, __PRETTY_FUNCTION__, "Unsupported HMI configuration!");
        return nullptr;
    }
}
