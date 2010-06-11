#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data/competition.h"
#include "qsettings.h"

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

private:
    Ui::MainWindow *ui;
    Competition* m_competition;
    QString m_fileName;
    QSettings* m_settings;

private slots:
    void on_Btn_import_clicked();
    void openCompetition();
    void openCompetitionFromFile(const QString& filename);
    void saveToFile();
    void saveToFileAs();
    void closeCompetition();
    void updateWindow();

signals:
    void competitionChanged();
};

#endif // MAINWINDOW_H