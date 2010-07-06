#include "judgeeditorwidget.h"
#include "ui_judgeeditorwidget.h"

JudgeEditorWidget::JudgeEditorWidget(Judge* toEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JudgeEditorWidget),
    m_name(toEdit->getName()),
    m_brevet(toEdit->getBrevet()),
    m_pools(toEdit->getPools())
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(reject()));

    ui->name->setText(toEdit->getName());
    ui->brevet->setCurrentIndex(ui->brevet->findText(Judge::brevetTypeToString(toEdit->getBrevet())));
    for (int i = 0; i < toEdit->getPools().size(); i++)
    {
        switch (toEdit->getPools().at(i)){
        case Judge::ARTISTIC:
            ui->artistic->setChecked(true);
            break;
        case Judge::EXECUTION:
            ui->execution->setChecked(true);
            break;
        case Judge::DIFFICULTY:
            ui->difficulty->setChecked(true);
            break;
        case Judge::CHAIR:
            ui->chair->setChecked(true);
            break;
        default: //nothing;
            break;
        }
    }

}

JudgeEditorWidget::~JudgeEditorWidget()
{
    delete ui;
}

void JudgeEditorWidget::changeName(const QString &name)
{
    m_name = name;
}

void JudgeEditorWidget::changeBrevet(const QString &brevetAsString)
{
    m_brevet = Judge::stringToBrevetType(brevetAsString);
}

void JudgeEditorWidget::updatePools()
{
    m_pools.clear();
    if (ui->artistic->isChecked()) m_pools.append(Judge::ARTISTIC);
    if (ui->execution->isChecked()) m_pools.append(Judge::EXECUTION);
    if (ui->difficulty->isChecked()) m_pools.append(Judge::DIFFICULTY);
    if (ui->chair->isChecked()) m_pools.append(Judge::CHAIR);
}
