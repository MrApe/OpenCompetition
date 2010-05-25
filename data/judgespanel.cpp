#include "judgespanel.h"

JudgesPanel::JudgesPanel(std::vector<Judge> artisticJudges,
                         std::vector<Judge> executionJudges,
                         std::vector<Judge> difficultyJudges,
                         std::vector<Judge> superiorJury,
                         std::vector<Judge> lineJudges,
                         Judge chairJudge,
                         Judge assistantJudge):
    m_artisticJudges(artisticJudges),
    m_executionJudges(executionJudges),
    m_difficultyJudges(difficultyJudges),
    m_superiorJury(superiorJury),
    m_lineJudges(lineJudges),
    m_chairJudge(chairJudge),
    m_assistantJudge(assistantJudge)
{
}
