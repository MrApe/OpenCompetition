#ifndef JUDGEEDITORWIDGET_H
#define JUDGEEDITORWIDGET_H

#include <QDialog>
#include "data/judge.h"

namespace Ui {
    class JudgeEditorWidget;
}

class JudgeEditorWidget : public QDialog {
    Q_OBJECT
public:
    JudgeEditorWidget(Judge* toEdit, QWidget *parent = 0);
    ~JudgeEditorWidget();

    inline const QString& getName(){return m_name;}
    inline Judge::brevetType getBrevet(){return m_brevet;}
    inline QList<Judge::scoreType> getPools(){return m_pools;}

private:
    Ui::JudgeEditorWidget *ui;
    QString m_name;
    Judge::brevetType m_brevet;
    QList<Judge::scoreType> m_pools;

private slots:
    void changeName(const QString& name);
    void changeBrevet(const QString& brevetAsString);
    void updatePools();

};

#endif // JUDGEEDITORWIDGET_H
