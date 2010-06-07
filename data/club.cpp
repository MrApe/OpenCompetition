#include "club.h"

Club::Club(const QString &name):
        m_name(name)
{
}

QDomElement Club::toDomElement(QDomDocument *parentDocument)
{
    QDomElement clubElement = parentDocument->createElement("club");
    clubElement.setAttribute("name",m_name);

    return clubElement;
}
