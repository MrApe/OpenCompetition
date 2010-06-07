#ifndef COMPETITOR_H
#define COMPETITOR_H

#include "abstractperson.h"
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
               genderType gender);

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*
     * Inline getter and setter
     */
    inline void setGender(const genderType& gender){
        m_gender = gender;
    }
    inline void setBirth(unsigned int const birth){
        m_birth = birth;}
    inline genderType getGender() const {
        return m_gender;}
    inline unsigned int getBirth() const{
        return m_birth;}


private:
    unsigned int m_birth;
    genderType m_gender;

};

#endif // COMPETITOR_H
