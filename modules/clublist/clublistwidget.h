#ifndef CLUBLISTWIDGET_H
#define CLUBLISTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QList>
#include "modules/abstractmodule.h"
#include "data/competition.h"
#include "data/club.h"
#include "data/group.h"

namespace Ui {
    class ClubListWidget;
}

class ClubListWidget : public AbstractModule {
    Q_OBJECT
public:
    ClubListWidget(const QString& name, Competition* comp, QWidget *parent = 0);
    ~ClubListWidget();

public slots:
    void updateWidget();
    void updateCompetition(Competition* comp);
    void updateDescription();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ClubListWidget *ui;
    Competition* m_competition;
    QMap<Club,QList<Group> > m_clublist;

    void updateClubList();
};

#endif // CLUBLISTWIDGET_H
