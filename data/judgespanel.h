#ifndef JUDGESPANEL_H
#define JUDGESPANEL_H

#include <QList>
#include "judge.h"
#include "abstractXMLElement.h"

class JudgesPanel : public AbstractXMLElement
{
public:
    JudgesPanel();
    JudgesPanel(QList<Judge> artisticJudges,
                QList<Judge> executionJudges,
                QList<Judge> difficultyJudges,
                QList<Judge> superiorJury,
                QList<Judge> lineJudges,
                QList<Judge> chairJudges,
                QList<Judge> assistantJudges);

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*!
      This method extracts judges information out of the given DomElement.
      */
    virtual void readFromDomElement(QDomElement &element);

    /*
     * Inline getter ans setter
     */
    inline void setArtisticJudges(QList<Judge> artisticJudges){
        m_artisticJudges = artisticJudges;
    }
    inline void setExecutionJudges(QList<Judge> executionJudges){
        m_executionJudges = executionJudges;
    }
    inline void setDifficultyJudges(QList<Judge> difficultyJudges){
        m_difficultyJudges = difficultyJudges;
    }
    inline void setSuperiorJury(QList<Judge> superiorJury){
        m_superiorJury = superiorJury;
    }
    inline void setLineJudges(QList<Judge> lineJudges) {
        m_lineJudges = lineJudges;
    }
    inline void setChairJudge(QList<Judge> chairJudges){
        m_chairJudges = chairJudges;
    }
    inline void setAssistantJudge(QList<Judge> assistantJudges){
        m_assistantJudges = assistantJudges;
    }
    inline QList<Judge>& getArtisticJudges()  {
        return m_artisticJudges;
    }
    inline QList<Judge>& getExecutionJudges()  {
        return m_executionJudges;
    }
    inline QList<Judge>& getDifficultyJudges()  {
        return m_difficultyJudges;
    }
    inline QList<Judge>& getSuperiorJury()  {
        return m_superiorJury;
    }
    inline QList<Judge>& getLineJudges()  {
        return m_lineJudges;
    }
    inline QList<Judge>& getChairJudges()  {
        return m_chairJudges;
    }
    inline QList<Judge>& getAssistantJudges()  {
        return m_assistantJudges;
    }
    int size() const;



private:
    QList<Judge> m_artisticJudges;
    QList<Judge> m_executionJudges;
    QList<Judge> m_difficultyJudges;
    QList<Judge> m_superiorJury;
    QList<Judge> m_lineJudges;
    QList<Judge> m_chairJudges;
    QList<Judge> m_assistantJudges;

    void extractJudgeFromXML(QDomElement& element, QList<Judge>& target);
};

#endif // JUDGESPANEL_H
