#ifndef STARTDATAEDITOR_H
#define STARTDATAEDITOR_H

#include <QWidget>
#include "data/competition.h"
#include "types.h"

namespace Ui {
    class StartDataEditor;
}

class StartDataEditor : public QWidget {
    Q_OBJECT
public:
    StartDataEditor(Competition* comp, QWidget *parent = 0);
    ~StartDataEditor();

signals:
    void sortingChanged(trainingOrderType newOrder);
    void rebuildStartListRequested();
    void rebuildTrainingListRequested();

public slots:
    void updateValues();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::StartDataEditor *ui;
    Competition* m_competition;
    QTime m_trainingTime;
    QTime m_competitionTime;
    QTime m_starterOffset;
    QTime m_trainingOffset;

private slots:
    void updateTrainingOrderType();
};

#endif // STARTDATAEDITOR_H
