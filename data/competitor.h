#ifndef COMPETITOR_H
#define COMPETITOR_H

#include "abstractperson.h"

class Competitor : public AbstractPerson
{
public:
    enum genderType{
        MALE,
        FEMALE
    };

    Competitor(const QString& name,
               const unsigned int birth,
               genderType gender);

    /*
     * Inline getter and setter
     */
    inline void setGender(const genderType& gender){
        m_gender = gender;
    }
    inline void setBirth(unsigned int const birth){
        m_birth = birth;};
    inline const genderType getGender() const {
        return m_gender;
    }
    inline unsigned int getBirth() const{
        return m_birth;}


private:
    unsigned int m_birth;
    genderType m_gender;

};

#endif // COMPETITOR_H
