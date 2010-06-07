#include "competition.h"
#include <QFile>
#include <QTextStream>

Competition::Competition() :
        m_name(),
        m_date(),
        m_time(),
        m_isRLT(false),
        m_description(),
        m_judgesPanel(NULL),
        m_starter()
{

}

Competition::Competition(const QString &name,
                         const QDate &date,
                         const QTime &time,
                         bool isRLT,
                         const QString& description,
                         JudgesPanel* judgesPanel,
                         std::vector<Group>starter) :
    m_name(name),
    m_date(date),
    m_time(time),
    m_isRLT(isRLT),
    m_description(description),
    m_judgesPanel(judgesPanel),
    m_starter(starter)
{
}

QDomElement Competition::toDomElement(QDomDocument* parentDocument)
{

    //Create XMl Model for Competition
    //Store base data
    QDomElement competitionElement = parentDocument->createElement("competitiondata");
    competitionElement.setAttribute("name", m_name);
    competitionElement.setAttribute("date",m_date.toString("dd.MM.yyyy"));
    competitionElement.setAttribute("time",m_time.toString());
    competitionElement.setAttribute("isrlt",m_isRLT?"true":"false");
    competitionElement.setAttribute("desc",m_description);

    // Add judges panel
    if (m_judgesPanel) {
        competitionElement.appendChild(m_judgesPanel->toDomElement(parentDocument));
    }

    //Add competitors
    QDomElement starterElement = parentDocument->createElement("starterdata");
    std::vector<Group>::iterator it;
    for (it = m_starter.begin() ; it != m_starter.end();it++){
        starterElement.appendChild(it->toDomElement(parentDocument));
    }

    return competitionElement;
}

bool Competition::saveToFile(const QString &filename)
{
    QFile outputFile(filename);

    QDomDocument compXMLDoc("competition");
    compXMLDoc.appendChild(toDomElement(&compXMLDoc));

    if (outputFile.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream outputStream(&outputFile);
            compXMLDoc.save(outputStream,3);
    }

    return true;

}

