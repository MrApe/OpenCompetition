#ifndef SCOREINPUTWIDGET_H
#define SCOREINPUTWIDGET_H

#include "modules/abstractmodule.h"
#include "data/competition.h"

namespace Ui {
    class ScoreInputWidget;
}

class ScoreInputWidget : public AbstractModule {
    Q_OBJECT
public:
    ScoreInputWidget(const QString& name,Competition* competition, QWidget *parent = 0);
    ~ScoreInputWidget();

signals:
    void competitionChanged();
    void groupChanged(Group* group);

public slots:
    void updateWidget();
    void showStartList();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ScoreInputWidget *ui;
    Competition* m_competition;

private slots:
    void on_startlist_itemSelectionChanged();
};

#endif // SCOREINPUTWIDGET_H
