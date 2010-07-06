#include "propertieswidget.h"
#include "ui_propertieswidget.h"

PropertiesWidget::PropertiesWidget(Competition* competition, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertiesWidget),
    m_competition(competition)
{
    ui->setupUi(this);
    updateProperties();
}

PropertiesWidget::~PropertiesWidget()
{
    delete ui;
}

void PropertiesWidget::changeEvent(QEvent *e)
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

void PropertiesWidget::updateProperties()
{
    setProperty(tr("Name"),m_competition->getName());
    setProperty(tr("Date"),m_competition->getDate());
    setProperty(tr("Time"),m_competition->getTime());
    setProperty(tr("Ranking?"),m_competition->isRLT());
    setProperty(tr("Description"),m_competition->getDescription());
    setProperty(tr("Competitors"),m_competition->getStarter().size());
    setProperty(tr("Judges assigned"),m_competition->getJudgesPanel()->size());
    setProperty(tr("Judges pool"),m_competition->getJudgesPanel()->poolSize());
}

void PropertiesWidget::addProperty(QString key, QString value)
{
    ui->propTable->insertRow(0);
    QTableWidgetItem* keyItem = new QTableWidgetItem(key);
    ui->propTable->setItem(0,0,keyItem);
    QTableWidgetItem* valieItem = new QTableWidgetItem(value);
    ui->propTable->setItem(0,1,valieItem);
}

void PropertiesWidget::setProperty(QString key, QString value)
{
    QList<QTableWidgetItem *> keyList = ui->propTable->findItems(key,Qt::MatchExactly);
    if (keyList.isEmpty())
    {
        addProperty(key,value);
    } else
    {
        for (int i=0;i < keyList.size(); i++)
        {
            int row = keyList.at(i)->row();
            if (keyList.at(i)->column() == 0)
            {
                ui->propTable->item(row,1)->setText(value);
            }
        }
    }
}

void PropertiesWidget::setProperty(QString key, int value)
{
    setProperty(key,QString::number(value));
}

void PropertiesWidget::setProperty(QString key, QDate value)
{
    setProperty(key,value.toString("dd.MM.yyyy"));
}

void PropertiesWidget::setProperty(QString key, QTime value)
{
    setProperty(key,value.toString("hh:mm"));
}

void PropertiesWidget::setProperty(QString key, Group::categorieType value)
{
    setProperty(key,Group::categorieToString(value));
}

void PropertiesWidget::setProperty(QString key, Group::ageType value)
{
    setProperty(key,Group::ageToString(value));
}

void PropertiesWidget::setProperty(QString key, bool value)
{
    setProperty(key,value?tr("yes"):tr("no"));
}


