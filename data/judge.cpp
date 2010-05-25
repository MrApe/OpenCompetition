#include "judge.h"

Judge::Judge(const QString &name,
             scoreType score,
             brevetType brevet):
    AbstractPerson(name),
    m_score(score),
    m_brevet(brevet)
{
}
