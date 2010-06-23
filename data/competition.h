#ifndef COMPETITION_H
#define COMPETITION_H

#include <vector>
#include <QObject>
#include <QString>
#include <QDate>
#include <QDomDocument>
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


    //! Inline getter
    inline const QString& getName() const {
        return m_name;}
    inline const QTime& getTime() const {
        return m_time;}
    inline const QDate& getDate() const {
        return m_date;}
    inline const JudgesPanel* getJudgesPanel() const {
        return m_judgesPanel;}
    inline const QList<Group>& getStarter() const {
        return m_starter;}
    inline bool isRLT() const {
        return m_isRLT;}
    inline const QString& getDescription() const {
        return m_description;}

signals:
    void changed();


    //! Inline setter as slots
public slots:

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
      Set the name of the competition.
        @param name Name of the Competition.
    */
    inline void setName(const QString& name){
        m_name = name;}
    /*!
      Set the time of the competition.
        @param time Time of the Competition.
    */
    inline void setTime(const QTime& time){
        m_time = time;}
    /*!
      Set the date of the competition.
        @param date Date of the Competition.
    */
    inline void setDate(const QDate& date){
        m_date = date;}
    /*!
      Set the judges panel for this competition.
        @param judgesPanel Judges for this competition.
    */
    inline void setJudgesPanel(JudgesPanel* judgesPanel){
        m_judgesPanel = judgesPanel;}
    /*!
      Set the groups and invividuals starting in this competition.
        @param starter Starter of this competition.
    */
    inline void setStarter(QList<Group> starter){
        m_starter = starter;}
    /*!
      Set wether this competition is an RLT.
        @param isRLT true is this competition is an RLT.
    */
    inline void setAsRLT(bool isRLT){
        m_isRLT = isRLT;}
    /*!
      Set the description of this competition.
        @param description Text describing this competition.
    */
    inline void setDescription(const QString& description){
        m_description = description;}
    /*!
      This function adds the given groups to the competition.
      Groups are interpretet as starter and can be individuals.
      @param groups Groups to be added.
      */
    void addGroups(QList<Group>& groups, QString* logMessage = 0);


private:
    QString m_name;
    QDate m_date;
    QTime m_time;
    bool m_isRLT;
    QString m_description;
    JudgesPanel* m_judgesPanel;
    QList<Group> m_starter;
};

#endif // COMPETITION_H
