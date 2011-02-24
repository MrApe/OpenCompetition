#ifndef JUDGESPANELWIDGET_H
#define JUDGESPANELWIDGET_H

#include <QWidget>
#include <QMap>
#include <QTableWidgetItem>
#include <QDropEvent>

#include "modules/abstractmodule.h"
#include "data/competition.h"

namespace Ui {
    class JudgesPanelWidget;
}

class JudgesPanelWidget : public AbstractModule {
    Q_OBJECT
public:
    JudgesPanelWidget(const QString& name,Competition* comp,QWidget *parent = 0);
    ~JudgesPanelWidget();

public slots:
    void updateWidget();

signals:
    void competitionChanged();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::JudgesPanelWidget *ui;
    Competition* m_competition;
    QMap<QTableWidgetItem*, Judge*> m_judgesItemCache;

    void updateJudgesPool();
    void updateJudges(Judge::scoreType type);

private slots:
    void changeJudge(QTableWidgetItem* changedItem);
    void saveChanges();
    void removeJudge();

};

#endif // JUDGESPANELWIDGET_H
