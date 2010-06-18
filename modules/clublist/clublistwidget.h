#ifndef CLUBLISTWIDGET_H
#define CLUBLISTWIDGET_H

#include <QWidget>

namespace Ui {
    class ClubListWidget;
}

class ClubListWidget : public QWidget {
    Q_OBJECT
public:
    ClubListWidget(QWidget *parent = 0);
    ~ClubListWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ClubListWidget *ui;
};

#endif // CLUBLISTWIDGET_H
