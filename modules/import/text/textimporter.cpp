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
        std::vector<Group> foundInCurrent = parseText(file);
        for (uint i = 0; i < foundInCurrent.size(); i++)
        {
            foundGroups.push_back(foundInCurrent.at(i));
        }
    }

    return foundGroups;
}

std::vector<Group> TextImporter::parseText(QFile& file){
    QString line;
    std::vector<Group> gr;
    gr.clear();

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

        std::vector<Competitor> competitors;
        QString starter;
        while (line.contains("*") &&
               !file.atEnd() &&
               !line.contains("Kategorie:")) {

            starter = line.remove(0,line.indexOf("*")+2);
            Competitor comp(starter.section(",",0,0),
                            starter.section(",",2,2).toUInt(),
                            starter.section(",",1,1).contains("m")?Competitor::MALE:Competitor::FEMALE);
            competitors.push_back(comp);

            line = file.readLine();
        }

        gr.push_back(Group(competitors,cat,c));
    }



    return gr;
}
