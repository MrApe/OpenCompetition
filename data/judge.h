#ifndef JUDGE_H
#define JUDGE_H

#include "abstractperson.h"

class Judge : public AbstractPerson
{
public:
    enum scoreType{
        ARTISTIC,
        EXECUTION,
        DIFFICULTY,
        CHAIR,
        SUPERIOR,
        ASSISTANT
    };
    enum brevetType{
        NONE,
        LTV,
        DTB,
        FIG4,
        FIG3,
        FIG2,
        FIG1
    };

    Judge(const QString& name,
          scoreType score,
          brevetType brevet);

    /*
     * Inline getter and setter
     */
    inline void setScore(scoreType score){
        m_score = score;
    }
    inline void setBrevet(brevetType brevet){
        m_brevet = brevet;
    }
    inline scoreType getScore() const {
        return m_score;
    }
    inline brevetType getBrevet() const {
        return m_brevet;
    }

private:
    scoreType m_score;
    brevetType m_brevet;

};

#endif // JUDGE_H
