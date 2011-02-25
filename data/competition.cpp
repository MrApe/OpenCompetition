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
        m_trainingTime(m_time.hour()-2,m_time.minute(),m_time.second(),m_time.msec()),
        m_competitionTime(m_time),
        m_starterOffset(QTime(0,2,0,0)),
        m_trainingOffset(QTime(0,1,0,0)),
        m_judgesPanel(new JudgesPanel()),
        m_clubs(),
        m_competitors(),
        m_groups(),
        m_startList(),
        m_trainingList()
{
}

Competition::Competition(const QString &name,
                         const QDate &date,
                         const QTime &time,
                         bool isRLT,
                         const QString& description,
                         JudgesPanel* judgesPanel) :
m_name(name),
m_date(date),
m_time(time),
m_isRLT(isRLT),
m_description(description),
m_trainingTime(m_time.hour()-2,m_time.minute(),m_time.second(),m_time.msec()),
m_competitionTime(m_time),
m_starterOffset(QTime(0,2,0,0)),
m_trainingOffset(QTime(0,1,0,0)),
m_judgesPanel(judgesPanel),
m_clubs(),
m_competitors(),
m_groups(),
m_startList(),
m_trainingList()
{
}

bool Competition::contains(const Group &group) const
{
    if (m_groups.empty()) return false;
    for (int i = 0; i < m_groups.size();i++)
    {
        if (group == m_groups.at(i)) return true;
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
    QDomElement judgesElement = parentDocument->createElement("judgesdata");
    if (m_judgesPanel) {
        judgesElement.appendChild(m_judgesPanel->toDomElement(parentDocument));
    }
    competitionElement.appendChild(judgesElement);

    //Add competitors
    QDomElement starterElement = parentDocument->createElement("starterdata");
    QList<Group>::iterator it;
    for (it = m_groups.begin() ; it != m_groups.end();it++){
        starterElement.appendChild(it->toDomElement(parentDocument));
    }
    competitionElement.appendChild(starterElement);

    return competitionElement;
}

void Competition::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "competitiondata")
    {
        setName(element.attribute("name",""));
        setDate(QDate::fromString(element.attribute("date",""),"dd.MM.yyyy"));
        setTime(QTime::fromString(element.attribute("time",""),"hh:mm"));
        setAsRLT(element.attribute("isrlt","false")=="true");
        setDescription(element.attribute("desc",""));

        QDomNode nextNode = element.firstChild();
        while (!nextNode.isNull())
        {
            QDomElement nextElement = nextNode.toElement();
            QString nextElementName;
            if (!nextElement.isNull())
                nextElementName = nextElement.tagName();
            if (nextElementName == "judgesdata")
            {
                QDomNode judgeNode = nextElement.firstChild();
                if (!judgeNode.isNull())
                {
                    QDomElement judgeElement = judgeNode.toElement();
                    if (!judgeElement.isNull())
                    {
                        m_judgesPanel = new JudgesPanel();
                        m_judgesPanel->readFromDomElement(judgeElement);
                    }
                }
            }

            if (nextElementName == "starterdata")
            {
                QDomNode groupNode = nextElement.firstChild();
                while (!groupNode.isNull())
                {
                    QDomElement groupElement = groupNode.toElement();
                    if (!groupElement.isNull())
                    {
                        Group gr;
                        gr.readFromDomElement(groupElement);
                        m_groups.append(gr);
                    }

                    groupNode = groupNode.nextSibling();
                }
            }

            nextNode = nextNode.nextSibling();
        }        
    }

}

bool Competition::saveToFile(const QString &filename)
{
    QFile outputFile(filename);

    QDomDocument compXMLDoc("competition");
    QDomAttr versionAttr = compXMLDoc.createAttribute("version");
    versionAttr.setValue("1.0");
    QDomElement compElement = toDomElement(&compXMLDoc);
    compXMLDoc.appendChild(compElement);

    if (outputFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream outputStream(&outputFile);
        compXMLDoc.save(outputStream,3);
        return true;
    } else {
        QMessageBox msgBox;
        msgBox.setText(tr("Save Error."));
        msgBox.setInformativeText(tr("Open file failed."));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }
}

bool Competition::loadFromFile(const QString &filename,QString* errorMsg,int* errorLine,int* errorColumn )
{
    QFile inputFile(filename);

    QDomDocument compXMLDoc;
    if (compXMLDoc.setContent(&inputFile,errorMsg,errorLine,errorColumn))
    {
        QDomElement root = compXMLDoc.documentElement();
        //Load base data
        readFromDomElement(root);

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
        if (!m_groups.contains(newGroup)) m_groups.append(newGroup);
    }
}

void Competition::addGroups(Group &group, QString *logMessage)
{
    QList<Group> groups;
    groups.append(group);
    addGroups(groups,logMessage);
}
