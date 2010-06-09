#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QString>
#include <QDate>
#include <QTime>
#include <QFileDialog>
#include "data/competition.h"

namespace Ui {
    class OpenDialog;
}

class OpenDialog : public QDialog {
    Q_OBJECT

    struct smallCompT{
        smallCompT(const QString& filename,
                   const QString& name,
                   const QDate& date,
                   const QTime& time,
                   const bool isRLT,
                   const QString& description
                   ):
            filename(filename),
            name(name),
            date(date),
            time(time),
            isRLT(isRLT),
            description(description){}

        QString filename;
        QString name;
        QDate date;
        QTime time;
        bool isRLT;
        QString description;
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

    void addToHistory(smallCompT& comp);
    void addToHistory(Competition* comp, const QString& filename);
    void updateHistoryWidget();
    void saveHistory();
    QString getFilenameFromDialog(const QString& title, QFileDialog::FileMode fileMode);

private slots:
    void on_openBtn_clicked();
    void on_createNewBtn_clicked();
    void on_historyWidget_itemSelectionChanged();
    void setShownCompetition(Competition* competition, const QString& filename);
    void setShownCompetition(smallCompT competition);

signals:
    void competitionChanged(Competition* competition, const QString& filename);
    void competitionChanged(smallCompT competition);
    void openFileChanged(const QString& filename);

};

#endif // OPENDIALOG_H
