#include "competitor.h"

Competitor::Competitor(const QString& name,
                       const unsigned int birth,
                       genderType gender):
        AbstractPerson(name),
        m_birth(birth),
        m_gender(gender)
{
}
