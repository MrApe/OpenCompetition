#ifndef SCORE_H
#define SCORE_H

#include "data/abstractXMLElement.h"
#include "data/judge.h"
#include <QList>

class Score : public AbstractXMLElement
{
public:
    Score();
    Score(Judge::scoreType type, Judge judge, double value);

    QDomElement toDomElement(QDomDocument *parentDocument);

    void readFromDomElement(QDomElement &element);

    const Judge& getJudge() const {return m_judge;}
    double getValue() const {return m_value;}
    Judge::scoreType getType() const {return m_type;}

private:
    Judge::scoreType m_type;
    Judge m_judge;
    double m_value;
};

#endif // SCORE_H
