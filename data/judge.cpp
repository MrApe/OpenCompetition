#include <QObject>
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

Judge::Judge(const QString &name,
             scoreType score,
             brevetType brevet):
    AbstractPerson(name),
    m_score(score),
    m_brevet(brevet)
{
}

Judge::Judge():
        AbstractPerson(QObject::tr("UNNAMED")),
        m_score(NONE),
        m_brevet(NO)
{
}

QDomElement Judge::toDomElement(QDomDocument *parentDocument)
{
    QDomElement judgeElement = parentDocument->createElement("judge");
    judgeElement.setAttribute("name",m_name);
    judgeElement.setAttribute("score",scoreTypeToString(m_score));
    judgeElement.setAttribute("brevet", brevetTypeToString(m_brevet));

    return judgeElement;
}

void Judge::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "judge")
    {
        m_name = element.attribute("name","");
        m_score = stringToScoreType(element.attribute("score","NONE"));
        m_brevet = stringToBrevetType(element.attribute("brevet","NONE"));
    }
}
