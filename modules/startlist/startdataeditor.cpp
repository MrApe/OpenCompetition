#include "startdataeditor.h"
#include "ui_startdataeditor.h"

StartDataEditor::StartDataEditor(Competition* comp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartDataEditor),
    m_competition(comp),
    m_trainingTime(comp->getTrainingTime()),
    m_competitionTime(comp->getCompetitionTime()),
    m_starterOffset(comp->getStarterOffset()),
    m_trainingOffset(comp->getTrainingOffset())
{
    ui->setupUi(this);

    connect(ui->trainingTime,SIGNAL(timeChanged(QTime)),m_competition,SLOT(setTrainingTime(QTime)));
    connect(ui->competitionTime,SIGNAL(timeChanged(QTime)),m_competition,SLOT(setCompetitionTime(QTime)));
    connect(ui->startOffset,SIGNAL(timeChanged(QTime)),m_competition,SLOT(setStarterOffset(QTime)));
    connect(ui->trainingOffset,SIGNAL(timeChanged(QTime)),m_competition,SLOT(setTrainingOffset(QTime)));

    connect(ui->byclub,SIGNAL(clicked()),this,SLOT(updateTrainingOrderType()));
    connect(ui->instartingorder,SIGNAL(clicked()),this,SLOT(updateTrainingOrderType()));

    connect(ui->rebuildStart,SIGNAL(clicked()),this,SIGNAL(rebuildStartListRequested()));
    connect(ui->rebuildTraining,SIGNAL(clicked()),this,SIGNAL(rebuildTrainingListRequested()));
}

StartDataEditor::~StartDataEditor()
{
    delete ui;
}

void StartDataEditor::updateValues()
{
    m_trainingTime = m_competition->getTrainingTime();
    ui->trainingTime->setTime(m_trainingTime);
    m_competitionTime = m_competition->getCompetitionTime();
    ui->competitionTime->setTime(m_competitionTime);
    m_starterOffset = m_competition->getStarterOffset();
    ui->startOffset->setTime(m_starterOffset);
    m_trainingOffset = m_competition->getTrainingOffset();
    ui->trainingOffset->setTime(m_trainingOffset);
}

void StartDataEditor::updateTrainingOrderType()
{
    if (ui->byclub->isChecked()) {
        emit sortingChanged(BY_CLUB);
    }

    if (ui->instartingorder->isChecked()) {
        emit sortingChanged(BY_STARTING_ORDER);
    }
}

void StartDataEditor::changeEvent(QEvent *e)
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
