#ifndef JUDGESTABLEWIDGET_H
#define JUDGESTABLEWIDGET_H

#include <QTableWidget>
#include <QDragMoveEvent>
#include <QDropEvent>
#include "data/judge.h"

class judgesTableWidget : public QTableWidget
{
    Q_OBJECT
public:
   judgesTableWidget(QWidget *parent = 0);

   /*!
     This method checks wether the given judge is listed in this table.
     @return True is the judge is listed.
     */
   bool isListed(QString name);

   /*!
     This is an overloaded function of isListed(QString name) checks wether the given judge is listed in this table.
     @return True is the judge is listed.
     */
   bool isListed(QTableWidgetItem name);

   /*!
     This method removes the given judge by name.
     @return The removed judge.
     */
   const Judge remove(QString name);

protected:
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dropEvent(QDropEvent *event);

signals:

public slots:

};

#endif // JUDGESTABLEWIDGET_H
