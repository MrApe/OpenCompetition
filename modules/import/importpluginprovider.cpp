#include "importpluginprovider.h"

ImportPluginProvider::ImportPluginProvider()
{
}

ImportPluginProvider::~ImportPluginProvider(){
    for (unsigned int i = 0;i < m_plugins.size();i++){
        delete m_plugins.at(i);
    }
}

void ImportPluginProvider::addPlugin(AbstractImporter* importPlugin)
{
    if (getPluginFor(importPlugin->getFilter()) == NULL) {
        m_plugins.push_back(importPlugin);
    }
}

AbstractImporter* ImportPluginProvider::getPluginFor(const QString& fileExt) {
    AbstractImporter* ret = NULL;

    unsigned int i = 0;
    while (ret==NULL && i<m_plugins.size())
    {
        ret = (m_plugins.at(i)->getFilter() == fileExt) ? (m_plugins.at(i)) : NULL;
        i++;
    }

    return ret;
}


