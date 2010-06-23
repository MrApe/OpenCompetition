#include "clublistwidget.h"
#include "ui_clublistwidget.h"

ClubListWidget::ClubListWidget(Competition* comp,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClubListWidget),
    m_competition(comp)
{
    ui->setupUi(this);
}

ClubListWidget::~ClubListWidget()
{
    delete ui;
}

void ClubListWidget::updateClubList()
{
    m_clublist.clear();
    for (unsigned int i = 0; i < m_competition->getStarter().size();i++)
    {

    }
}

void ClubListWidget::changeEvent(QEvent *e)
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
