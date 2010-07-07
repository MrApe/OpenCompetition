#include "startdataeditor.h"
#include "ui_startdataeditor.h"

StartDataEditor::StartDataEditor(Competition* comp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartDataEditor),
    m_competition(comp),
    m_trainingTime(comp->getTrainingTime()),
    m_competitionTime(comp->getCompetitionTime()),
    m_starterOffset(comp->getStarterOffset())
{
    ui->setupUi(this);

    connect(ui->trainingTime,SIGNAL(timeChanged(QTime)),m_competition,SLOT(setTrainingTime(QTime)));
    connect(ui->competitionTime,SIGNAL(timeChanged(QTime)),m_competition,SLOT(setCompetitionTime(QTime)));
    connect(ui->offset,SIGNAL(timeChanged(QTime)),m_competition,SLOT(setStarterOffset(QTime)));
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
    ui->offset->setTime(m_starterOffset);
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
