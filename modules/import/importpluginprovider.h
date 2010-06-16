#ifndef IMPORTPLUGINPROVIDER_H
#define IMPORTPLUGINPROVIDER_H

#include "abstractimporter.h"
#include "vector"

class ImportPluginProvider
{
public:
    ImportPluginProvider();
    ~ImportPluginProvider();

    void addPlugin(AbstractImporter* importPlugin);
    AbstractImporter* getPluginFor(const QString& fielExt);

private:
    QList<AbstractImporter*> m_plugins;

};

#endif // IMPORTPLUGINPROVIDER_H
