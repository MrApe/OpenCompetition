#include "textimporter.h"
#include <QFile>
#include <QVector>
#include "data/club.h"
#include "data/judgespanel.h"
#include "iostream"

TextImporter::TextImporter(const QString& filter):
        AbstractImporter(filter)
{
}

void TextImporter::importFile(const QString &fileName, Competition *target, QString* logMessage) throw (FileNotOpenedException)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw new FileNotOpenedException(file.fileName().toStdString().c_str());
    }
    else
    {
        parseText(file,target,logMessage);
    }
}

void TextImporter::parseText(QFile& file,Competition* target, QString* logMessage){
    QString line;

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
    if (!logMessage->isNull())  logMessage->append(QObject::tr("Found Club:")+c.toString());

    //find judges
    while (!line.contains("Kampfrichter:") && !file.atEnd()) {
        line = file.readLine();
    }
    line = file.readLine();

    QString judge;
    while (line.contains("*") &&
           !file.atEnd() &&
           !line.contains("Kategorie:") &&
           !line.contains("Altersklasse:") &&
           !line.contains("Teams") &&
           !line.contains("Starter")) {

        judge = line.remove(0,line.indexOf("*")+2);
        Judge j = Judge::judgeFromString(judge);

        target->getJudgesPanel()->addJudge(j);

        logMessage->append(QObject::tr("Found judge: ")+j.toString() +"\n");

        line = file.readLine();
    }

    //find categorie
    while (!line.contains("Kategorie:") && !file.atEnd()){
        line = file.readLine();
    }


    while (line.contains("Kategorie:") && !file.atEnd()) {
        QString catString = line.remove(0,line.indexOf("Kategorie:")+10).simplified();
        Group::categorieType cat = Group::categorieFromString(catString);

        //find age group
        while (!line.contains("Altersklasse:") && !file.atEnd()){
            line = file.readLine();
        }
        QString ageString = line.remove(0,line.indexOf("Alterklasse:")+16).simplified();
        Group::ageType age = Group::ageFromString(ageString);

        //find starter
        while (!line.contains("Starter:")  && !file.atEnd()){
            line = file.readLine();
        }
        line = file.readLine();

        QList<Competitor> competitors;
        QString starter;
        while (line.contains("*") &&
               !file.atEnd() &&
               !line.contains("Kategorie:") &&
               !line.contains("Altersklasse:")) {

            starter = line.remove(0,line.indexOf("*")+2);
            Competitor comp(starter.section(",",0,0),
                            starter.section(",",2,2).toUInt(),
                            starter.section(",",1,1).contains("m")?Competitor::MALE:Competitor::FEMALE,
                            c);
            competitors.append(comp);

            line = file.readLine();
        }

        Group found(competitors,age,cat,c);
        logMessage->append(QObject::tr("Found group: \n"));
        target->addGroup(found,logMessage);

        //look for more teams
        while (!line.contains("Kategorie:") &&
               !line.contains("Ende des Dokumentes") &&
               !file.atEnd()){
            line = file.readLine();
        }
    }

}
