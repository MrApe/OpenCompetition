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
                std::vector<Group> starter);

    /*!
      Empty Constructor.
     */
    Competition();


    //! Inline getter
    inline const QString& getName() const {
        return m_name;}
    inline const QTime& getTime() const {
        return m_time;}
    inline const QDate& getDate() const {
        return m_date;}
    inline const JudgesPanel* getJudgesPanel() const {
        return m_judgesPanel;}
    inline const std::vector<Group>& getStarter() const {
        return m_starter;}
    inline bool isRLT() const {
        return m_isRLT;}
    inline const QString& getDescription() const {
        return m_description;}


    //! Inline setter as slots
public slots:

    /*!
      This function saves the competition as XML-Data
      */
    bool saveToFile(const QString& filename);

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
    inline void setStarter(std::vector<Group> starter){
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


private:
    QString m_name;
    QDate m_date;
    QTime m_time;
    bool m_isRLT;
    QString m_description;
    JudgesPanel* m_judgesPanel;
    std::vector<Group> m_starter;
};

#endif // COMPETITION_H
