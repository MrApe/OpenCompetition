#include "competitor.h"

Competitor::Competitor(const QString& name,
                       const unsigned int birth,
                       genderType gender):
        AbstractPerson(name),
        m_birth(birth),
        m_gender(gender)
{
}

QDomElement Competitor::toDomElement(QDomDocument *parentDocument)
{
    QDomElement competitor = parentDocument->createElement("competitor");
    competitor.setAttribute("name",m_name);
    competitor.setAttribute("birth",m_birth);
    competitor.setAttribute("gender",m_gender?"male":"female");

    return competitor;
}
