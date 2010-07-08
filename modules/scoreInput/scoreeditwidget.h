#ifndef SCOREEDITWIDGET_H
#define SCOREEDITWIDGET_H

#include <QWidget>
#include "data/competition.h"
#include "data/group.h"

namespace Ui {
    class ScoreEditWidget;
}

class ScoreEditWidget : public QWidget {
    Q_OBJECT
public:
    ScoreEditWidget(Competition* comp,QWidget *parent = 0);
    ~ScoreEditWidget();

signals:
    void scoreChanged();

public slots:
    void updateWidget();
    void changeGroup(Group* newGroup);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ScoreEditWidget *ui;
    Competition* m_competition;
    Group* m_group;
};

#endif // SCOREEDITWIDGET_H
