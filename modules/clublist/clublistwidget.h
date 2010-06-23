#ifndef CLUBLISTWIDGET_H
#define CLUBLISTWIDGET_H

#include <QWidget>
#include "data/competition.h"
#include "data/club.h"
#include "data/group.h"

namespace Ui {
    class ClubListWidget;
}

class ClubListWidget : public QWidget {
    Q_OBJECT
public:
    ClubListWidget(Competition* comp, QWidget *parent = 0);
    ~ClubListWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ClubListWidget *ui;
    Competition* m_competition;
    QMap<Club,QVector<Group> > m_clublist;

    void updateClubList();
};

#endif // CLUBLISTWIDGET_H
