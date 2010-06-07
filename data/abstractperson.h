#ifndef ABSTRACTPERSON_H
#define ABSTRACTPERSON_H

#include "QString"

class AbstractPerson
{
public:
    AbstractPerson(const QString& name);

    /*!
      Inline getter and setter
      */
    inline QString getName() const{
        return m_name;}
    inline void setName(QString const name){
        m_name = name;
        }


protected:
   QString m_name;
};

#endif // ABSTRACTPERSON_H
