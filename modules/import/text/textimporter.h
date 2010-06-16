#ifndef TEXTIMPORTER_H
#define TEXTIMPORTER_H

#include <QString>
#include <QFile>
#include <vector>
#include <QVector>
#include "modules/import/abstractimporter.h"

class TextImporter : public AbstractImporter
{
public:
    TextImporter(const QString& filter);

    virtual const std::vector<Group> importFile(const QString& fileName) throw (FileNotOpenedException);

private:
    QVector<Group> parseText(QFile& file);
};

#endif // TEXTIMPORTER_H
