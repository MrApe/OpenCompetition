#include <QObject>
#include <QMap>
#include <QDate>
#include "group.h"

QString Group::categorieToString(categorieType categorie)
{
    switch (categorie) {
    case INDIVIDUAL_MEN: return QObject::QObject::tr("IM");
    case INDIVIDUAL_WOMEN:return QObject::tr("IW");
    case MIXED_PAIR: return QObject::tr("Mixed");
    case PAIR_TRIO: return QObject::tr("Pair/Trio");
    case GROUP: return QObject::tr("Group");
    default: return ""; //should not be reached
    }
}

QString Group::ageToString(ageType age)
{
    switch (age) {
    case NATIONAL_DEVELOPMENT: return QObject::tr("National Development");
    case AG_ONE: return QObject::tr("Age Group 1");
    case AG_TWO: return QObject::tr("Age Group 2");
    case SENIORS: return QObject::tr("Seniors");
    default:return QObject::tr("unknown"); //should not be reached
    }
}

Group::categorieType Group::categorieFromString(const QString &catAsString)
{
    if (catAsString == QObject::tr("IM")) return INDIVIDUAL_MEN;
    if (catAsString == QObject::tr("IW")) return INDIVIDUAL_WOMEN;
    if (catAsString == QObject::tr("Mixed")) return MIXED_PAIR;
    if (catAsString == QObject::tr("Pair/Trio")) return PAIR_TRIO;
    if (catAsString == QObject::tr("Group")) return GROUP;
    return GROUP;
}

Group::ageType Group::ageFromString(const QString &ageAsString)
{
    if (ageAsString == QObject::tr("National Development")) return NATIONAL_DEVELOPMENT;
    if (ageAsString == QObject::tr("Age Group 1")) return AG_ONE;
    if (ageAsString == QObject::tr("Age Group 2")) return AG_TWO;
    if (ageAsString == QObject::tr("Seniors")) return SENIORS;
    return UNSET;
}

Group::Group():
        m_competitors(),
        m_age(),
        m_categorie(),
        m_club(QObject::tr("NOT_GIVEN")),
        m_scores()
{

}

Group::Group(const QList<Competitor>& competitors,
             ageType age,
             categorieType categorie,
             const Club& cl):
        m_competitors(competitors),
        m_age(age),
        m_categorie(categorie),
        m_club(cl),
        m_scores()
{
}

Group::Group(const Group &other):
        AbstractXMLElement(),
        m_competitors(other.getCompetitors()),
        m_age(other.getAge()),
        m_categorie(other.getType()),
        m_club(other.getClub().getName()),
        m_scores(other.getScores())
{
}

bool Group::operator ==(const Group& other) const
{
    for (int i = 0; i<m_competitors.size() && i < other.getCompetitors().size(); i++)
    {
        if (m_competitors.at(i) != other.getCompetitors().at(i))
        {
            return false;
        }
    }
    if (m_club != other.getClub()) return false;
    if (m_categorie != other.getType()) return false;

    return true;
}

bool Group::operator!=(const Group& other) const
{
    return !(*this==other);
}

bool Group::contains(Competitor &competitor)
{
    for (QList<Competitor>::iterator i = m_competitors.begin(); i != m_competitors.end(); i++)
    {
        if ((*i)==competitor) return true;
    }
    return false;
}

QString Group::hash() const
{
    QString hash;
    hash.append(m_club.getName());
    hash.append(Group::ageToString(m_age));
    hash.append(Group::categorieToString(m_categorie));
    for (int i = 0; i<m_competitors.size(); i++)
    {
       hash.append(m_competitors.at(i).getName());
    }
    return hash;
}

QString Group::toString()
{
    QString output;
    output.append(QObject::tr("Club: ")+m_club.getName()+"\n");
    output.append(QObject::tr("Age Group: ")+Group::ageToString(m_age)+"\n");
    output.append(QObject::tr("Categorie: ")+Group::categorieToString(m_categorie)+"\n");
    output.append(QObject::tr("Starter: ")+"\n");
    for (int i = 0; i<m_competitors.size(); i++)
    {
       output.append(m_competitors.at(i).getName()+"\n");
    }
    return output;
}

void Group::addCompetitor(Competitor comp) throw (ToManyCompetitorsException){
    if (m_competitors.size() == 6) {
        throw new ToManyCompetitorsException();
    } else {
        if (!contains(comp)){
            m_competitors.append(comp);
        }
    }
}

Group::categorieType Group::guessType(){
    unsigned int size = m_competitors.size();

    switch (size) {
    case 1 : return m_competitors.at(0).getGender() == Competitor::MALE ? INDIVIDUAL_MEN : INDIVIDUAL_WOMEN;
    case 2 : return (m_competitors.at(0).getGender() == Competitor::MALE ||
                     m_competitors.at(1).getGender() == Competitor::MALE) ? MIXED_PAIR : PAIR_TRIO;
    case 3 : return PAIR_TRIO;
    default : return GROUP;
    }
}

Group::ageType Group::guessAge()
{
    switch (m_categorie)
    {
    case Group::INDIVIDUAL_MEN:case Group::INDIVIDUAL_WOMEN:
                return m_age;
    case Group::MIXED_PAIR:
    case Group::PAIR_TRIO:
                if(m_competitors.size() == 2){
                    ageType first = guessAge(m_competitors.at(0).getBirth());
                    ageType second = guessAge(m_competitors.at(1).getBirth());
                    return first>second?first:second;
                }
   default:
                QMap<ageType, int> occurence;
                for (int i = 0; i < m_competitors.size(); i++)
                {
                    occurence[guessAge(m_competitors.at(i).getBirth())] += 1;
                }
                ageType ret = NATIONAL_DEVELOPMENT;
                ret = occurence[ret] > occurence[AG_ONE]?ret:AG_ONE;
                ret = occurence[ret] > occurence[AG_TWO]?ret:AG_TWO;
                ret = occurence[ret] > occurence[SENIORS]?ret:SENIORS;
                return ret;

    }


}

Group::ageType Group::guessAge(int birth)
{
    int diff = QDate::currentDate().year() - birth;
    if (diff < 11) {
        return NATIONAL_DEVELOPMENT;
    }
    switch (diff)
    {
    case 12:case 13:case 14: return AG_ONE;
    case 15:case 16:case 17: return AG_TWO;
    default: return SENIORS;
    }
}

QDomElement Group::toDomElement(QDomDocument *parentDocument)
{
    QDomElement groupElement = parentDocument->createElement("group");
    groupElement.setAttribute("agegroup",ageToString(m_age));
    groupElement.setAttribute("categorie",categorieToString(m_categorie));
    groupElement.appendChild(m_club.toDomElement(parentDocument));

    QDomElement competitorsElement = parentDocument->createElement("competitors");
    groupElement.appendChild(competitorsElement);
    QList<Competitor>::iterator compIT;
    for (compIT = m_competitors.begin();compIT != m_competitors.end();compIT++)
    {
        competitorsElement.appendChild(compIT->toDomElement(parentDocument));
    }

    QDomElement scoreElement = parentDocument->createElement("scores");
    groupElement.appendChild(scoreElement);
    QList<Score>::iterator scoreIT;
    for (scoreIT = m_scores.begin(); scoreIT != m_scores.end();scoreIT++)
    {
        scoreElement.appendChild(scoreIT->toDomElement(parentDocument));
    }

    return groupElement;
}

void Group::readFromDomElement(QDomElement &element)
{
    if (element.tagName() == "group")
    {
        m_age = ageFromString(element.attribute("agegroup",QObject::tr("unknown")));
        m_categorie = categorieFromString(element.attribute("categorie",""));

        QDomNode nextNode = element.firstChild();
        while (!nextNode.isNull())
        {
            QDomElement nextElement = nextNode.toElement();
            if (!nextElement.isNull() &&
                nextElement.tagName() == "club")
            {
                m_club.readFromDomElement(nextElement);
            }

            if (!nextElement.isNull() &&
                nextElement.tagName() == "competitors")
            {
                QDomNode starterNode = nextElement.firstChild();
                while (!starterNode.isNull())
                {
                    QDomElement starterElement = starterNode.toElement();
                    if (!starterElement.isNull())
                    {
                        Competitor starter(QObject::tr("NO_NAME"),0,Competitor::MALE,Club(QObject::tr("NOT_GIVEN")));
                        starter.readFromDomElement(starterElement);
                        m_competitors.append(starter);
                    }

                    starterNode = starterNode.nextSibling();
                }
            }

            if (!nextElement.isNull() &&
                nextElement.tagName() == "scores")
            {
                QDomNode scoreNode = nextElement.firstChild();
                while (!scoreNode.isNull())
                {
                    QDomElement scoreElement = scoreNode.toElement();
                    if (!scoreElement.isNull())
                    {
                        Score score;
                        score.readFromDomElement(scoreElement);
                        m_scores.append(score);
                    }

                    scoreNode = scoreNode.nextSibling();
                }
            }

            nextNode = nextNode.nextSibling();
        }


    }
}

double Group::getScoreFromJudge(const Judge& judge)
{
    if (!m_scores.isEmpty())
    {
        for (int i = 0; i< m_scores.size(); i++)
        {
            if (m_scores.at(i).getJudge() == judge)
            {
                return m_scores.at(i).getValue();
            }
        }
    }
    return 0.0;
}

bool Group::isMale() const
{
    if (m_categorie == MIXED_PAIR || m_categorie == INDIVIDUAL_MEN)
    {
        return true;
    }
    bool w = false;
    for (int i = 0; i < m_competitors.size() && w ==false; i++)
    {
        w = m_competitors.at(i).getGender() == Competitor::FEMALE;
    }
    return !w;
}

double Group::getFinalScore()
{
    double a = 0.0;
    int aCount = 0;
    double b = 0.0;
    int bCount = 0;
    double s = 0.0;
    int sCount = 0;
    double divider = isMale()?2.0:1.9;
    double line = 0.0;
    double chair = 0.0;
    for (int i = 0; i < m_scores.size(); i++)
    {
        switch (m_scores.at(i).getType())
        {
        case Judge::ARTISTIC:
            a += m_scores.at(i).getValue();
            aCount++;
            break;
        case Judge::EXECUTION:
            b += m_scores.at(i).getValue();
            bCount++;
            break;
        case Judge::DIFFICULTY:
            s += m_scores.at(i).getValue();
            sCount++;
            break;
        case Judge::CHAIR:
            chair = m_scores.at(i).getValue();
            break;
        case Judge::LINE:
            line += m_scores.at(i).getValue();
            break;
        default: //nothing;
            break;
        }
    }

    a = aCount==0?a:a/aCount;
    b = bCount==0?b:b/bCount;
    s = sCount==0?s:(s/sCount)/divider;

    return a + b + s + chair + line;
}
