#include "judgespanel.h"

JudgesPanel::JudgesPanel():
        m_artisticJudges(),
        m_executionJudges(),
        m_difficultyJudges(),
        m_superiorJury(),
        m_lineJudges(),
        m_chairJudge(),
        m_assistantJudge()
{

}

JudgesPanel::JudgesPanel(QList<Judge> artisticJudges,
                         QList<Judge> executionJudges,
                         QList<Judge> difficultyJudges,
                         QList<Judge> superiorJury,
                         QList<Judge> lineJudges,
                         Judge chairJudge,
                         Judge assistantJudge):
    m_artisticJudges(artisticJudges),
    m_executionJudges(executionJudges),
    m_difficultyJudges(difficultyJudges),
    m_superiorJury(superiorJury),
    m_lineJudges(lineJudges),
    m_chairJudge(chairJudge),
    m_assistantJudge(assistantJudge)
{
}

int JudgesPanel::size() const
{
    int s = m_artisticJudges.size();
    s += m_executionJudges.size();
    s += m_difficultyJudges.size();
    s += m_superiorJury.size();
    s += m_lineJudges.size();
    s += 2; //chair + Assistant
    return s;
}

QDomElement JudgesPanel::toDomElement(QDomDocument *parentDocument)
{
    QDomElement judgesPanelElement = parentDocument->createElement("judgespanel");
    QDomElement artisticJudgesElement = parentDocument->createElement("artisticjudges");
    judgesPanelElement.appendChild(artisticJudgesElement);
    QList<Judge>::iterator i;
    for (i = m_artisticJudges.begin(); i != m_artisticJudges.end(); i++)
    {
        artisticJudgesElement.appendChild(i->toDomElement(parentDocument));
    }

    QDomElement executionJudgesElement = parentDocument->createElement("executionjudges");
    judgesPanelElement.appendChild(executionJudgesElement);
    for (i = m_executionJudges.begin(); i!= m_executionJudges.end(); i++)
    {
        executionJudgesElement.appendChild(i->toDomElement(parentDocument));
    }

    QDomElement difficultyJudgesElement = parentDocument->createElement("difficultyjudges");
    judgesPanelElement.appendChild(difficultyJudgesElement);
    for (i = m_difficultyJudges.begin(); i!= m_difficultyJudges.end(); i++)
    {
        difficultyJudgesElement.appendChild(i->toDomElement(parentDocument));
    }

    QDomElement superiorJuryElement = parentDocument->createElement("superiorjury");
    judgesPanelElement.appendChild(superiorJuryElement);
    for (i = m_superiorJury.begin(); i!= m_superiorJury.end(); i++)
    {
        superiorJuryElement.appendChild(i->toDomElement(parentDocument));
    }

    QDomElement lineJudgesElement = parentDocument->createElement("linejudges");
    judgesPanelElement.appendChild(lineJudgesElement);
    for (i = m_lineJudges.begin(); i!= m_lineJudges.end(); i++)
    {
        lineJudgesElement.appendChild(i->toDomElement(parentDocument));
    }

    QDomElement chairJudgeElement = parentDocument->createElement("chairjudge");
    judgesPanelElement.appendChild(chairJudgeElement);
    chairJudgeElement.appendChild(m_chairJudge.toDomElement(parentDocument));

    QDomElement assistantJudgeElement = parentDocument->createElement("assistantjudge");
    judgesPanelElement.appendChild(assistantJudgeElement);
    assistantJudgeElement.appendChild(m_assistantJudge.toDomElement(parentDocument));

    return judgesPanelElement;
}

void JudgesPanel::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "judgespanel")
    {
        QDomNode nextNode = element.firstChild();
        while (!nextNode.isNull())
        {
            QDomElement e = nextNode.toElement();
            if (!e.isNull())
            {
                if (e.tagName() == "artisticjudges")
                    extractJudgeFromXML(e,m_artisticJudges);
                if (e.tagName() == "executionjudges")
                    extractJudgeFromXML(e,m_executionJudges);
                if (e.tagName() == "difficultyjudges")
                    extractJudgeFromXML(e,m_difficultyJudges);
                if (e.tagName() == "superiorjury")
                    extractJudgeFromXML(e,m_superiorJury);
                if (e.tagName() == "linejudges")
                    extractJudgeFromXML(e,m_lineJudges);
                if (e.tagName() == "chairjudge")
                    extractJudgeFromXML(e,m_chairJudge);
                if (e.tagName() == "assistantjudge")
                    extractJudgeFromXML(e,m_assistantJudge);
            }
        }
    }
}

void JudgesPanel::extractJudgeFromXML(QDomElement& element, QList<Judge> &target)
{
    QDomNode aJudgeNode = element.firstChild();
    while (!aJudgeNode.isNull())
    {
        QDomElement aJudgeElement = aJudgeNode.toElement();
        if (!aJudgeElement.isNull())
        {
            Judge aJudge("Noname",Judge::ARTISTIC,Judge::LTV);
            aJudge.readFromDomElement(aJudgeElement);
            target.append(aJudge);
        }
    }
}

void JudgesPanel::extractJudgeFromXML(QDomElement& element, Judge &target)
{
    QDomNode aJudgeNode = element.firstChild();
    if (!aJudgeNode.isNull())
    {
        QDomElement aJudgeElement = aJudgeNode.toElement();
        if (!aJudgeElement.isNull())
        {
            target.readFromDomElement(aJudgeElement);
        }
    }
}
