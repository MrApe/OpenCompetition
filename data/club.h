#ifndef CLUB_H
#define CLUB_H

#include "QString"
#include "abstractXMLElement.h"

class Club : public AbstractXMLElement
{
public:
    Club(const QString& name);

    bool operator ==(const Club& other) const;
    bool operator!=(const Club& other) const;
    bool operator<(const Club& right) const;
    bool operator>(const Club& right) const;

    /*!
     * Inline getter and setter
     */
    inline void setName(const QString& name){
        m_name = name;}
    inline const QString& getName() const {
        return m_name;}
    inline QString toString() const {
        return m_name;}

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);

    /*!
      This method reades Club data from an xml element.
      */
    virtual void readFromDomElement(QDomElement &element);


private:
    QString m_name;
};

#endif // CLUB_H
