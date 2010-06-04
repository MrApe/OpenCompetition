#include "newcompdialog.h"
#include "ui_newcompdialog.h"

NewCompDialog::NewCompDialog(const QString& title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCompDialog),
    m_newCompetition(new Competition())
{
    ui->setupUi(this);

    setWindowTitle(title);

    connect(ui->nameEdit,SIGNAL(textChanged(QString)),m_newCompetition,SLOT(setName(QString)));
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),m_newCompetition,SLOT(setDate(QDate)));
    connect(ui->timeEdit,SIGNAL(timeChanged(QTime)),m_newCompetition,SLOT(setTime(QTime)));
    connect(ui->RLTCheck,SIGNAL(toggled(bool)),m_newCompetition,SLOT(setAsRLT(bool)));
    connect(ui->descriptionEdit,SIGNAL(textChanged()),this,SLOT(retrieveDescription()));
}

NewCompDialog::~NewCompDialog()
{
    delete ui;
}

void NewCompDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

Competition* NewCompDialog::getNewCompetition()
{
    int ret;
    ret = exec();
    if (ret == QDialog::Accepted)
    {
       m_newCompetition->setName(ui->nameEdit->text());
       m_newCompetition->setDate(ui->dateEdit->date());
       m_newCompetition->setTime(ui->timeEdit->time());
       m_newCompetition->setAsRLT(ui->RLTCheck->isChecked());
       m_newCompetition->setDescription(ui->descriptionEdit->toPlainText());
       return m_newCompetition;
    }

    return NULL;
}

void NewCompDialog::retrieveDescription()
{
    m_newCompetition->setDescription(ui->descriptionEdit->toPlainText());
}
