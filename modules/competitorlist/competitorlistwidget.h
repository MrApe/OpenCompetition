#ifndef COMPETITORLISTWIDGET_H
#define COMPETITORLISTWIDGET_H

#include <QWidget>
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
    void changeCompetitorName();
    void changeCompetitorBirth();
    void changeCompetitorGender(const QString& genderString);
    void removeCompetitorFromTeam();
    void showGroupListContextMenu();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CompetitorListWidget *ui;
    Competition* m_competition;
    Competitor* m_shownCompetitor;
    QList<Group *> m_groupsOfShownCompetitor;
    QList<Competitor> m_competitors;

    void updateCompetitorList();
    void updateTeamList();

signals:
    void competitionChanged();

private slots:
    void on_addCompetitor_clicked();
    void addCompetitor(Group* group);
};

#endif // COMPETITORLISTWIDGET_H
