#include "textimporter.h"
#include "QFile"
#include "data/club.h"
#include "iostream"

TextImporter::TextImporter(const QString& filter):
        AbstractImporter(filter)
{
}

const std::vector<Group> TextImporter::importFile(const QString &fileName) throw (FileNotOpenedException)
{
    std::vector<Group> foundGroups;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw new FileNotOpenedException(file.fileName().toStdString().c_str());
    }
    else
    {
        QByteArray fileContent = file.readAll();
        std::vector<Group> foundInCurrent = parseText(QString(fileContent));
        for (uint i = 0; i < foundInCurrent.size(); i++)
        {
            foundGroups.push_back(foundInCurrent.at(i));
        }
    }

    return foundGroups;
}

std::vector<Group> TextImporter::parseText(QString text){
    std::vector<Group> foundGroups;

    int annBase = text.indexOf("Verbindliche Meldung");
    QString announcement = text.remove(0,annBase);

    int clubBase = announcement.indexOf("Verein:");
    int clubEnd = announcement.indexOf(QChar::LineSeparator,clubBase);
    Club c(announcement.mid(clubBase+7,clubEnd).simplified());

    int catBase = announcement.indexOf("Kategorie:");
    int catEnd = announcement.indexOf(QChar::LineSeparator,catEnd);
    Group::categorieType cat = Group::categorieFromString(announcement.mid(catBase+10,catEnd).simplified());

    int startBase = announcement.indexOf("Starter:");
    startBase = announcement.indexOf("*",startBase);

    std::vector<Competitor> competitors;
    int startEnd = -1;
    while (startBase != -1)
    {
        startBase+=1;
        startEnd = announcement.indexOf(QChar::LineSeparator,startBase);
        QString starter = announcement.mid(startBase,startEnd);
        Competitor comp(starter.section(",",0,0),
                        starter.section(",",2,2).toUInt(),
                        starter.section(",",1,1).contains("m")?Competitor::MALE:Competitor::FEMALE);
        competitors.push_back(comp);
        startBase = announcement.indexOf("*",startEnd);
    }

    foundGroups.push_back(Group(competitors,cat,c));

    return foundGroups;
}
