#include "modulefactory.h"

ModuleFactory* ModuleFactory::instance = NULL;

ModuleFactory& ModuleFactory::getInstance()
{
    if (!instance)
    {
        instance = new ModuleFactory();
    }
    return *instance;
}

void ModuleFactory::destroy()
{
    delete instance;
    instance = NULL;
}

void ModuleFactory::addModule(AbstractModule *newModule)
{
    m_moduleList[newModule->getName()] = newModule;
}

AbstractModule* ModuleFactory::getModuleByName(QString name)
{
    return m_moduleList[name];
}

ModuleFactory::ModuleFactory(QObject* parent):
    QObject(parent){}

ModuleFactory::ModuleFactory(const ModuleFactory &other):
    QObject(other.parent()){}

ModuleFactory::~ModuleFactory(){}
