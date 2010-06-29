#ifndef PROPERTIESWIDGET_H
#define PROPERTIESWIDGET_H

#include <QWidget>
#include "data/competition.h"

namespace Ui {
    class PropertiesWidget;
}

class PropertiesWidget : public QWidget {
    Q_OBJECT
public:
    PropertiesWidget(Competition* competition, QWidget *parent = 0);
    ~PropertiesWidget();

public slots:
    void updateProperties();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PropertiesWidget *ui;
    Competition* m_competition;

    void addProperty(QString key, QString value);
    void setProperty(QString key, QString value);
    void setProperty(QString key, int value);
    void setProperty(QString key, QDate value);
    void setProperty(QString key, QTime value);
    void setProperty(QString key, Group::categorieType value);
    void setProperty(QString key, Group::ageType value);
    void setProperty(QString key, bool value);
};

#endif // PROPERTIESWIDGET_H
