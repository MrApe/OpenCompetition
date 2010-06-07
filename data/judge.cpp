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
    default: return ""; //should not be reached
    }
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
    default: return QObject::tr("NONE");
    }
}

Judge::Judge(const QString &name,
             scoreType score,
             brevetType brevet):
    AbstractPerson(name),
    m_score(score),
    m_brevet(brevet)
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
