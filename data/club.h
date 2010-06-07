#ifndef CLUB_H
#define CLUB_H

#include "QString"
#include "abstractXMLElement.h"

class Club : public AbstractXMLElement
{
public:
    Club(const QString& name);

    /*!
     * Inline getter and setter
     */
    inline void setName(const QString& name){
        m_name = name;}
    inline const QString& getName() const {
        return m_name;}

    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument);


private:
    QString m_name;
};

#endif // CLUB_H
