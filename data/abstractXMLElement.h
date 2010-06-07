#ifndef ABSTRACTXMLELEMENT_H
#define ABSTRACTXMLELEMENT_H

#include <QDomElement>

class AbstractXMLElement
{
public:
    /*!
      This method creates a DomElement out of this object and returns it to the caller.
      @return The current object as DomElement.
      */
    virtual QDomElement toDomElement(QDomDocument* parentDocument) = 0;
};

#endif // ABSTRACTXMLELEMENT_H
