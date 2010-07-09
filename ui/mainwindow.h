#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data/competition.h"
#include "qsettings.h"
#include "modules/modulefactory.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(const QString& openFileName,QSettings* settings, QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    virtual void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    Competition* m_competition;
    QString m_fileName;
    QSettings* m_settings;

private slots:
    void on_Btn_Ergebnisliste_clicked();
    void on_Btn_Rangliste_clicked();
    void on_Btn_Urkunden_clicked();
    void on_Btn_Beamer_clicked();
    void on_Btn_Wertungen_clicked();
    void on_Btn_Startliste_clicked();
    void on_Btn_Kampfrichter_clicked();
    void on_Btn_startfeld_clicked();
    void on_Btn_gemVer_clicked();
    void on_Btn_import_clicked();
    void openCompetition();
    void openCompetitionFromFile(const QString& filename);
    void saveToFile();
    void saveToFileAs();
    bool closeCompetition();
    void updateWindow();
    bool showModule(const QString& name);
    void showAboutWindow();

signals:
    void competitionChanged();
};

#endif // MAINWINDOW_H
