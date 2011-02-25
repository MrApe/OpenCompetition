#ifndef GROUP_H
#define GROUP_H

#include "vector"
#include "data/competitor.h"
#include "data/club.h"
#include "data/score.h"
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

    enum ageType{
        NATIONAL_DEVELOPMENT,
        AG_ONE,
        AG_TWO,
        SENIORS,
        UNSET
    };

    static QString categorieToString(const categorieType categorie);
    static QString ageToString(const ageType age);
    static categorieType categorieFromString(const QString& catAsString);
    static ageType ageFromString(const QString& ageAsString);

    Group();

    Group(const QList<Competitor>& competitors,
          ageType age,
          categorieType categorie,
          const Club& cl);

    Group(const Group& other);

    bool operator ==(const Group& other) const;
    bool operator!=(const Group& other) const;

    QString toString() const;

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
      This method tries to determine the age group out of the groups member.
      @return The age group of the group.
      */
    ageType guessAge();
    /*!
      This is an overloaded function for an indivudual with the given year of birth.
      @param birth Year of birth.
      @return The age group of the given year.
      */
    static ageType guessAge(int birth);

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);
    /*!
      This method reads data into the group out of an xml element.
      */
    virtual void readFromDomElement(QDomElement &element);
    /*!
      This method checks if the group contains the given competitior.
      @param competitor Competitor to find.
      @return True is the competitor is part of the group. False otherwise.
      */
    bool contains(const Competitor& competitor) const;

    /*!
      This method creates a unique hash for this group.
      */
    QString hash() const;

    /*!
      This method looks for a score from a decent judge.
      @param judge The judge the score was given from.
      @return the score.
      */
    double getScoreFromJudge(const Judge& judge);

    /*!
      This method sets the score for a given Judge.
      @param judge The judge.
      @param score The score.
      */
    void setScoreForJudge(const Judge& judge, double score);

    /*!
      This method calculates the score for the current goup and returns it.
      @return The final score.
      */
    double getFinalScore();

    /*!
      This method checks if the group is male.
      @return True is the group has only male competitors.
      */
    bool isMale() const;


    /*
     * Inline getter and setter
     */
    inline void setCompetitors(const QList<Competitor>& competitors){m_competitors = competitors;}
    inline void setAge(const ageType age){m_age = age;}
    inline void setType(const categorieType categorie){m_categorie = categorie;}
    inline void setClub(const Club& cl){m_club = cl;}
    inline const QList<Competitor>& getCompetitors() const{return m_competitors;}
    inline QList<Competitor>& getCompetitors(){return m_competitors;}
    inline ageType getAge() const{return m_age;}
    inline categorieType getType() const{return m_categorie;}
    inline const Club& getClub() const{return m_club;}
    inline Club& getClub() {return m_club;}
    inline const QList<Score>& getScores()const {return m_scores;}
    inline QList<Score>& getScores() {return m_scores;}


private:
    QList<Competitor> m_competitors;
    ageType m_age;
    categorieType m_categorie;
    Club m_club;
    QList<Score> m_scores;
};

#endif // GROUP_H
