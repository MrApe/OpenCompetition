#ifndef COMPETITOR_H
#define COMPETITOR_H

#include "abstractperson.h"
#include "data/club.h"
#include "abstractXMLElement.h"

class Competitor : public AbstractPerson, public AbstractXMLElement
{
public:
    enum genderType{
        MALE,
        FEMALE
    };

    Competitor(const QString& name,
               const unsigned int birth,
               genderType gender,
               const Club& club);

    Competitor(const Competitor& other);

    bool equals(const Competitor& other) const;
    Competitor& operator=(const Competitor& other);
    bool operator ==(const Competitor& other) const;
    bool operator !=(const Competitor& other) const;

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*!
     This method reads starter data from an xml element.
     */
    virtual void readFromDomElement(QDomElement &element);

    /*
     * Inline getter and setter
     */
    inline void setGender(const genderType& gender){
        m_gender = gender;}
    inline void setBirth(unsigned int const birth){
        m_birth = birth;}
    inline void setClub(const Club& club){
        m_club = club;}
    inline genderType getGender() const {
        return m_gender;}
    inline int getBirth() const{
        return m_birth;}
    inline Club& getClub() const{
        return const_cast<Club&>(m_club);}


private:
    int m_birth;
    genderType m_gender;
    Club m_club;

};

#endif // COMPETITOR_H
