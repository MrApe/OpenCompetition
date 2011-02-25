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

void ModuleFactory::closeAllModules()
{
    QList<QString>::iterator mod;
    for (mod = m_moduleList.keys().begin(); mod != m_moduleList.keys().end(); mod++)
    {
        getModuleByName(*mod)->close();
    }
}

ModuleFactory::ModuleFactory(QObject* parent):
    QObject(parent){}

ModuleFactory::ModuleFactory(const ModuleFactory &other):
    QObject(other.parent()){}

ModuleFactory::~ModuleFactory(){}
