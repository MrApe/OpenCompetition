#include <QObject>
#include "group.h"

QString Group::categorieToString(categorieType categorie)
{
    switch (categorie) {
    case INDIVIDUAL_MEN: return QObject::QObject::tr("IM");
    case INDIVIDUAL_WOMEN:return QObject::tr("IW");
    case MIXED_PAIR: return QObject::tr("Mixed");
    case PAIR_TRIO: return QObject::tr("Pair/Trio");
    case GROUP: return QObject::tr("Group");
    default: return ""; //should not be reached
    }
}

Group::categorieType Group::categorieFromString(const QString &catAsString)
{
    if (catAsString == QObject::tr("IM")) return INDIVIDUAL_MEN;
    if (catAsString == QObject::tr("IW")) return INDIVIDUAL_WOMEN;
    if (catAsString == QObject::tr("Mixed")) return MIXED_PAIR;
    if (catAsString == QObject::tr("Pair/Trio")) return PAIR_TRIO;
    if (catAsString == QObject::tr("Group")) return GROUP;
    return GROUP;
}

Group::Group():
        m_competitors(),
        m_categorie(),
        m_club(QObject::tr("Not Set"))
{

}

Group::Group(const std::vector<Competitor>& competitors,
             const categorieType categorie,
             const Club& cl):
        m_competitors(competitors),
        m_categorie(categorie),
        m_club(cl)
{
}

Group::Group(const Group &other):
        m_competitors(),
        m_categorie(other.getType()),
        m_club(other.getClub().getName())
{
    for (unsigned int i = 0; i < other.getCompetitors().size(); i++)
    {
        m_competitors.push_back(Competitor(other.getCompetitors().at(i).getName(),
                                           other.getCompetitors().at(i).getBirth(),
                                           other.getCompetitors().at(i).getGender()));
    }
}

bool Group::operator ==(const Group& other) const
{
    for (unsigned int i = 0; i<m_competitors.size(); i++)
    {
        if (m_competitors.at(i) != other.getCompetitors().at(i))
        {
            return false;
        }
    }
    if (m_club != other.getClub()) return false;
    if (m_categorie != other.getType()) return false;

    return true;
}

bool Group::operator!=(const Group& other) const
{
    return !(*this==other);
}

bool Group::contains(const Competitor &competitor)
{
    for (std::vector<Competitor>::iterator i = m_competitors.begin(); i != m_competitors.end(); i++)
    {
        if ((*i)==competitor) return true;
    }
    return false;
}

QString Group::toString()
{
    QString output;
    output.append(QObject::tr("Club: ")+m_club.getName());
    output.append(QObject::tr("Categorie: ")+Group::categorieToString(m_categorie));
    output.append(QObject::tr("Starter: "));
    for (unsigned int i = 0; i<m_competitors.size(); i++)
    {
       output.append(m_competitors.at(i).getName());
    }
    return output;
}

void Group::addCompetitor(Competitor comp) throw (ToManyCompetitorsException){
    if (m_competitors.size() == 6) {
        throw new ToManyCompetitorsException();
    } else {
        if (!contains(comp)){
            m_competitors.push_back(comp);
        }
    }
}

Group::categorieType Group::guessType(){
    unsigned int size = m_competitors.size();

    switch (size) {
    case 1 : return m_competitors.at(1).getGender() == Competitor::MALE ? INDIVIDUAL_MEN : INDIVIDUAL_WOMEN;
    case 2 : return (m_competitors.at(1).getGender() == Competitor::MALE ||
                     m_competitors.at(2).getGender() == Competitor::MALE) ? MIXED_PAIR : PAIR_TRIO;
    case 3 : return PAIR_TRIO;
    default : return GROUP;
    }
}

QDomElement Group::toDomElement(QDomDocument *parentDocument)
{
    QDomElement groupElement = parentDocument->createElement("group");
    groupElement.setAttribute("categorie",categorieToString(m_categorie));
    groupElement.appendChild(m_club.toDomElement(parentDocument));
    QDomElement competitorsElement = parentDocument->createElement("competitors");
        groupElement.appendChild(competitorsElement);

        std::vector<Competitor>::iterator it;
        for (it = m_competitors.begin();it != m_competitors.end();it++)
        {
            competitorsElement.appendChild(it->toDomElement(parentDocument));
        }

    return groupElement;
}
