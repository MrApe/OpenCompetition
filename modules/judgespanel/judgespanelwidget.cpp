#include "judgespanelwidget.h"
#include "modules/judgespanel/judgeeditorwidget.h"
#include "ui_judgespanelwidget.h"
#include <QMessageBox>

JudgesPanelWidget::JudgesPanelWidget(const QString &name, Competition *comp, QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::JudgesPanelWidget),
    m_competition(comp),
    m_judgesItemDB()
{
    ui->setupUi(this);

    ui->judgesTable->setColumnWidth(0,200);
    ui->judgesTable->setColumnWidth(1,80);

    ui->artistic->setColumnWidth(0,200);
    ui->artistic->setColumnWidth(1,80);

    ui->execution->setColumnWidth(0,200);
    ui->execution->setColumnWidth(1,80);

    ui->difficulty->setColumnWidth(0,200);
    ui->difficulty->setColumnWidth(1,80);

    ui->chair->setColumnWidth(0,200);
    ui->chair->setColumnWidth(1,80);

    ui->superior->setColumnWidth(0,200);
    ui->superior->setColumnWidth(1,80);

    ui->line->setColumnWidth(0,200);
    ui->line->setColumnWidth(1,80);

    ui->assistant->setColumnWidth(0,200);
    ui->assistant->setColumnWidth(1,80);
}

JudgesPanelWidget::~JudgesPanelWidget()
{
    delete ui;
}

void JudgesPanelWidget::closeEvent(QCloseEvent *)
{
    saveChanges();
}

void JudgesPanelWidget::updateWidget()
{
    if (m_competition != NULL)
    {
        updateJudgesPool();
        updateJudges(Judge::ARTISTIC);
        updateJudges(Judge::EXECUTION);
        updateJudges(Judge::DIFFICULTY);
        updateJudges(Judge::CHAIR);
        updateJudges(Judge::SUPERIOR);
        updateJudges(Judge::LINE);
        updateJudges(Judge::ASSISTANT);
    }
}

void JudgesPanelWidget::updateJudgesPool()
{
    ui->judgesTable->setSortingEnabled(false);
    ui->judgesTable->setRowCount(m_competition->getJudgesPanel()->getPool().size());
    ui->judgesTable->clearContents();
    m_judgesItemDB.clear();
    QList<Judge>::iterator judge;
    int row = 0;
    QTableWidgetItem* item;
    for (judge = m_competition->getJudgesPanel()->getPool().begin();
         judge != m_competition->getJudgesPanel()->getPool().end();
         judge++)
    {
        item = new QTableWidgetItem((*judge).getName());
        ui->judgesTable->setItem(row,0,item);
        m_judgesItemDB[item] = &(*judge);
        item = new QTableWidgetItem(Judge::brevetTypeToString((*judge).getBrevet()));
        ui->judgesTable->setItem(row,1,item);
        m_judgesItemDB[item] = &(*judge);
        item = new QTableWidgetItem(Judge::poolListToString((*judge).getPools()));
        ui->judgesTable->setItem(row,2,item);
        m_judgesItemDB[item] = &(*judge);
        row++;
    }

    ui->judgesTable->setSortingEnabled(true);
}

void JudgesPanelWidget::updateJudges(Judge::scoreType type)
{
    QTableWidget* target;
    QList<Judge*> source;
    bool sometingToDo = true;
    switch (type){
    case Judge::ARTISTIC:
        target = ui->artistic;
        source = m_competition->getJudgesPanel()->getArtisticJudges();
        break;
    case Judge::EXECUTION:
        target = ui->execution;
        source = m_competition->getJudgesPanel()->getExecutionJudges();
        break;
    case Judge::DIFFICULTY:
        target = ui->difficulty;
        source = m_competition->getJudgesPanel()->getDifficultyJudges();
        break;
    case Judge::CHAIR:
        target = ui->chair;
        source = m_competition->getJudgesPanel()->getChairJudges();
        break;
    case Judge::SUPERIOR:
        target = ui->superior;
        source = m_competition->getJudgesPanel()->getSuperiorJury();
        break;
    case Judge::ASSISTANT:
        target = ui->assistant;
        source = m_competition->getJudgesPanel()->getAssistantJudges();
        break;
    case Judge::LINE:
        target = ui->assistant;
        source = m_competition->getJudgesPanel()->getLineJudges();
        break;
    default: //nothing to do
        sometingToDo = false;
    }

    if (sometingToDo){
        target->setRowCount(source.size());
        target->clearContents();
        QTableWidgetItem* item;
        for (int row = 0; row < source.size(); row++)
        {
            item = new QTableWidgetItem(source.at(row)->getName());
            target->setItem(row,0,item);
            item = new QTableWidgetItem(Judge::brevetTypeToString(source.at(row)->getBrevet()));
            target->setItem(row,1,item);
            item = new QTableWidgetItem(Judge::poolListToString(source.at(row)->getPools()));
            target->setItem(row,2,item);
        }
    }
}

void JudgesPanelWidget::changeJudge(QTableWidgetItem *changedItem)
{
    Judge* judgeToEdit = m_judgesItemDB[changedItem];
    JudgeEditorWidget editor(judgeToEdit);
    int ret = editor.exec();
    if (ret == QDialog::Accepted)
    {
        judgeToEdit->setName(editor.getName());
        judgeToEdit->setBrevet(editor.getBrevet());
        for (int i = 0; i < editor.getPools().size(); i++)
        {
            judgeToEdit->addPool(editor.getPools().at(i));
        }
        emit competitionChanged();
    }
}

void JudgesPanelWidget::saveChanges()
{
    int row = 0;
    for (row =0; row < ui->artistic->rowCount(); row++)
    {
        QString judgeName = ui->artistic->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            m_competition->getJudgesPanel()->addArtisticJudge(*judgeListed);
        }
    }

    for (row =0; row < ui->execution->rowCount(); row++)
    {
        QString judgeName = ui->execution->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            m_competition->getJudgesPanel()->addExecutionJudge(*judgeListed);
        }
    }

    for (row =0; row < ui->difficulty->rowCount(); row++)
    {
        QString judgeName = ui->difficulty->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            m_competition->getJudgesPanel()->addDifficultyJudge(*judgeListed);
        }
    }

    for (row =0; row < ui->chair->rowCount(); row++)
    {
        QString judgeName = ui->chair->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            m_competition->getJudgesPanel()->addChairJudge(*judgeListed);
        }
    }

    for (row =0; row < ui->superior->rowCount(); row++)
    {
        QString judgeName = ui->superior->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            m_competition->getJudgesPanel()->addSuperiorJudge(*judgeListed);
        }
    }

    for (row =0; row < ui->line->rowCount(); row++)
    {
        QString judgeName = ui->line->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            m_competition->getJudgesPanel()->addLineJudge(*judgeListed);
        }
    }

    for (row =0; row < ui->assistant->rowCount(); row++)
    {
        QString judgeName = ui->assistant->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            m_competition->getJudgesPanel()->addAssistantJudge(*judgeListed);
        }
    }

    emit competitionChanged();

}

void JudgesPanelWidget::removeJudge()
{
    QTableWidget* from = ui->judgeTabs->currentWidget()->findChild<QTableWidget*>();
    if (from->selectedItems().size() > 0)
    {
        int row = from->selectedItems().at(0)->row();
        QString judgeName = from->item(row,0)->text();
        QList<QTableWidgetItem*> itemsInPool = ui->judgesTable->findItems(judgeName,Qt::MatchExactly);
        if (itemsInPool.size() > 0)
        {
            Judge* judgeListed = m_judgesItemDB[itemsInPool.at(0)];
            if (from == ui->artistic)
                m_competition->getJudgesPanel()->getArtisticJudges().removeAll(judgeListed);
            if (from == ui->execution)
                m_competition->getJudgesPanel()->getExecutionJudges().removeAll(judgeListed);
            if (from == ui->difficulty)
                m_competition->getJudgesPanel()->getDifficultyJudges().removeAll(judgeListed);
            if (from == ui->chair)
                m_competition->getJudgesPanel()->getChairJudges().removeAll(judgeListed);
            if (from == ui->superior)
                m_competition->getJudgesPanel()->getSuperiorJury().removeAll(judgeListed);
            if (from == ui->assistant)
                m_competition->getJudgesPanel()->getAssistantJudges().removeAll(judgeListed);
            if (from == ui->line)
                m_competition->getJudgesPanel()->getLineJudges().removeAll(judgeListed);
            from->removeRow(row);
        }
    }
    saveChanges();
}

void JudgesPanelWidget::changeEvent(QEvent *e)
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
