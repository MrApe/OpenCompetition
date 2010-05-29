#ifndef COMPETITION_H
#define COMPETITION_H

#include "vector"
#include "QObject"
#include "QString"
#include "QDate"
#include "judgespanel.h"
#include "group.h"

class Competition : public QObject
{

    Q_OBJECT

public:
    /*!
      Constructor
        @param name Name of the competition.
        @param date Date of the competition.
        @param time Time of the competition.
        @param judgesPanel The judges panel for this comeptition.
        @param starter The starting groups and individuals.
     */
    Competition(const QString& name,
                const QDate& date,
                const QTime& time,
                JudgesPanel judgesPanel,
                std::vector<Group> starter);


    //! Inline getter
    inline const QString& getName() const {
        return m_name;}
    inline const QTime& getTime() const {
        return m_time;}
    inline const QDate& getDate() const {
        return m_date;}
    inline const JudgesPanel& getJudgesPanel() const {
        return m_judgesPanel;}
    inline const std::vector<Group>& getStarter() const {
        return m_starter;}


    //! Inline setter as slots
public slots:
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
    inline void setJudgesPanel(JudgesPanel judgesPanel){
        m_judgesPanel = judgesPanel;}
    /*!
      Set the groups and invividuals starting in this competition.
        @param starter Starter of this competition.
    */
    inline void setStarter(std::vector<Group> starter){
        m_starter = starter;}


private:
    QString m_name;
    QDate m_date;
    QTime m_time;
    JudgesPanel m_judgesPanel;
    std::vector<Group> m_starter;
};

#endif // COMPETITION_H
