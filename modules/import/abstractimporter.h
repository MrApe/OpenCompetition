#ifndef ABSTRACTIMPORTER_H
#define ABSTRACTIMPORTER_H

#include "QStringList"

class AbstractImporter
{
public:
    AbstractImporter();
    ~AbstractImporter();

    void importFiles();

private:
    QStringList* m_Files;
};

#endif // ABSTRACTIMPORTER_H
