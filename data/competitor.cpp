#include "competitor.h"

Competitor::Competitor(const QString& name,
                       const unsigned int birth,
                       genderType gender,
                       const Club& club):
        AbstractPerson(name),
        m_birth(birth),
        m_gender(gender),
        m_club(club)
{
}

Competitor::Competitor(const Competitor &other):
        AbstractPerson(other.getName()),
        AbstractXMLElement(),
        m_birth(other.getBirth()),
        m_gender(other.getGender()),
        m_club(other.getClub())
{
}

Competitor& Competitor::operator =(const Competitor& other)
{
    setName(other.getName());
    m_birth = other.getBirth();
    m_gender = other.getGender();
    m_club = other.getClub();
    return *this;
}

bool Competitor::equals(const Competitor &other) const
{
    return *this == other;
}

bool Competitor::operator ==(const Competitor& other) const
{
    return (m_name == other.getName() &&
            m_birth == other.getBirth() &&
            m_gender == other.getGender() &&
            m_club == other.getClub());
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
    competitor.setAttribute("gender",m_gender==MALE?"male":"female");
    QDomElement clubElement = m_club.toDomElement(parentDocument);
    competitor.appendChild(clubElement);

    return competitor;
}

void Competitor::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "competitor")
    {
        m_name = element.attribute("name","");
        m_birth = element.attribute("birth","").toInt();
        m_gender = element.attribute("gender","male")=="male"?MALE:FEMALE;

        QDomNode clubNode = element.firstChild();
        if (!clubNode.isNull())
        {
            QDomElement clubElement = clubNode.toElement();
            if (!clubElement.isNull())
            {
                m_club.readFromDomElement(clubElement);
            }
        }

    }
}
