#ifndef TEXTIMPORTER_H
#define TEXTIMPORTER_H

#include <QString>
#include <QFile>
#include "data/competition.h"
#include "modules/import/abstractimporter.h"

class TextImporter : public AbstractImporter
{
public:
    TextImporter(const QString& filter);

    virtual void importFile(const QString& fileName, Competition* target, QString* logMessage=0) throw (FileNotOpenedException);

private:
    void parseText(QFile& file, Competition* target,QString* logMessage);
};

#endif // TEXTIMPORTER_H
