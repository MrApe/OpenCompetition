#include "judgespanel.h"
#include <QObject>

JudgesPanel::JudgesPanel():
        m_artisticJudges(),
        m_executionJudges(),
        m_difficultyJudges(),
        m_superiorJury(),
        m_lineJudges(),
        m_chairJudges(),
        m_assistantJudges(),
        m_judgesPool()
{

}

JudgesPanel::JudgesPanel(QList<Judge> judgesPool):
        m_artisticJudges(),
        m_executionJudges(),
        m_difficultyJudges(),
        m_superiorJury(),
        m_lineJudges(),
        m_chairJudges(),
        m_assistantJudges(),
        m_judgesPool(judgesPool)
{

}

JudgesPanel::JudgesPanel(QList<Judge*> artisticJudges,
                         QList<Judge*> executionJudges,
                         QList<Judge*> difficultyJudges,
                         QList<Judge*> superiorJury,
                         QList<Judge*> lineJudges,
                         QList<Judge*> chairJudges,
                         QList<Judge*> assistantJudges):
    m_artisticJudges(artisticJudges),
    m_executionJudges(executionJudges),
    m_difficultyJudges(difficultyJudges),
    m_superiorJury(superiorJury),
    m_lineJudges(lineJudges),
    m_chairJudges(chairJudges),
    m_assistantJudges(assistantJudges),
    m_judgesPool()
{
    addJudgesToPoolFrom(&m_artisticJudges);
    addJudgesToPoolFrom(&m_executionJudges);
    addJudgesToPoolFrom(&m_difficultyJudges);
    addJudgesToPoolFrom(&m_superiorJury);
    addJudgesToPoolFrom(&m_lineJudges);
    addJudgesToPoolFrom(&m_chairJudges);
    addJudgesToPoolFrom(&m_assistantJudges);

}

void JudgesPanel::addJudgesToPoolFrom(QList<Judge *> *source)
{
    for (QList<Judge*>::iterator i = source->begin(); i != source->end(); i++){
        addJudgeToPool(*(*i));
    }
}

Judge* JudgesPanel::addJudgeToPool(Judge judge)
{
    if (!m_judgesPool.contains(judge))
    {
        m_judgesPool.append(judge);
    }
    return findJudgeInPool(judge);
}

void JudgesPanel::addJudgeTo(Judge judge, QList<Judge *> *to)
{
    Judge* judgePtr = addJudgeToPool(judge);
    if (!to->contains(judgePtr))
    {
        to->append(judgePtr);
    }
}

Judge* JudgesPanel::findJudgeInPool(Judge judge)
{
    for (QList<Judge>::iterator i = m_judgesPool.begin(); i != m_judgesPool.end(); i++)
    {
        if ((*i) == judge) return &(*i);
    }
    return NULL;
}

int JudgesPanel::size() const
{
    int s = m_artisticJudges.size();
    s += m_executionJudges.size();
    s += m_difficultyJudges.size();
    s += m_superiorJury.size();
    s += m_lineJudges.size();
    s += m_chairJudges.size();
    s += m_assistantJudges.size();
    return s;
}

int JudgesPanel::poolSize() const
{
   return m_judgesPool.size();
}

QDomElement JudgesPanel::toDomElement(QDomDocument *parentDocument)
{
    QDomElement judgesPanelElement = parentDocument->createElement("judgespanel");
    QDomElement judgesPoolElement = parentDocument->createElement("judgespool");
    judgesPanelElement.appendChild(judgesPoolElement);
    QList<Judge>::iterator i;
    for (i = m_judgesPool.begin(); i!= m_judgesPool.end(); i++)
    {
        judgesPoolElement.appendChild((*i).toDomElement(parentDocument));
    }

    QDomElement artisticJudgesElement = parentDocument->createElement("artisticjudges");
    judgesPanelElement.appendChild(artisticJudgesElement);
    QList<Judge*>::iterator judgePtrIt;
    for (judgePtrIt = m_artisticJudges.begin(); judgePtrIt != m_artisticJudges.end(); judgePtrIt++)
    {
        artisticJudgesElement.appendChild((*judgePtrIt)->toDomElement(parentDocument));
    }

    QDomElement executionJudgesElement = parentDocument->createElement("executionjudges");
    judgesPanelElement.appendChild(executionJudgesElement);
    for (judgePtrIt = m_executionJudges.begin(); judgePtrIt!= m_executionJudges.end(); judgePtrIt++)
    {
        executionJudgesElement.appendChild((*judgePtrIt)->toDomElement(parentDocument));
    }

    QDomElement difficultyJudgesElement = parentDocument->createElement("difficultyjudges");
    judgesPanelElement.appendChild(difficultyJudgesElement);
    for (judgePtrIt = m_difficultyJudges.begin(); judgePtrIt!= m_difficultyJudges.end(); judgePtrIt++)
    {
        difficultyJudgesElement.appendChild((*judgePtrIt)->toDomElement(parentDocument));
    }

    QDomElement superiorJuryElement = parentDocument->createElement("superiorjury");
    judgesPanelElement.appendChild(superiorJuryElement);
    for (judgePtrIt = m_superiorJury.begin(); judgePtrIt!= m_superiorJury.end(); judgePtrIt++)
    {
        superiorJuryElement.appendChild((*judgePtrIt)->toDomElement(parentDocument));
    }

    QDomElement lineJudgesElement = parentDocument->createElement("linejudges");
    judgesPanelElement.appendChild(lineJudgesElement);
    for (judgePtrIt = m_lineJudges.begin(); judgePtrIt!= m_lineJudges.end(); judgePtrIt++)
    {
        lineJudgesElement.appendChild((*judgePtrIt)->toDomElement(parentDocument));
    }

    QDomElement chairJudgesElement = parentDocument->createElement("chairjudges");
    judgesPanelElement.appendChild(chairJudgesElement);
    for (judgePtrIt = m_chairJudges.begin(); judgePtrIt!= m_chairJudges.end(); judgePtrIt++)
    {
        chairJudgesElement.appendChild((*judgePtrIt)->toDomElement(parentDocument));
    }

    QDomElement assistantJudgesElement = parentDocument->createElement("assistantjudges");
    judgesPanelElement.appendChild(assistantJudgesElement);
    for (judgePtrIt = m_assistantJudges.begin(); judgePtrIt!= m_assistantJudges.end(); judgePtrIt++)
    {
        assistantJudgesElement.appendChild((*judgePtrIt)->toDomElement(parentDocument));
    }

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
                if (e.tagName() == "judgespool")
                    extractJudgeFromXML(e);
                if (e.tagName() == "artisticjudges")
                    extractJudgeFromXML(e,&m_artisticJudges);
                if (e.tagName() == "executionjudges")
                    extractJudgeFromXML(e,&m_executionJudges);
                if (e.tagName() == "difficultyjudges")
                    extractJudgeFromXML(e,&m_difficultyJudges);
                if (e.tagName() == "superiorjury")
                    extractJudgeFromXML(e,&m_superiorJury);
                if (e.tagName() == "linejudges")
                    extractJudgeFromXML(e,&m_lineJudges);
                if (e.tagName() == "chairjudges")
                    extractJudgeFromXML(e,&m_chairJudges);
                if (e.tagName() == "assistantjudges")
                    extractJudgeFromXML(e,&m_assistantJudges);
            }
            nextNode = nextNode.nextSibling();
        }
    }
}

Judge JudgesPanel::getJudgeByName(const QString &name)
{
    Judge j(name,Judge::NO);
    for (int i = 0; i< m_judgesPool.size(); i++)
    {
        if (m_judgesPool.at(i).getName() == name)
        {
            j = m_judgesPool.at(i);
            return j;
        }
    }
    return j;

}

void JudgesPanel::extractJudgeFromXML(QDomElement& element, QList<Judge*> *target)
{
    QDomNode aJudgeNode = element.firstChild();
    while (!aJudgeNode.isNull())
    {
        QDomElement aJudgeElement = aJudgeNode.toElement();
        if (!aJudgeElement.isNull())
        {
            Judge aJudge(QObject::tr("UNKNOWN"),Judge::LTV);
            aJudge.readFromDomElement(aJudgeElement);
            if (aJudge.getName() != QObject::tr("UNKNOWN")) addJudgeTo(aJudge,target);;
        }

        aJudgeNode = aJudgeNode.nextSibling();
    }
}

void JudgesPanel::extractJudgeFromXML(QDomElement& element)
{
    QDomNode aJudgeNode = element.firstChild();
    while (!aJudgeNode.isNull())
    {
        QDomElement aJudgeElement = aJudgeNode.toElement();
        if (!aJudgeElement.isNull())
        {
            Judge aJudge(QObject::tr("UNKNOWN"),Judge::LTV);
            aJudge.readFromDomElement(aJudgeElement);
            if (aJudge.getName() != QObject::tr("UNKNOWN")) addJudgeToPool(aJudge);;
        }

        aJudgeNode = aJudgeNode.nextSibling();
    }
}
