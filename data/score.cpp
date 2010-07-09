#include "score.h"

Score::Score():
        m_type(Judge::NONE),
        m_judge(),
        m_value(0.0)
{

}

Score::Score(Judge::scoreType type, Judge judge, double value):
        m_type(type),
        m_judge(judge),
        m_value(value)
{
}

QDomElement Score::toDomElement(QDomDocument *parentDocument)
{
    QDomElement scoreElement = parentDocument->createElement("score");
    scoreElement.setAttribute("type",Judge::scoreTypeToString(m_type));
    scoreElement.setAttribute("judge",m_judge.toString());
    scoreElement.setAttribute("value",QString::number(m_value,'f',4));

    return scoreElement;
}

void Score::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "score")
    {
        m_type = Judge::stringToScoreType(element.attribute("type",""));
        m_judge = Judge::judgeFromString(element.attribute("judge",""));
        m_value = element.attribute("value","").toDouble();
    }
}
