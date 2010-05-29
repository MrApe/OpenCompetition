#ifndef GROUP_H
#define GROUP_H

#include "vector"
#include "competitor.h"
#include "club.h"
#include "tomanycompetitorsexception.h"

class Group
{
public:
    enum categorieType{
        INDIVIDUAL_MEN,
        INDIVIDUAL_WOMEN,
        MIXED_PAIR,
        PAIR_TRIO,
        GROUP
    };

    Group(const std::vector<Competitor>& competitors,
          const categorieType categorie,
          const Club& cl);

    void addCompetitor(Competitor comp) throw (ToManyCompetitorsException);
    categorieType guessType();


    /*
     * Inline getter and setter
     */
    inline void setCompetitors(const std::vector<Competitor>& competitors){
        m_competitors = competitors;
    }
    inline void setType(const categorieType categorie){
        m_categorie = categorie;
    }
    inline void setClub(const Club& cl){
        m_club = cl;
    }
    inline const std::vector<Competitor>& getCompetitors() const {
        return m_competitors;
    }
    inline categorieType getType() const{
        return m_categorie;
    }
    inline const Club& getClub() const{
        return m_club;
    }


private:
    std::vector<Competitor> m_competitors;
    categorieType m_categorie;
    Club m_club;

};

#endif // GROUP_H
