#ifndef STARTLISTWIDGET_H
#define STARTLISTWIDGET_H

#include "modules/abstractmodule.h"
#include "data/competition.h"
#include <QMainWindow>
#include "types.h"

namespace Ui {
    class StartListWidget;
}

class StartListWidget : public AbstractModule{
    Q_OBJECT

public:
    StartListWidget(const QString& name,Competition* comp, QWidget *parent = 0);
    ~StartListWidget();

signals:
    void trainingOrderChanged();
    void competitionChanged();

public slots:
    void updateWidget();
    void forceUpdateStartList();
    void forceUpdateTrainingList();
    void changeTrainingOrder(trainingOrderType newOrder);
    void buildTrainingList();
    void showTrainingList();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::StartListWidget *ui;
    Competition* m_competition;
    trainingOrderType m_trainingOder;

    void buildStartList();
    void showStartList();

};

#endif // STARTLISTWIDGET_H
