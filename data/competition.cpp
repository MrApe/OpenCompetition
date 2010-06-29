#include "competition.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDomNamedNodeMap>

Competition::Competition() :
        m_name(),
        m_date(),
        m_time(),
        m_isRLT(false),
        m_description(),
        m_judgesPanel(NULL),
        m_starter()
{
    m_starter = QList<Group>();

}

Competition::Competition(const QString &name,
                         const QDate &date,
                         const QTime &time,
                         bool isRLT,
                         const QString& description,
                         JudgesPanel* judgesPanel,
                         QList<Group>starter) :
    m_name(name),
    m_date(date),
    m_time(time),
    m_isRLT(isRLT),
    m_description(description),
    m_judgesPanel(judgesPanel),
    m_starter(starter)
{
    QMessageBox::critical(NULL,tr("Open error!"),tr("Competition could not be opened due to the following error: "),QMessageBox::Ok,QMessageBox::Ok);
}

bool Competition::contains(const Group &group) const
{
    if (m_starter.empty()) return false;
    for (int i = 0; i < m_starter.size();i++)
    {
        if (group == m_starter.at(i)) return true;
    }

    return false;
}

QDomElement Competition::toDomElement(QDomDocument* parentDocument)
{

    //Create XMl Model for Competition
    //Store base data
    QDomElement competitionElement = parentDocument->createElement("competitiondata");
    competitionElement.setAttribute("name", m_name);
    competitionElement.setAttribute("date",m_date.toString("dd.MM.yyyy"));
    competitionElement.setAttribute("time",m_time.toString("hh:mm"));
    competitionElement.setAttribute("isrlt",m_isRLT?"true":"false");
    competitionElement.setAttribute("desc",m_description);

    // Add judges panel
    if (m_judgesPanel) {
        competitionElement.appendChild(m_judgesPanel->toDomElement(parentDocument));
    }

    //Add competitors
    QDomElement starterElement = parentDocument->createElement("starterdata");
    QList<Group>::iterator it;
    for (it = m_starter.begin() ; it != m_starter.end();it++){
        starterElement.appendChild(it->toDomElement(parentDocument));
    }

    return competitionElement;
}

bool Competition::saveToFile(const QString &filename)
{
    QFile outputFile(filename);

    QDomDocument compXMLDoc("competition");
    QDomAttr versionAttr = compXMLDoc.createAttribute("version");
    versionAttr.setValue("1.0");
    compXMLDoc.appendChild(toDomElement(&compXMLDoc));

    QString Debug = compXMLDoc.toString(2);
    QMessageBox msgBox;
    msgBox.setText(tr("SaveFile."));
    msgBox.setInformativeText("The Competition will now be saved as XML-Document.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDetailedText(Debug);
    msgBox.exec();

    if (outputFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream outputStream(&outputFile);
        compXMLDoc.save(outputStream,3);
        return true;
    } else {
        return false;
    }
}

bool Competition::loadFromFile(const QString &filename,QString* errorMsg,int* errorLine,int* errorColumn )
{
    QFile inputFile(filename);

    QDomDocument compXMLDoc;
    if (compXMLDoc.setContent(&inputFile,errorMsg,errorLine,errorColumn))
    {
        //Load base data
        QDomNamedNodeMap attrMap = compXMLDoc.elementsByTagName("competitiondata").item(0).attributes();
        m_name = attrMap.namedItem("name").nodeValue();
        m_date = QDate::fromString(attrMap.namedItem("date").nodeValue(),"dd.MM.yyyy");
        m_time = QTime::fromString(attrMap.namedItem("time").nodeValue(),"hh:mm");
        m_isRLT = attrMap.namedItem("isrlt").nodeValue()=="true";
        m_description = attrMap.namedItem("desc").nodeValue();

        //load

        return true;
    }
    return false;

}

void Competition::addGroups(QList<Group>& groups, QString* logMessage)
{
    for (int i = 0; i < groups.size(); i++)
    {
        Group newGroup(groups.at(i));
        if (logMessage!=0) logMessage->append(newGroup.toString());
        if (!m_starter.contains(newGroup)) m_starter.append(newGroup);
    }
}

