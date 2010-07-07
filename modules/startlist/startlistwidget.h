#ifndef STARTLISTWIDGET_H
#define STARTLISTWIDGET_H

#include "modules/abstractmodule.h"
#include "data/competition.h"
#include <QMainWindow>

namespace Ui {
    class StartListWidget;
}

class StartListWidget : public AbstractModule{
    Q_OBJECT
public:
    StartListWidget(const QString& name,Competition* comp, QWidget *parent = 0);
    ~StartListWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::StartListWidget *ui;
    Competition* m_competition;
};

#endif // STARTLISTWIDGET_H
