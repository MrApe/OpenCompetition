#include "scoreeditwidget.h"
#include "ui_scoreeditwidget.h"

ScoreEditWidget::ScoreEditWidget(Competition* comp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScoreEditWidget),
    m_competition(comp),
    m_group(NULL)
{
    ui->setupUi(this);

    #if QT_VERSION > 0x040602 // needs Qt 4.6.2 or better
        ui->chair->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    #endif

    #if QT_VERSION > 0x040602 // needs Qt 4.6.2 or better
        ui->line->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    #endif

//    connect(ui->artisticTable,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(itemChanged(QTableWidgetItem*)));
//    connect(ui->executionTable,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(itemChanged(QTableWidgetItem*)));
//    connect(ui->difficultyTable,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(itemChanged(QTableWidgetItem*)));
//    connect(ui->chair,SIGNAL(editingFinished()),this,SLOT(sendScore()));
//    connect(ui->line,SIGNAL(editingFinished()),this,SLOT(sendScore()));
    connect(ui->save,SIGNAL(clicked()),this,SLOT(sendScore()));
}

ScoreEditWidget::~ScoreEditWidget()
{
    delete ui;
}

void ScoreEditWidget::updateWidget()
{
    if (m_competition != NULL && m_group != NULL)
    {
        QTableWidgetItem* item;
        Judge current;
        ui->artisticTable->setRowCount(m_competition->getJudgesPanel()->getArtisticJudges().size());
        ui->artisticTable->clearContents();
        for (int a = 0; a < m_competition->getJudgesPanel()->getArtisticJudges().size(); a++)
        {
            current = *(m_competition->getJudgesPanel()->getArtisticJudges().at(a));
            item = new QTableWidgetItem(current.getName());
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->artisticTable->setItem(a,0,item);

            item = new QTableWidgetItem(QString::number(m_group->getScoreFromJudge(current),'f',4));
            ui->artisticTable->setItem(a,1,item);
        }

        ui->executionTable->setRowCount(m_competition->getJudgesPanel()->getExecutionJudges().size());
        ui->executionTable->clearContents();
        for (int a = 0; a < m_competition->getJudgesPanel()->getExecutionJudges().size(); a++)
        {
            current = *(m_competition->getJudgesPanel()->getExecutionJudges().at(a));
            item = new QTableWidgetItem(current.getName());
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->executionTable->setItem(a,0,item);

            item = new QTableWidgetItem(QString::number(m_group->getScoreFromJudge(current),'f',4));
            ui->executionTable->setItem(a,1,item);
        }

        ui->difficultyTable->setRowCount(m_competition->getJudgesPanel()->getDifficultyJudges().size());
        ui->difficultyTable->clearContents();
        for (int a = 0; a < m_competition->getJudgesPanel()->getDifficultyJudges().size(); a++)
        {
            current = *(m_competition->getJudgesPanel()->getDifficultyJudges().at(a));
            item = new QTableWidgetItem(current.getName());
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->difficultyTable->setItem(a,0,item);

            item = new QTableWidgetItem(QString::number(m_group->getScoreFromJudge(current),'f',4));
            ui->difficultyTable->setItem(a,1,item);
        }

        if (!m_competition->getJudgesPanel()->getChairJudges().isEmpty())
        {
            current = *(m_competition->getJudgesPanel()->getChairJudges().at(0));
            ui->chair->setText(QString::number(m_group->getScoreFromJudge(current),'f',4));
        }

        double line = 0.0;
        for (int a = 0; a < m_competition->getJudgesPanel()->getLineJudges().size(); a++)
        {
            current = *(m_competition->getJudgesPanel()->getLineJudges().at(a));
            line += m_group->getScoreFromJudge(current);
        }

        ui->line->setText(QString::number(line,'f',4));

        ui->finalScore->setText(QString::number(m_group->getFinalScore(),'f',3));
    }

}

void ScoreEditWidget::changeGroup(Group *newGroup)
{
    if (newGroup != NULL)
    {
        m_group = newGroup;
        updateWidget();
    }
}

void ScoreEditWidget::itemChanged(QTableWidgetItem *)
{
    sendScore();
}

void ScoreEditWidget::sendScore()
{
    if (m_group != NULL && m_competition != NULL)
    {
        m_group->getScores().clear();
        for (int i=0; i< ui->artisticTable->rowCount(); i++)
        {
            Judge j = m_competition->getJudgesPanel()->getJudgeByName(ui->artisticTable->item(i,0)->text());
            Score s(Judge::ARTISTIC,j,ui->artisticTable->item(i,1)->text().toDouble());
            m_group->getScores().append(s);
        }

        for (int i=0; i< ui->executionTable->rowCount(); i++)
        {
            Judge j = m_competition->getJudgesPanel()->getJudgeByName(ui->executionTable->item(i,0)->text());
            Score s(Judge::EXECUTION,j,ui->executionTable->item(i,1)->text().toDouble());
            m_group->getScores().append(s);
        }

        for (int i=0; i< ui->difficultyTable->rowCount(); i++)
        {
            Judge j = m_competition->getJudgesPanel()->getJudgeByName(ui->difficultyTable->item(i,0)->text());
            Score s(Judge::DIFFICULTY,j,ui->difficultyTable->item(i,1)->text().toDouble());
            m_group->getScores().append(s);
        }

        if (m_competition->getJudgesPanel()->getChairJudges().size() > 0)
        {
            Judge j = *(m_competition->getJudgesPanel()->getChairJudges().at(0));
            Score s(Judge::CHAIR,j,ui->chair->text().toDouble());
            m_group->getScores().append(s);
        }

        if (m_competition->getJudgesPanel()->getLineJudges().size() > 0)
        {
            Judge j = *(m_competition->getJudgesPanel()->getLineJudges().at(0));
            Score s(Judge::LINE,j,ui->line->text().toDouble());
            m_group->getScores().append(s);
        }

    }

    emit scoreChanged();

}

void ScoreEditWidget::changeEvent(QEvent *e)
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
