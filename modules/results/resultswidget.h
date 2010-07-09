#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include "modules/abstractmodule.h"
#include "data/competition.h"

namespace Ui {
    class ResultsWidget;
}

class ResultsWidget : public AbstractModule {
    Q_OBJECT
public:
    ResultsWidget(const QString& name,Competition* comp,QWidget *parent = 0);
    ~ResultsWidget();

public slots:
    void updateWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ResultsWidget *ui;
    Competition* m_competition;

    void showStartList();

private slots:
    void on_pushButton_clicked();
};

#endif // RESULTSWIDGET_H
