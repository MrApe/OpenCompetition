#include "clublistwidget.h"
#include "ui_clublistwidget.h"

ClubListWidget::ClubListWidget(const QString& name, Competition* comp,QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::ClubListWidget),
    m_competition(comp)
{
    ui->setupUi(this);

    connect(ui->clubTable,SIGNAL(itemSelectionChanged()),this,SLOT(updateDescription()));

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
    if (comp != NULL)
    {
        updateClubList();
    }
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

    for (;ui->clubTable->rowCount()>0;ui->clubTable->removeRow(0));
    ui->clubTable->setSortingEnabled(false);
    for (QMap<Club,QList<Group> >::iterator i = m_clublist.begin(); i != m_clublist.end();i++)
    {
        ui->clubTable->insertRow(0);

        QString club = i.key().getName();
        QTableWidgetItem* clubItem = new QTableWidgetItem(club);
        ui->clubTable->setItem(0,0,clubItem);

        QString groups;
        for (QList<Group>::iterator j = m_clublist[club].begin();j!=m_clublist[club].end();j++)
        {
            groups.append("(");
            groups.append(Group::categorieToString((*j).getType()));
            groups.append("|");
            groups.append(Group::ageToString((*j).getAge()));
            groups.append(") ");
        }
        QTableWidgetItem* starterItem = new QTableWidgetItem(groups);
        ui->clubTable->setItem(0,1,starterItem);
    }
    ui->clubTable->setSortingEnabled(true);
    if (ui->clubTable->rowCount() > 0) ui->clubTable->selectRow(0);
}

void ClubListWidget::updateDescription()
{
    for (;ui->teamTable->rowCount()>0;ui->teamTable->removeRow(0));
    if (ui->clubTable->selectedItems().size() > 0)
    {
        QString club = ui->clubTable->selectedItems().at(0)->text();
        ui->name->setText(club);

        for (int j = 0;j< m_clublist[club].size();j++)
        {
            ui->teamTable->insertRow(0);
            QTableWidgetItem* type = new QTableWidgetItem(Group::categorieToString(m_clublist[club].at(j).getType()));
            ui->teamTable->setItem(0,0,type);
            QTableWidgetItem* age = new QTableWidgetItem(Group::ageToString(m_clublist[club].at(j).getAge()));
            ui->teamTable->setItem(0,1,age);

            QString comp;
            for (int i = 0; i < m_clublist[club].at(j).getCompetitors().size();i++)
            {
               comp.append(m_clublist[club].at(j).getCompetitors().at(i).getName());
               comp.append("(");
               comp.append(QString::number(m_clublist[club].at(j).getCompetitors().at(i).getBirth()));
               comp.append(")");
               if (i < m_clublist[club].at(j).getCompetitors().size()-1){
                   comp.append(", ");
               }
            }
            QTableWidgetItem* starter = new QTableWidgetItem(comp);
            ui->teamTable->setItem(0,2,starter);
        }
    }
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
