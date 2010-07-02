#include "competitorlistwidget.h"
#include "ui_competitorlistwidget.h"

CompetitorListWidget::CompetitorListWidget(const QString &name,Competition* comp, QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::CompetitorListWidget),
    m_competition(comp),
    m_shownCompetitor(NULL),
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
        QString name, birth, gender;
        int selectedRow;
        selectedRow = ui->competitorTable->selectedItems().at(0)->row();
        name = ui->competitorTable->item(selectedRow,0)->text();
        birth = ui->competitorTable->item(selectedRow,1)->text();
        gender = ui->competitorTable->item(selectedRow,2)->text();

        //find competitor
        bool found = false;
        int groupsSize =  m_competition->getStarter().size();
        for (int group = 0; group < groupsSize && !found; group++)
        {
            int starterSize = m_competition->getStarter().at(group).getCompetitors().size();
            for (int starter = 0; starter < starterSize && ! found; starter++)
            {
                if (m_competition->getStarter().at(group).getCompetitors().at(starter).getName() == name&&
                    m_competition->getStarter().at(group).getCompetitors().at(starter).getBirth() == birth.toInt() &&
                    m_competition->getStarter().at(group).getCompetitors().at(starter).getGender() == (gender==QObject::tr("male")?Competitor::MALE:Competitor::FEMALE))
                {
                    m_shownCompetitor = &(m_competition->getStarter().at(group).getCompetitors().at(starter));
                }
            }

        }

        ui->name->setText(name);
        ui->birth->setValue(birth.toInt());
        ui->gender->setCurrentIndex(ui->gender->findText(gender));
        ui->club->setText(m_shownCompetitor->getClub().toString());
    }


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
