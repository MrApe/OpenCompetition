#ifndef COMPETITION_H
#define COMPETITION_H

#include <vector>
#include <QObject>
#include <QString>
#include <QDate>
#include <QDomDocument>
#include <QHash>
#include "judgespanel.h"
#include "group.h"
#include "abstractXMLElement.h"

class Competition : public QObject, public AbstractXMLElement
{

    Q_OBJECT

public:
    /*!
      Constructor
        @param name Name of the competition.
        @param date Date of the competition.
        @param time Time of the competition.
        @param isRLT Is this competition an RLT?
        @param description Text describing the competition.
        @param judgesPanel The judges panel for this comeptition.
        @param starter The starting groups and individuals.
     */
    Competition(const QString& name,
                const QDate& date,
                const QTime& time,
                bool isRLT,
                const QString& description,
                JudgesPanel* judgesPanel,
                QList<Group> starter);

    /*!
      Empty Constructor.
     */
    Competition();

    /*!
      This method checks if this competition contains the given group in its startlist.
      @param group The group to be found.
      @return True if the group is contained. False otherwise.
      */
    bool contains(const Group& group) const;

    /*!
      This method creates a QDomDocument and returnes it as an xml-Structure.
      @return The Competition as QDomDocument.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*!
      This method reads a DomElement.
      */
    virtual void readFromDomElement(QDomElement &element);


    //! Inline getter
    inline QString& getName(){return m_name;}
    inline QTime& getTime()  {return m_time;}
    inline QDate& getDate()  {return m_date;}
    inline JudgesPanel* getJudgesPanel()  {return m_judgesPanel;}
    inline const QList<Group>& getStarter() const {return m_groups;}
    inline QList<Group>& getStarter(){return m_groups;}
    inline bool isRLT() const {return m_isRLT;}
    inline const QString& getDescription() const {return m_description;}
    inline QList<Group*>& getStartList() {return m_startList;}
    inline QList<Group*>& getTrainingList() {return m_trainingList;}
    inline const QTime& getTrainingTime() const { return m_trainingTime;}
    inline const QTime& getCompetitionTime() const {return m_competitionTime;}
    inline const QTime& getStarterOffset() const {return m_starterOffset;}
    inline const QTime& getTrainingOffset() const {return m_trainingOffset;}

signals:
    void changed();


    //! Inline setter as slots
public slots:  
    /*!
      Set the name of the competition.
        @param name Name of the Competition.
    */
    inline void setName(const QString& name){m_name = name;}
    /*!
      Set the time of the competition.
        @param time Time of the Competition.
    */
    inline void setTime(const QTime& time){
        m_time = time;
        m_trainingTime = QTime(m_time.hour()-2,m_time.minute(),m_time.second(),m_time.msec());
        m_competitionTime = m_time;}
    /*!
      Set the date of the competition.
        @param date Date of the Competition.
    */
    inline void setDate(const QDate& date){m_date = date;}
    /*!
      Set the judges panel for this competition.
        @param judgesPanel Judges for this competition.
    */
    inline void setJudgesPanel(JudgesPanel* judgesPanel){m_judgesPanel = judgesPanel;}
    /*!
      Set wether this competition is an RLT.
        @param isRLT true is this competition is an RLT.
    */
    inline void setAsRLT(bool isRLT){m_isRLT = isRLT;}
    /*!
      Set the description of this competition.
        @param description Text describing this competition.
    */
    inline void setDescription(const QString& description){m_description = description;}
    /*!
      Set the training time of this competition.
        @param time Time of training.
    */
    inline void setTrainingTime(const QTime& time) {m_trainingTime = time;}
    /*!
      Set the start time of this competition.
        @param time Time of competition.
    */
    inline void setCompetitionTime(const QTime& time) {m_competitionTime = time;}
    /*!
      Set the time between two starters during competition.
        @param offset Time til next starter.
    */
    inline void setStarterOffset(const QTime& offset) {m_starterOffset = offset;}
    /*!
      Set the time between two starters during training.
        @param offset Time til next starter.
    */
    inline void setTrainingOffset(const QTime& offset) {m_trainingOffset = offset;}

    //More complex functions to modify thsi competition
    /*!
      This function saves the competition as XML-Data
      @param filename The filename.
      */
    bool saveToFile(const QString& filename);
    /*!
      This function loades the competition from an XML-file
      @param filename The filename of the XML-file
      @param errorMsg Where to put the error message in case of an error.
      @param errorLine Where to put the line number of the error.
      @param errorColumn Where to put the column of the error.
      */
    bool loadFromFile(const QString& filename, QString* errorMsg = 0,int* errorLine = 0,int* errorColumn = 0);
    /*!
      This function adds the given groups to the competition.
      Groups are interpretet as starter and can be individuals, too.
      @param groups Groups to add.
      */
    void addGroups(QList<Group>& groups, QString* logMessage = 0);
    /*!
      This function adds the given group to the competition.
      Groups are interpretet as starter and can be individuals, too.
      @param group Group to add.
      */
    void addGroup(Group& group, QString* logMessage = 0);

    /*!
      This method adds the given competitior to the compepetition.
      @param competitor Competitor to add.
      */
    void addCompetitor(const Competitor& competitor);

    /*!
      This method adds the given club to the competition.
      @param club Club to add.
      */
    void addClub(const Club& club);



private:
    //main properties
    QString m_name;
    QDate m_date;
    QTime m_time;
    bool m_isRLT;
    QString m_description;

    //judges combined in a JudgesPanel
    JudgesPanel* m_judgesPanel;

    //main data lists
    QList<Club> m_clubs;
    QList<Competitor> m_competitors;
    QList<Group> m_groups;

    //composed lists
    QList<Group*> m_startList;
    QList<Group*> m_trainingList;

    /*!
      Set the groups and invividuals starting in this competition.
        @param starter Starter of this competition.
    */
    inline void setStarter(QList<Group> starter){
        m_groups = starter;}
};

#endif // COMPETITION_H
