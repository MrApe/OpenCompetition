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
    AbstractImporter(const QString& filter);
    virtual ~AbstractImporter();

    virtual const std::vector<Group> importFile(const QString& file) throw (FileNotOpenedException) = 0;

    /*!
     * Inline getter
     */
    inline const QString& getFilter() const {
        return m_filter;}

private:
    QString m_filter;
};

#endif // ABSTRACTIMPORTER_H
