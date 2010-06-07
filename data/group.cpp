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

Group::Group(const std::vector<Competitor>& competitors,
             const categorieType categorie,
             const Club& cl):
        m_competitors(competitors),
        m_categorie(categorie),
        m_club(cl)
{

}

void Group::addCompetitor(Competitor comp) throw (ToManyCompetitorsException){
    if (m_competitors.size() == 6) {
        throw new ToManyCompetitorsException();
    } else {
            m_competitors.push_back(comp);
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
