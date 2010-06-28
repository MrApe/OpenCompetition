#include "clublistwidget.h"
#include "ui_clublistwidget.h"

ClubListWidget::ClubListWidget(const QString& name, Competition* comp,QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::ClubListWidget),
    m_competition(comp)
{
    ui->setupUi(this);

    updateClubList();

    //Sort items in club View
    ui->clubTable->sortByColumn(0);
    ui->clubTable->setSortingEnabled(true);
}

ClubListWidget::~ClubListWidget()
{
    delete ui;
}

void ClubListWidget::updateCompetition(Competition *comp)
{
    m_competition = comp;
    updateClubList();
}

void ClubListWidget::updateWidget()
{
    if (m_competition != NULL)
    {
        updateClubList();
    }
}


void ClubListWidget::updateClubList()
{
    m_clublist.clear();
    for (int i = 0; i < m_competition->getStarter().size();i++)
    {
        m_clublist[m_competition->getStarter().at(i).getClub()].insert(0,m_competition->getStarter().at(i));
    }

    ui->clubTable->clearContents();
    ui->clubTable->setSortingEnabled(false);
    for (QMap<Club,QList<Group> >::iterator i = m_clublist.begin(); i != m_clublist.end();i++)
    {
        ui->clubTable->insertRow(0);

        QString club = i.key().getName();
        QTableWidgetItem* newClub = new QTableWidgetItem(club);
        ui->clubTable->setItem(0,0,newClub);

        QString groups;
        for (QList<Group>::iterator j = m_clublist[club].begin();j!=m_clublist[club].end();j++)
        {
            groups.append("(");
            groups.append(Group::categorieToString((*j).getType()));
            groups.append("|");
            groups.append(Group::ageToString((*j).getAge()));
            groups.append(") ");
        }
        QTableWidgetItem* newStarter = new QTableWidgetItem(groups);
        ui->clubTable->setItem(0,1,newStarter);
    }
    ui->clubTable->setSortingEnabled(true);
}

void ClubListWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
