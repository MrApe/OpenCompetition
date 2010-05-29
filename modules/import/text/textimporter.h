#ifndef TEXTIMPORTER_H
#define TEXTIMPORTER_H

#include "QString"
#include "modules/import/abstractimporter.h"

class TextImporter : public AbstractImporter
{
public:
    TextImporter();

    virtual const std::vector<Group>& importFiles(const QStringList& files) throw (FileNotOpenedException);
    virtual const std::vector<Group>& importFile(const QString& file) throw (FileNotOpenedException);

private:
    std::vector<Group> parseText(QString text);

    static const QString m_filter;
};

#endif // TEXTIMPORTER_H
