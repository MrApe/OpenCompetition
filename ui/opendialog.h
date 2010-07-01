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
        bool operator ==(const smallCompT& other){
            return (filename == other.filename);
        }

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
    QList<smallCompT> m_recentComp;


    /*!
      This function updates the history widget with the backend data.
      */
    void updateHistoryWidget();
    /*!
      This method saves the history to the application settings.
      */
    void saveHistory();
    /*!
      This helper function opens a file dialog for *.cmp files with the given title ans filenmode and returns a single selected filename.
      However QFileDialog::ExistingFiles allows selecting more than one file this method will only return the first selected and ignore all others. Create a custom file dialog to prevent this behavior.
      @param title The title to be shown in the dialog.
      @param fileMode Specifies the file mode for the open file dialog.
      @return Selected filename
      */
    QString getFilenameFromDialog(const QString& title, QFileDialog::FileMode fileMode);


public slots:
    void on_historyWidget_itemSelectionChanged();
    /*!
      This method sets the competition shown in the description section and highlights the corresponding entry in the history widget.
      @param competition The competition to be shown.
      */
    void setShownCompetition(smallCompT competition);
    /*!
      This is an overloaded function. It creates a smallCompT object and calls setShwonCompetition.
      @param competition The competition to add.
      @param filename Its filename.
      */
    void setShownCompetition(Competition* competition, const QString& filename);
    /*!
      This function adds the competition to the local history.
      It returns its index in the history.
      @param comp The competition to add to the history.
      @return The index of the added competition in the history vector.
      */
    int addToHistory(smallCompT& comp);
    /*!
      This is an overloaded function. It creates a smallCompT object and calls addToHistory(smallCompT& comp).
      @param comp The competition to add.
      @param filename Its filename.
      @return The index of the newly added competition.
      */
    int addToHistory(Competition* comp, const QString& filename);
    /*!
      This function sets filename of the file to open.
      @param filename Filename of the file to open.
      */
    void setOpenFileName(const QString& filename);

private slots:
    void on_remove_clicked();
    void on_openBtn_clicked();
    void on_createNewBtn_clicked();
    void clearWidget();

signals:
    void competitionChanged(Competition* competition, const QString& filename);
    void competitionChanged(smallCompT competition);
    void openFileChanged(const QString& filename);

};

#endif // OPENDIALOG_H
