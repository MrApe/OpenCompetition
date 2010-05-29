#include "textimporter.h"
#include "QFile"
#include "data/club.h"
#include "iostream"

const QString TextImporter::m_filter;

TextImporter::TextImporter()
{
}

const std::vector<Group>& TextImporter::importFiles(const QStringList& files) throw (FileNotOpenedException)
{
    std::vector<Group> foundGroups;

    for (QStringList::const_iterator i = files.constBegin(); i != files.constEnd(); i++)
    {
        QFile current((*i));
        if (!current.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            throw new FileNotOpenedException(current.fileName().toStdString().c_str());
        }
        else
        {
            QByteArray fileContent = current.readAll();
            std::vector<Group> foundInCurrent = parseText(QString(fileContent));
            for (uint i = 0; i < foundInCurrent.size(); i++)
            {
                foundGroups.push_back(foundInCurrent.at(i));
            }
        }
    }

    return foundGroups;
}

const std::vector<Group>& TextImporter::importFile(const QString &file) throw (FileNotOpenedException)
{
    return importFiles(QStringList(file));
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
