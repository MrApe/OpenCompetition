#ifndef CLUB_H
#define CLUB_H

#include "QString"

class Club
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


private:
    QString m_name;
};

#endif // CLUB_H
