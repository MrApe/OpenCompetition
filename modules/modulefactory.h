#ifndef MODULEFACTORY_H
#define MODULEFACTORY_H

#include <QObject>
#include <QMap>
#include <QString>
#include "modules/abstractmodule.h"

class ModuleFactory : public QObject
{ 

    Q_OBJECT

public:
    static ModuleFactory& getInstance();
    static void destroy();

    /*!
      This function adds a module to the Factory.
      If there is an existing module of this type
      it will be replaced by the new one.
      */
    void addModule(AbstractModule* newModule);

    AbstractModule* getModuleByName(const QString name);

private:
    ModuleFactory(QObject * parent = 0);
    ModuleFactory(const ModuleFactory& other);
    ~ModuleFactory();

    static ModuleFactory* instance;
    QMap<QString, AbstractModule* > m_moduleList;
};

#endif // MODULEFACTORY_H
