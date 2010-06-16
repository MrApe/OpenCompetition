#ifndef TEXTIMPORTER_H
#define TEXTIMPORTER_H

#include <QString>
#include <QFile>
#include "modules/import/abstractimporter.h"

class TextImporter : public AbstractImporter
{
public:
    TextImporter(const QString& filter);

    virtual const QList<Group> importFile(const QString& fileName) throw (FileNotOpenedException);

private:
    QList<Group> parseText(QFile& file);
};

#endif // TEXTIMPORTER_H
