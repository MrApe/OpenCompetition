#ifndef COMPETITORLISTWIDGET_H
#define COMPETITORLISTWIDGET_H

#include "modules/abstractmodule.h"
#include "data/competition.h"

namespace Ui {
    class CompetitorListWidget;
}

class CompetitorListWidget : public AbstractModule {
    Q_OBJECT
public:
    CompetitorListWidget(const QString& name,Competition* comp, QWidget *parent = 0);
    ~CompetitorListWidget();

public slots:
    void updateWidget();
    void updateCompetition(Competition* comp);
    void updateProperties();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CompetitorListWidget *ui;
    Competition* m_competition;
    QList<Competitor> m_competitors;

    void updateCompetitorList();
};

#endif // COMPETITORLISTWIDGET_H
