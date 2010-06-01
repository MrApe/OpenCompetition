#include "group.h"

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