#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QString>
#include <QDate>
#include <QTime>
#include "data/competition.h"

namespace Ui {
    class OpenDialog;
}

class OpenDialog : public QDialog {
    Q_OBJECT

    struct smallCompT{
        QString filename;
        QString name;
        QDate date;
        QTime time;
    };

public:
    OpenDialog(QSettings* settings,QWidget *parent = 0);
    ~OpenDialog();

    /*!
      Open this dialog and return the filename of the file to open.
      @return Filename of file to open.
      */
    QString getSelectedFile();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::OpenDialog *ui;
    QString m_fileToOpen;
    QSettings* m_settings;
    std::vector<smallCompT> m_recentComp;

private slots:
    void on_createNewBtn_clicked();
    void on_historyWidget_itemSelectionChanged();
    void setShownCompetition(Competition* competition);

signals:
    void competitionChanged(Competition* competition);

};

#endif // OPENDIALOG_H
