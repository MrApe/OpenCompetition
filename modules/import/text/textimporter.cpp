#include "textimporter.h"
#include <QFile>
#include <QVector>
#include "data/club.h"
#include "iostream"

TextImporter::TextImporter(const QString& filter):
        AbstractImporter(filter)
{
}

const QList<Group> TextImporter::importFile(const QString &fileName) throw (FileNotOpenedException)
{
    QList<Group> foundGroups;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw new FileNotOpenedException(file.fileName().toStdString().c_str());
    }
    else
    {
        QList<Group> foundInCurrent = parseText(file);
        for (int i = 0; i < foundInCurrent.size(); i++)
        {
            foundGroups.append(foundInCurrent.at(i));
        }
    }

    return foundGroups;
}

QList<Group> TextImporter::parseText(QFile& file){
    QString line;
    QList<Group> groupList;

    //skip preämbel
    while (!line.contains("Verbindliche Meldung")){
        line = file.readLine();
    }

    //find club
    while (!line.contains("Verein:")  && !file.atEnd()){
        line = file.readLine();
    }
    QString name = line.remove(0,line.indexOf("Verein:")+7).simplified();
    Club c(name);

    //find categorie
    while (!line.contains("Kategorie:") && !file.atEnd()){
        line = file.readLine();
    }

    while (line.contains("Kategorie:") && !file.atEnd()) {
        QString catString = line.remove(0,line.indexOf("Kategorie:")+10).simplified();
        Group::categorieType cat = Group::categorieFromString(catString);

        //find starter
        while (!line.contains("Starter:")  && !file.atEnd()){
            line = file.readLine();
        }
        line = file.readLine();

        QList<Competitor> competitors;
        QString starter;
        while (line.contains("*") &&
               !file.atEnd() &&
               !line.contains("Kategorie:")) {

            starter = line.remove(0,line.indexOf("*")+2);
            Competitor comp(starter.section(",",0,0),
                            starter.section(",",2,2).toUInt(),
                            starter.section(",",1,1).contains("m")?Competitor::MALE:Competitor::FEMALE);
            competitors.append(comp);

            line = file.readLine();
        }

        Group found(competitors,cat,c);
        groupList.append(found);
    }

    return groupList;
}
