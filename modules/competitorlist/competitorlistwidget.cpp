#include "competitorlistwidget.h"
#include "ui_competitorlistwidget.h"
#include <QMessageBox>

CompetitorListWidget::CompetitorListWidget(const QString &name,Competition* comp, QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::CompetitorListWidget),
    m_competition(comp),
    m_shownCompetitor(NULL),
    m_groupsOfShownCompetitor(),
    m_competitors()
{
    ui->setupUi(this);

    updateCompetitorList();

    //Sort items in club View
    ui->competitorTable->sortByColumn(0);
    ui->competitorTable->setSortingEnabled(true);
}

CompetitorListWidget::~CompetitorListWidget()
{
    delete ui;
}

void CompetitorListWidget::updateCompetition(Competition *comp)
{
    m_competition = comp;
    if (comp != NULL)
    {
        updateCompetitorList();
    }
}

void CompetitorListWidget::updateWidget()
{
    if (m_competition!=0)
    {
        updateCompetitorList();
    }
}

void CompetitorListWidget::updateCompetitorList()
{
    ui->competitorTable->setSortingEnabled(false); //temoprary disable sorting
    if (m_competition != NULL)
    {
        //update local competitor List
        m_competitors.clear();
        for (int i = 0; i < m_competition->getStarter().size(); i++)
        {
            for (int j = 0; j < m_competition->getStarter().at(i).getCompetitors().size(); j++)
            {
                Competitor c(m_competition->getStarter().at(i).getCompetitors().at(j));
                if (!m_competitors.contains(c))
                {
                    m_competitors.append(c);
                }
            }
        }

        //set row count
        int size = m_competitors.size();
        ui->competitorTable->setRowCount(size);
        ui->competitorTable->clearContents();

        for (int i = 0; i < size; i++)
        {
            QTableWidgetItem* item;
            QString name = m_competitors.at(i).getName();
            item = new QTableWidgetItem(name);
            ui->competitorTable->setItem(i,0,item);

            QString birthString = QString::number(m_competitors.at(i).getBirth());
            item = new QTableWidgetItem(birthString);
            ui->competitorTable->setItem(i,1,item);

            Competitor::genderType gender = m_competitors.at(i).getGender();
            QString genderString = gender==Competitor::MALE?QObject::tr("male"):QObject::tr("female");
            item = new QTableWidgetItem(genderString);
            ui->competitorTable->setItem(i,2,item);
        }
    }
    ui->competitorTable->sortByColumn(0);
    ui->competitorTable->setSortingEnabled(true);
}

void CompetitorListWidget::updateProperties()
{
    if (ui->competitorTable->selectedItems().size() > 0)
    {
        //prepare variables
        m_groupsOfShownCompetitor.clear();
        QString name, birth, gender;
        int selectedRow;
        selectedRow = ui->competitorTable->selectedItems().at(0)->row();
        name = ui->competitorTable->item(selectedRow,0)->text();
        birth = ui->competitorTable->item(selectedRow,1)->text();
        gender = ui->competitorTable->item(selectedRow,2)->text();

        //find competitor
        QList<Group>::iterator group;
        for (group = m_competition->getStarter().begin(); group != m_competition->getStarter().end(); group++)
        {
            QList<Competitor>::iterator starter;
            for (starter = (*group).getCompetitors().begin(); starter != (*group).getCompetitors().end(); starter++)
            {
                if ((*starter).getName() == name&&
                    (*starter).getBirth() == birth.toInt() &&
                    (*starter).getGender() == (gender==QObject::tr("male")?Competitor::MALE:Competitor::FEMALE))
                {
                    m_shownCompetitor = &(*starter);
                    m_groupsOfShownCompetitor.append(&(*group));
                }
            }

        }

        ui->name->setText(name);
        ui->birth->setValue(birth.toInt());
        ui->gender->setCurrentIndex(ui->gender->findText(gender));
        ui->club->setText(m_shownCompetitor->getClub().toString());

        //find Teams
        updateTeamList();
    }
}

void CompetitorListWidget::updateTeamList()
{
    ui->teamTable->setRowCount(m_groupsOfShownCompetitor.size());
    for (int row = 0; row < m_groupsOfShownCompetitor.size(); row++)
    {
        QTableWidgetItem* item;
        QString groupType = Group::categorieToString(m_groupsOfShownCompetitor.at(row)->getType());
        item = new QTableWidgetItem(groupType);
        ui->teamTable->setItem(row,0,item);

        QString ageGroup = Group::ageToString(m_groupsOfShownCompetitor.at(row)->getAge());
        item = new QTableWidgetItem(ageGroup);
        ui->teamTable->setItem(row,1,item);

        QString comp;
        for (int starter = 0; starter < m_groupsOfShownCompetitor.at(row)->getCompetitors().size();starter++)
        {
           comp.append(m_groupsOfShownCompetitor.at(row)->getCompetitors().at(starter).getName());
           comp.append("(");
           comp.append(QString::number(m_groupsOfShownCompetitor.at(row)->getCompetitors().at(starter).getBirth()));
           comp.append(")");
           if (starter < m_groupsOfShownCompetitor.at(row)->getCompetitors().size()-1){
               comp.append(", ");
           }
        }
        item = new QTableWidgetItem(comp);
        ui->teamTable->setItem(0,2,item);
    }
    if (ui->teamTable->rowCount() > 0)
    {
        ui->teamTable->selectRow(0);
    }
}

void CompetitorListWidget::changeCompetitorName()
{
    m_shownCompetitor->setName(ui->name->text());
    int row = ui->competitorTable->selectedItems().at(0)->row();
    ui->competitorTable->item(row,0)->setText(ui->name->text());
}

void CompetitorListWidget::changeCompetitorBirth()
{
    int birth = ui->birth->value();
    if (birth > ui->birth->minimum())
    {
        m_shownCompetitor->setBirth(birth);
        int row = ui->competitorTable->selectedItems().at(0)->row();
        ui->competitorTable->item(row,1)->setText(QString::number(birth));
    }
}

void CompetitorListWidget::changeCompetitorGender(const QString &genderString)
{
    Competitor::genderType gen = genderString==QObject::tr("male")?
                                 Competitor::MALE:Competitor::FEMALE;
    m_shownCompetitor->setGender(gen);
    int row = ui->competitorTable->selectedItems().at(0)->row();
    ui->competitorTable->item(row,2)->setText(genderString);
}

void CompetitorListWidget::removeCompetitorFromTeam()
{
    QMessageBox warn;
    warn.setIcon(QMessageBox::Question);
    warn.setText(tr("Remove competitor?"));
    warn.setInformativeText(tr("This is the last membership of this competitor. Keep it as individual?"));
    warn.setDetailedText(tr("Answering no means deleting the competitior entirely from this competition."));
    warn.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    warn.setDefaultButton(QMessageBox::Yes);
    int ret = warn.exec();
    if (ret != QMessageBox::Cancel && ui->teamTable->selectedItems().size()>0)
    {
        int index = ui->teamTable->selectedItems().at(0)->row();
        m_groupsOfShownCompetitor.at(index)->getCompetitors().removeOne(*m_shownCompetitor);
        m_groupsOfShownCompetitor.at(index)->guessType();
        if (ret == QMessageBox::Yes)
        {
            QList<Competitor> list;
            list.append((*m_shownCompetitor));
            Group gr(list,
                     Group::guessAge(m_shownCompetitor->getBirth()),
                     m_shownCompetitor->getGender()==Competitor::MALE?
                        Group::INDIVIDUAL_MEN:Group::INDIVIDUAL_WOMEN,
                     m_shownCompetitor->getClub());
            m_competition->addGroup(gr);
        }
        m_groupsOfShownCompetitor.removeAt(index);
        //emit competitionChanged();
        if (ui->competitorTable->rowCount()>0)
        {
            ui->competitorTable->selectRow(0);
        }
    }
}

void CompetitorListWidget::reomveCompetitor()
{

}

void CompetitorListWidget::changeEvent(QEvent *e)
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
