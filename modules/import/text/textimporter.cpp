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
    Club c(text.mid(clubBase+7,clubEnd));

    std::cout << c.getName().toStdString() << std::endl;

    //foundGroups.push_back(Group(std::vector<Group>(),Group::INDIVIDUAL_MEN,c));

    return foundGroups;
}
