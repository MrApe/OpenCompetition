#ifndef JUDGESPANEL_H
#define JUDGESPANEL_H

#include <vector>
#include "judge.h"

class JudgesPanel
{
public:
    JudgesPanel(std::vector<Judge> artisticJudges,
                std::vector<Judge> executionJudges,
                std::vector<Judge> difficultyJudges,
                std::vector<Judge> superiorJury,
                std::vector<Judge> lineJudges,
                Judge chairJudge,
                Judge assistantJudge);
    /*
     * Inline getter ans setter
     */
    inline void setArtisticJudges(std::vector<Judge> artisticJudges){
        m_artisticJudges = artisticJudges;
    }
    inline void setExecutionJudges(std::vector<Judge> executionJudges){
        m_executionJudges = executionJudges;
    }
    inline void setDifficultyJudges(std::vector<Judge> difficultyJudges){
        m_difficultyJudges = difficultyJudges;
    }
    inline void setSuperiorJury(std::vector<Judge> superiorJury){
        m_superiorJury = superiorJury;
    }
    inline void setLineJudges(std::vector<Judge> lineJudges) {
        m_lineJudges = lineJudges;
    }
    inline void setChairJudge(Judge chairJudge){
        m_chairJudge = chairJudge;
    }
    inline void setAssistantJudge(Judge assistantJudge){
        m_assistantJudge = assistantJudge;
    }
    inline const std::vector<Judge>& getArtisticJudges() const {
        return m_artisticJudges;
    }
    inline const std::vector<Judge>& getExecutionJudges() const {
        return m_executionJudges;
    }
    inline const std::vector<Judge>& getDifficultyJudges() const {
        return m_difficultyJudges;
    }
    inline const std::vector<Judge>& getSuperiorJury() const {
        return m_superiorJury;
    }
    inline const std::vector<Judge>& getLineJudges() const {
        return m_lineJudges;
    }
    inline const Judge& getChairJudge() const {
        return m_chairJudge;
    }
    inline const Judge& getAssistantJudge() const {
        return m_assistantJudge;
    }



private:
    std::vector<Judge> m_artisticJudges;
    std::vector<Judge> m_executionJudges;
    std::vector<Judge> m_difficultyJudges;
    std::vector<Judge> m_superiorJury;
    std::vector<Judge> m_lineJudges;
    Judge m_chairJudge;
    Judge m_assistantJudge;
};

#endif // JUDGESPANEL_H
