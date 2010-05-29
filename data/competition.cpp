#include "competition.h"

Competition::Competition(const QString &name,
                         const QDate &date,
                         const QTime &time,
                         JudgesPanel judgesPanel,
                         std::vector<Group>starter) :
    m_name(name),
    m_date(date),
    m_time(time),
    m_judgesPanel(judgesPanel),
    m_starter(starter)
{
}


