#include "judgespanel.h"

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

