#include "competitor.h"

Competitor::Competitor(const QString& name,
                       const unsigned int birth,
                       genderType gender):
        AbstractPerson(name),
        m_birth(birth),
        m_gender(gender)
{
}

bool Competitor::operator ==(const Competitor& other) const
{
    return (m_name == other.getName() &&
            m_birth == other.getBirth() &&
            m_gender == other.getGender());
}

bool Competitor::operator !=(const Competitor& other) const
{
    return !(*this==other);
}

QDomElement Competitor::toDomElement(QDomDocument *parentDocument)
{
    QDomElement competitor = parentDocument->createElement("competitor");
    competitor.setAttribute("name",m_name);
    competitor.setAttribute("birth",m_birth);
    competitor.setAttribute("gender",m_gender?"male":"female");

    return competitor;
}

void Competitor::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "competitor")
    {
        m_name = element.attribute("name","");
        m_birth = element.attribute("birth","").toInt();
        m_gender = element.attribute("gender","male")=="male"?MALE:FEMALE;
    }
}
