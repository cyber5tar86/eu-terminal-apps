#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "qt_hmi.h"

struct QtHmi::Impl
{
    QQmlApplicationEngine m_appEngine;
};

struct HmiConfiguration
{
    QString name;
    QObject *value;
};

QtHmi::QtHmi()
    : Hmi{}
    , m_impl{new Impl{}}
{
    //Q_INIT_RESOURCE(resources);
}

QtHmi::~QtHmi()
{
}

void QtHmi::initialize(const std::string& name, void *value)
{
    m_impl->m_appEngine.rootContext()->setContextProperty(QString::fromStdString(name), (QObject *)value);
    m_impl->m_appEngine.load(u"qrc:/main.qml"_qs);
}