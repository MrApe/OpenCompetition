#include <QObject>
#include <QStringList>
#include "judge.h"

QString Judge::scoreTypeToString(const scoreType &score)
{
    switch (score){
    case ARTISTIC: return QObject::tr("Artistic");
    case EXECUTION: return QObject::tr("Execution");
    case DIFFICULTY: return QObject::tr("Difficulty");
    case CHAIR: return QObject::tr("Chair");
    case SUPERIOR: return QObject::tr("Superior");
    case ASSISTANT: return QObject::tr("Assistant");
    case LINE: return QObject::tr("Line");
    default: return QObject::tr("NONE"); //should not be reached
    }
}

Judge::scoreType Judge::stringToScoreType(const QString &scoreString)
{
    if (scoreString == QObject::tr("Artistic")) return ARTISTIC;
    if (scoreString == QObject::tr("Execution")) return EXECUTION;
    if (scoreString == QObject::tr("Difficulty")) return DIFFICULTY;
    if (scoreString == QObject::tr("Chair")) return CHAIR;
    if (scoreString == QObject::tr("Superior")) return SUPERIOR;
    if (scoreString == QObject::tr("Assistant")) return ASSISTANT;
    if (scoreString == QObject::tr("Line")) return LINE;
    return NONE;
}

QString Judge::brevetTypeToString(const brevetType &brevet)
{
    switch (brevet){
    case LTV: return QObject::tr("LTV");
    case DTB: return QObject::tr("DTB");
    case FIG4: return QObject::tr("FIG4");
    case FIG3: return QObject::tr("FIG3");
    case FIG2: return QObject::tr("FIG2");
    case FIG1: return QObject::tr("FIG1");
    default: return QObject::tr("NO");
    }
}

Judge::brevetType Judge::stringToBrevetType(const QString &brevetString)
{
    if (brevetString == QObject::tr("LTV")) return LTV;
    if (brevetString == QObject::tr("DTB")) return DTB;
    if (brevetString == QObject::tr("FIG4")) return FIG4;
    if (brevetString == QObject::tr("FIG3")) return FIG3;
    if (brevetString == QObject::tr("FIG2")) return FIG2;
    if (brevetString == QObject::tr("FIG1")) return FIG1;
    return NO;
}

QString Judge::poolListToString(QList<scoreType> pool)
{
    QString poolString;
    poolString.append("(");
    for (int i =0; i < pool.size(); i++)
    {
        poolString.append(scoreTypeToString(pool.at(i)));
        if (i < pool.size()-1) poolString.append(", ");
    }
    poolString.append(")");
    return poolString;
}

Judge::Judge(const QString &name,
             brevetType brevet):
    AbstractPerson(name),
    m_brevet(brevet),
    m_pools()
{
}

Judge::Judge():
        AbstractPerson(QObject::tr("NO_NAME")),
        m_brevet(NO),
        m_pools()
{
}

const QString Judge::toString()
{
    QString judge;
    judge.append(m_name);
    judge.append(", ");
    judge.append(brevetTypeToString(m_brevet));
    judge.append(", (");
    for (int i =0; i < m_pools.size(); i++)
    {
        judge.append(scoreTypeToString(m_pools.at(i)));
        if (i < m_pools.size()-1) judge.append(", ");
    }
    judge.append(")");
    return judge;
}

void Judge::addPool(scoreType pool)
{
    if (pool == ARTISTIC || pool == EXECUTION || pool == DIFFICULTY || pool == CHAIR)
    {
        if (!m_pools.contains(pool)) m_pools.append(pool);
    }
}

void Judge::removePool(scoreType pool)
{
    m_pools.removeAll(pool);
}


bool Judge::operator ==(const Judge& other) const
{
    return (m_name == other.getName() &&
            m_brevet == other.getBrevet() &&
            m_pools == other.getPools());
}

QDomElement Judge::toDomElement(QDomDocument *parentDocument)
{
    QDomElement judgeElement = parentDocument->createElement("judge");
    judgeElement.setAttribute("name",m_name);
    judgeElement.setAttribute("brevet", brevetTypeToString(m_brevet));

    QString poolString;
    for (int i  = 0; i < m_pools.size(); i++)
    {
        poolString.append(scoreTypeToString(m_pools.at(i)));
        if (i < m_pools.size()-1) poolString.append(",");
    }

    judgeElement.setAttribute("pools",poolString);

    return judgeElement;
}

void Judge::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "judge")
    {
        m_name = element.attribute("name","");
        QStringList poolsList = element.attribute("pools","NONE").split(",");
        for (QStringList::iterator i = poolsList.begin(); i != poolsList.end(); i++)
        {
            addPool(stringToScoreType(*i));
        }
        m_brevet = stringToBrevetType(element.attribute("brevet","NONE"));
    }
}
