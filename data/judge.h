#ifndef JUDGE_H
#define JUDGE_H

#include "abstractperson.h"
#include "abstractXMLElement.h"

class Judge : public AbstractPerson, public AbstractXMLElement
{
public:
    enum scoreType{
        NONE,
        ARTISTIC,
        EXECUTION,
        DIFFICULTY,
        CHAIR,
        SUPERIOR,
        ASSISTANT
    };
    
    /*!
      Returns the given score type as a string representation.
      @return String representation of the score type.
      */
    static QString scoreTypeToString(const scoreType& score);

    /*!
      Returns the given score type from string representation.
      @return score type.
      */
    static scoreType stringToScoreType(const QString& scoreString);
    
    enum brevetType{
        NO,
        LTV,
        DTB,
        FIG4,
        FIG3,
        FIG2,
        FIG1
    };
    
    /*!
      Returns the given brevet type as string representation.
      @return String representation of the brevet type.
      */
    static QString brevetTypeToString(const brevetType& brevet);

    /*!
      Returns the given score type from string representation.
      @return score type.
      */
    static brevetType stringToBrevetType(const QString& brevetString);

    Judge(const QString& name,
          scoreType score,
          brevetType brevet);

    Judge();

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*!
      This method reads the judge data from an xml-element.
      */
    virtual void readFromDomElement(QDomElement &element);

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
