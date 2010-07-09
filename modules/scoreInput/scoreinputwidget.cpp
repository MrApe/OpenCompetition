#include "scoreinputwidget.h"
#include "ui_scoreinputwidget.h"
#include "modules/scoreInput/scoreeditwidget.h"
#include <QDockWidget>

ScoreInputWidget::ScoreInputWidget(const QString &name, Competition *competition, QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::ScoreInputWidget),
    m_competition(competition)
{
    ui->setupUi(this);
    ui->startlist->setColumnWidth(0,50);
    ui->startlist->setColumnWidth(1,80);
    ui->startlist->setColumnWidth(2,200);
    ui->startlist->setColumnWidth(3,250);

    ScoreEditWidget* scoreEW = new ScoreEditWidget(m_competition);
    QDockWidget* edDock = new QDockWidget(tr("Score Editor"),this);
    edDock->setWidget(scoreEW);
    addDockWidget(Qt::BottomDockWidgetArea,edDock);
    connect(this,SIGNAL(competitionChanged()),scoreEW,SLOT(updateWidget()));
    connect(this,SIGNAL(groupChanged(Group*)),scoreEW,SLOT(changeGroup(Group*)));

    connect(scoreEW,SIGNAL(scoreChanged()),this,SIGNAL(competitionChanged()));
    connect(scoreEW,SIGNAL(scoreChanged()),this,SLOT(updateWidget()));
}

ScoreInputWidget::~ScoreInputWidget()
{
    delete ui;
}

void ScoreInputWidget::updateWidget()
{
    if(m_competition != NULL)
    {
        showStartList();
    }
}

void ScoreInputWidget::showStartList()
{
    QTableWidgetItem* item;
    int rows = m_competition->getStartList().size();
    ui->startlist->setRowCount(rows);
    ui->startlist->clearContents();
    for (int row = 0; row < rows; row++)
    {
        Group* current = m_competition->getStartList().at(row);
        item = new QTableWidgetItem(Group::ageToString(current->getAge()));
        ui->startlist->setItem(row,0,item);

        item = new QTableWidgetItem(Group::categorieToString(current->getType()));
        ui->startlist->setItem(row,1,item);

        item = new QTableWidgetItem(current->getClub().toString());
        ui->startlist->setItem(row,2,item);


        QString comp;
        for (int i = 0; i < current->getCompetitors().size();i++)
        {
           comp.append(current->getCompetitors().at(i).getName());
           comp.append("(");
           comp.append(QString::number(current->getCompetitors().at(i).getBirth()));
           comp.append(")");
           if (i < current->getCompetitors().size()-1){
               comp.append(", ");
           }
        }
        item = new QTableWidgetItem(comp);
        ui->startlist->setItem(row,3,item);

        item = new QTableWidgetItem(QString::number(current->getFinalScore(),'f',4));
        ui->startlist->setItem(row,4,item);
    }
}

void ScoreInputWidget::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ScoreInputWidget::on_startlist_itemSelectionChanged()
{
    if (ui->startlist->selectedItems().size() > 0)
    {
        Group* g = m_competition->getStartList().at(ui->startlist->selectedItems().at(0)->row());
        emit groupChanged(g);
    }
}
