#include "clublistwidget.h"
#include "ui_clublistwidget.h"

ClubListWidget::ClubListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClubListWidget)
{
    ui->setupUi(this);
}

ClubListWidget::~ClubListWidget()
{
    delete ui;
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
