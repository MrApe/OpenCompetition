#ifndef JUDGESPANEL_H
#define JUDGESPANEL_H

#include <QList>
#include "judge.h"
#include "abstractXMLElement.h"

class JudgesPanel : public AbstractXMLElement
{
public:
    JudgesPanel();

    JudgesPanel(QList<Judge> juudgesPool);

    JudgesPanel(QList<Judge*> artisticJudges,
                QList<Judge*> executionJudges,
                QList<Judge*> difficultyJudges,
                QList<Judge*> superiorJury,
                QList<Judge*> lineJudges,
                QList<Judge*> chairJudges,
                QList<Judge*> assistantJudges);

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*!
      This method extracts judges information out of the given DomElement.
      */
    virtual void readFromDomElement(QDomElement &element);

    /*!
      This method returns a judge by name.
      @param name The name of the judge.
      @return A reference to the judge.
      */
    Judge getJudgeByName(const QString& name);

    inline void addJudge(Judge judge) {addJudgeToPool(judge);}
    inline void addArtisticJudge(Judge judge) {addJudgeTo(judge, &m_artisticJudges);}
    inline void addExecutionJudge(Judge judge) {addJudgeTo(judge, &m_executionJudges);}
    inline void addDifficultyJudge(Judge judge) {addJudgeTo(judge, &m_difficultyJudges);}
    inline void addSuperiorJudge(Judge judge) {addJudgeTo(judge, &m_superiorJury);}
    inline void addLineJudge(Judge judge) {addJudgeTo(judge, &m_lineJudges);}
    inline void addChairJudge(Judge judge) {addJudgeTo(judge, &m_chairJudges);}
    inline void addAssistantJudge(Judge judge) {addJudgeTo(judge, &m_assistantJudges);}

    inline QList<Judge*>& getArtisticJudges(){return m_artisticJudges;}
    inline QList<Judge*>& getExecutionJudges(){return m_executionJudges;}
    inline QList<Judge*>& getDifficultyJudges(){return m_difficultyJudges;}
    inline QList<Judge*>& getSuperiorJury(){return m_superiorJury;}
    inline QList<Judge*>& getLineJudges(){return m_lineJudges;}
    inline QList<Judge*>& getChairJudges(){return m_chairJudges;}
    inline QList<Judge*>& getAssistantJudges(){return m_assistantJudges;}
    inline QList<Judge>& getPool(){return m_judgesPool;}
    int size() const;
    int poolSize() const;



private:
    QList<Judge*> m_artisticJudges;
    QList<Judge*> m_executionJudges;
    QList<Judge*> m_difficultyJudges;
    QList<Judge*> m_superiorJury;
    QList<Judge*> m_lineJudges;
    QList<Judge*> m_chairJudges;
    QList<Judge*> m_assistantJudges;
    QList<Judge> m_judgesPool;

    inline void setArtisticJudges(QList<Judge*> artisticJudges){
        m_artisticJudges = artisticJudges;
    }
    inline void setExecutionJudges(QList<Judge*> executionJudges){
        m_executionJudges = executionJudges;
    }
    inline void setDifficultyJudges(QList<Judge*> difficultyJudges){
        m_difficultyJudges = difficultyJudges;
    }
    inline void setSuperiorJury(QList<Judge*> superiorJury){
        m_superiorJury = superiorJury;
    }
    inline void setLineJudges(QList<Judge*> lineJudges) {
        m_lineJudges = lineJudges;
    }
    inline void setChairJudges(QList<Judge*> chairJudges){
        m_chairJudges = chairJudges;
    }
    inline void setAssistantJudges(QList<Judge*> assistantJudges){
        m_assistantJudges = assistantJudges;
    }

    void addJudgesToPoolFrom(QList<Judge*> * source);
    Judge* addJudgeToPool(Judge judge);
    void addJudgeTo(Judge judge, QList<Judge*> * to);
    Judge* findJudgeInPool(Judge judge);

    void extractJudgeFromXML(QDomElement& element, QList<Judge*>* target);
    void extractJudgeFromXML(QDomElement& element);
};

#endif // JUDGESPANEL_H
