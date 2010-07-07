#include "startlistwidget.h"
#include "ui_startlistwidget.h"
#include "modules/startlist/startdataeditor.h"
#include <QDockWidget>

StartListWidget::StartListWidget(const QString &name, Competition *comp, QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::StartListWidget),
    m_competition(comp),
    m_trainingOder(BY_CLUB)
{
    ui->setupUi(this);
    ui->traininglist->setColumnWidth(0,50);
    ui->traininglist->setColumnWidth(1,50);
    ui->traininglist->setColumnWidth(2,200);
    ui->traininglist->setColumnWidth(3,200);

    connect(this,SIGNAL(trainingOrderChanged()),this,SLOT(buildTrainingList()));
    connect(this,SIGNAL(trainingOrderChanged()),this,SLOT(showTrainingList()));

    QDockWidget* edDock = new QDockWidget(tr("Startdata Editor"),this);
    StartDataEditor* editor = new StartDataEditor(comp);
    edDock->setWidget(editor);
    addDockWidget(Qt::RightDockWidgetArea,edDock);
    connect(this,SIGNAL(competitionChanged()),editor,SLOT(updateValues()));
    connect(editor,SIGNAL(sortingChanged(trainingOrderType)),this,SLOT(changeTrainingOrder(trainingOrderType)));
    connect(editor,SIGNAL(rebuildTrainingListRequested()),this,SLOT(forceUpdateTrainingList()));
    connect(editor,SIGNAL(rebuildStartListRequested()),this,SLOT(forceUpdateStartList()));
}

StartListWidget::~StartListWidget()
{
    delete ui;
}

void StartListWidget::changeTrainingOrder(trainingOrderType newOrder)
{
    m_trainingOder = newOrder;
    emit trainingOrderChanged();
}

void StartListWidget::forceUpdateStartList()
{
    buildStartList();
    showStartList();
}

void StartListWidget::forceUpdateTrainingList()
{
    buildTrainingList();
    showTrainingList();
}

void StartListWidget::updateWidget()
{
    if(m_competition != NULL)
    {
        if (m_competition->getStartList().isEmpty())
        {
           buildStartList();
        }
        showStartList();

        if (m_competition->getTrainingList().isEmpty())
        {
            buildTrainingList();
        }
        showTrainingList();
    }
}

void StartListWidget::buildStartList()
{
    m_competition->getStartList().clear();
    QMap<Group::ageType, QMap<Group::categorieType, QList<Group*> > > sortedStartList;
    QList<Group>::iterator gIt;
    for (gIt = m_competition->getStarter().begin();
         gIt != m_competition->getStarter().end();
         gIt++)
    {
        sortedStartList[(*gIt).getAge()][(*gIt).getType()].append(&(*gIt));
    }

    for (int age = 0; age < sortedStartList.keys().size(); age++)
    {
        Group::ageType currentAge = sortedStartList.keys().at(age);
        for (int cat = 0; cat < sortedStartList[currentAge].keys().size(); cat++)
        {
            Group::categorieType currentCat = sortedStartList[currentAge].keys().at(cat);
            for (int i = 0; i < sortedStartList[currentAge][currentCat].size(); i++)
            {
                Group* gPtr = sortedStartList[currentAge][currentCat].at(i);
                m_competition->getStartList().append(gPtr);
            }
        }
    }
}

void StartListWidget::showStartList()
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

        QTime base = m_competition->getCompetitionTime();
        QTime off = m_competition->getStarterOffset();
        QTime start = base.addSecs((off.minute()*60 + off.second())*row);
        QString time = start.toString(QObject::tr("hh:mm")) ;
        item = new QTableWidgetItem(time);
        ui->startlist->setItem(row,4,item);
    }
}

void StartListWidget::buildTrainingList()
{
    m_competition->getTrainingList().clear();

    if (m_trainingOder == BY_STARTING_ORDER)
    {
        m_competition->getTrainingList().append(m_competition->getStartList());
    }

    if  (m_trainingOder == BY_CLUB)
    {
        QMap<Club, QList<Group*> > clubStartList;
        QList<Group>::iterator gIt;
        for (gIt = m_competition->getStarter().begin();
             gIt != m_competition->getStarter().end();
             gIt++)
        {
            clubStartList[(*gIt).getClub()].append(&(*gIt));
        }

        QList<Club>::iterator keyIt;
        for (keyIt = clubStartList.keys().begin();
             keyIt != clubStartList.keys().end();
             keyIt++)
        {
            m_competition->getTrainingList().append(clubStartList[(*keyIt)]);
        }
    }

}

void StartListWidget::showTrainingList()
{
    QTableWidgetItem* item;
    int rows = m_competition->getTrainingList().size();
    ui->traininglist->setRowCount(rows);
    ui->traininglist->clearContents();
    for (int row = 0; row < rows; row++)
    {
        Group* current = m_competition->getTrainingList().at(row);
        item = new QTableWidgetItem(Group::ageToString(current->getAge()));
        ui->traininglist->setItem(row,0,item);

        item = new QTableWidgetItem(Group::categorieToString(current->getType()));
        ui->traininglist->setItem(row,1,item);

        item = new QTableWidgetItem(current->getClub().toString());
        ui->traininglist->setItem(row,2,item);


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
        ui->traininglist->setItem(row,3,item);

        QTime base = m_competition->getTrainingTime();
        QTime off = m_competition->getTrainingOffset();
        QTime start = base.addSecs((off.minute()*60 + off.second())*row);
        QString time = start.toString(QObject::tr("hh:mm")) ;
        item = new QTableWidgetItem(time);
        ui->traininglist->setItem(row,4,item);
    }
}

void StartListWidget::changeEvent(QEvent *e)
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
