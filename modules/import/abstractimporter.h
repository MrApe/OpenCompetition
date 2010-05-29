#ifndef ABSTRACTIMPORTER_H
#define ABSTRACTIMPORTER_H

#include "vector"
#include "QString"
#include "QStringList"
#include "data/group.h"
#include "filenotopenedexception.h"

class AbstractImporter
{
public:
    AbstractImporter();
    ~AbstractImporter();

    virtual const std::vector<Group>& importFiles(const QStringList& files) throw (FileNotOpenedException) = 0;
    virtual const std::vector<Group>& importFile(const QString& file) throw (FileNotOpenedException) = 0;
};

#endif // ABSTRACTIMPORTER_H
