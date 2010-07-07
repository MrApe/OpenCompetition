#include "startlistwidget.h"
#include "ui_startlistwidget.h"
#include "modules/startlist/startdataeditor.h"
#include <QDockWidget>

StartListWidget::StartListWidget(const QString &name, Competition *comp, QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::StartListWidget),
    m_competition(comp)
{
    ui->setupUi(this);

    QDockWidget* edDock = new QDockWidget(tr("Startdata Editor"),this);
    StartDataEditor* editor = new StartDataEditor(comp);
    edDock->setWidget(editor);
    addDockWidget(Qt::RightDockWidgetArea,edDock);
}

StartListWidget::~StartListWidget()
{
    delete ui;
}

void StartListWidget::changeEvent(QEvent *e)
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
