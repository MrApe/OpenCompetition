#ifndef JUDGESPANEL_H
#define JUDGESPANEL_H

#include <QList>
#include "judge.h"
#include "abstractXMLElement.h"

class JudgesPanel : public AbstractXMLElement
{
public:
    JudgesPanel(QList<Judge> artisticJudges,
                QList<Judge> executionJudges,
                QList<Judge> difficultyJudges,
                QList<Judge> superiorJury,
                QList<Judge> lineJudges,
                Judge chairJudge,
                Judge assistantJudge);
    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

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
    inline void setChairJudge(Judge chairJudge){
        m_chairJudge = chairJudge;
    }
    inline void setAssistantJudge(Judge assistantJudge){
        m_assistantJudge = assistantJudge;
    }
    inline const QList<Judge>& getArtisticJudges() const {
        return m_artisticJudges;
    }
    inline const QList<Judge>& getExecutionJudges() const {
        return m_executionJudges;
    }
    inline const QList<Judge>& getDifficultyJudges() const {
        return m_difficultyJudges;
    }
    inline const QList<Judge>& getSuperiorJury() const {
        return m_superiorJury;
    }
    inline const QList<Judge>& getLineJudges() const {
        return m_lineJudges;
    }
    inline const Judge& getChairJudge() const {
        return m_chairJudge;
    }
    inline const Judge& getAssistantJudge() const {
        return m_assistantJudge;
    }



private:
    QList<Judge> m_artisticJudges;
    QList<Judge> m_executionJudges;
    QList<Judge> m_difficultyJudges;
    QList<Judge> m_superiorJury;
    QList<Judge> m_lineJudges;
    Judge m_chairJudge;
    Judge m_assistantJudge;
};

#endif // JUDGESPANEL_H
