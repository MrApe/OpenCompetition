#include "competition.h"
#include <QFile>
#include <QTextStream>
#include <QDomDocument>

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

bool Competition::saveToFile(const QString &filename)
{
    QFile outputFile(filename);


    //Create XMl Model for Competition
    QDomDocument compXMLDoc("Competition");
    QDomElement baseDataElement = compXMLDoc.createElement("BaseData");
    compXMLDoc.appendChild(baseDataElement);
    QDomElement nameElement = compXMLDoc.createElement("Name");
    baseDataElement.appendChild(nameElement);
    QDomText name = compXMLDoc.createTextNode(m_name);
    nameElement.appendChild(name);

    if (outputFile.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream outputStream(&outputFile);
            compXMLDoc.save(outputStream,3);
    }

    return true;

}

