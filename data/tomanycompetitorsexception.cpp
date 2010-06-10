#include "tomanycompetitorsexception.h"
#include <QObject>
#include <QString>

ToManyCompetitorsException::ToManyCompetitorsException()
{
}

const char* ToManyCompetitorsException::what() const throw()
{
    return QObject::tr("Group size limit reached. Add a substitute or change group type.").toStdString().c_str();
}
