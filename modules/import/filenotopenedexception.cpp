#include <QObject>
#include <QString>
#include "filenotopenedexception.h"

FileNotOpenedException::FileNotOpenedException(const char *filename):
        m_filename(filename)
{
}

const char* FileNotOpenedException::what() const throw()
{
    return QObject::tr("Opening file failed. It may not exist or is in use by another program.").toStdString().c_str();
}
