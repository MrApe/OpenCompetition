#ifndef GROUP_H
#define GROUP_H

#include "vector"
#include "competitor.h"
#include "club.h"
#include "tomanycompetitorsexception.h"
#include "abstractXMLElement.h"

class Group : public AbstractXMLElement
{
public:
    enum categorieType{
        INDIVIDUAL_MEN,
        INDIVIDUAL_WOMEN,
        MIXED_PAIR,
        PAIR_TRIO,
        GROUP
    };

    static QString categorieToString(const categorieType categorie);
    static categorieType categorieFromString(const QString& catAsString);

    Group(const std::vector<Competitor>& competitors,
          const categorieType categorie,
          const Club& cl);

    Group(const Group& other);

    bool operator ==(const Group& other) const;
    bool operator!=(const Group& other) const;

    QString toString();

    /*!
      This method adds a competitor to the group. It throws an exception is the group is full.
      @param comp The competitor to be added.
      @throw ToManyCompetitorsException Thrown if the group has to many member.
      */
    void addCompetitor(Competitor comp) throw (ToManyCompetitorsException);
    /*!
      This method tries to guess the category type. However, it only counts the male and female member and returns what it thinks to be the best type.
      @return Type of the group.
      */
    categorieType guessType();

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);
    /*!
      This method checks if the group contains the given competitior.
      @param competitor Competitor to find.
      @return True is the competitor is part of the group. False otherwise.
      */
    bool contains(const Competitor& competitor);


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
