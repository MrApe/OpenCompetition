#ifndef JUDGE_H
#define JUDGE_H

#include <QList>
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
        ASSISTANT,
        LINE
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

    /*!
      This mehod comverts the pools to string.
      @param pool The pool.
      @return Pool as QString.
      */
    static QString poolListToString(QList<scoreType> pool);

    /*!
      This method creates a judge out of it's string representation.
      It only works, if the string was created by the Judge::toString() method.
      @param stringRepresenation The judge as string.
      @return The judge.
      */
    static const Judge judgeFromString(const QString& stringRepresentation);

    Judge(const QString& name,
          brevetType brevet);

    Judge();

    bool operator ==(const Judge& other) const;
    bool operator ==(Judge* other) const;
    bool operator !=(const Judge& other) const;
    bool operator !=(Judge* other) const;

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*!
      This method reads the judge data from an xml-element.
      */
    virtual void readFromDomElement(QDomElement &element);

    /*!
      This method adds a pool for this judge.
      @param pool The pool this judge belongs to.
    */
    void addPool(scoreType pool);

    /*!
      This method removes a pool from the judge.
      @param pool The pool to remove.
      */
    void removePool(scoreType pool);

    /*
     * Inline getter and setter
     */
    inline void setBrevet(brevetType brevet){m_brevet = brevet;}
    inline brevetType getBrevet() const {return m_brevet;}
    /*!
      This method returns the pools this judge belongs to as a list.
      @return The pools of this judge.
      */
    inline const QList<scoreType>& getPools() const{return m_pools;}

    /*!
      This method converts the judge to a string.
      */
    const QString toString();

private:
    brevetType m_brevet;
    QList<scoreType> m_pools;

};

#endif // JUDGE_H
