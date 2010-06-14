#ifndef TEXTIMPORTER_H
#define TEXTIMPORTER_H

#include <QString>
#include <QFile>
#include <vector>
#include "modules/import/abstractimporter.h"

class TextImporter : public AbstractImporter
{
public:
    TextImporter(const QString& filter);

    virtual const std::vector<Group> importFile(const QString& fileName) throw (FileNotOpenedException);

private:
    std::vector<Group> parseText(QFile& file);
};

#endif // TEXTIMPORTER_H
