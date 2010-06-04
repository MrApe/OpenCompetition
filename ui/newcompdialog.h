#ifndef NEWCOMPDIALOG_H
#define NEWCOMPDIALOG_H

#include <QDialog>
#include "data/competition.h"

namespace Ui {
    class NewCompDialog;
}

class NewCompDialog : public QDialog {
    Q_OBJECT
public:
    NewCompDialog(const QString& title = "Neuer Wettkampf",QWidget *parent = 0);
    ~NewCompDialog();

    /*!
        Show this dialog and return the competition the user typed in.
        @return Created competition.
      */
    Competition* getNewCompetition();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::NewCompDialog *ui;
    Competition* m_newCompetition;

private slots:
    void retrieveDescription();

};

#endif // NEWCOMPDIALOG_H
