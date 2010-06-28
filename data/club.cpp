#include "club.h"

Club::Club(const QString &name):
        m_name(name)
{
}

bool Club::operator ==(const Club& other) const
{
    return m_name==other.getName();
}

bool Club::operator !=(const Club& other) const
{
    return m_name!=other.getName();
}

bool Club::operator <(const Club& right) const
{
    return m_name < right.getName();
}

bool Club::operator >(const Club& right) const
{
    return m_name > right.getName();
}


QDomElement Club::toDomElement(QDomDocument *parentDocument)
{
    QDomElement clubElement = parentDocument->createElement("club");
    clubElement.setAttribute("name",m_name);

    return clubElement;
}
