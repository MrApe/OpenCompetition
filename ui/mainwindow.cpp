#include "ui/mainwindow.h"
#include "ui_mainwindow.h"
#include "modules/import/importmodule.h"
#include "ui/opendialog.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(const QString& openFileName,QSettings* settings, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_competition(NULL),
    m_fileName(openFileName),
    m_settings(settings)
{   
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_competition;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_Btn_import_clicked()
{
    importModule* importWindow = new importModule();
    importWindow->show();
}

void MainWindow::openCompetition()
{
    closeCompetition();

    while (m_competition==NULL || m_fileName == ""){
        OpenDialog openDiag(m_settings,this);
        m_fileName = openDiag.exec();
    }

    openCompetitionFromFile(m_fileName);
}

void MainWindow::openCompetitionFromFile(const QString &filename)
{
    QMessageBox::information(this,"Opening File",filename);
}

void MainWindow::closeCompetition()
{
    QMessageBox msgBox;
    msgBox.setText("Der aktuelle Wettkampf wird geschlossen.");
    msgBox.setInformativeText("Sollen die Änderungen gespeichert werden?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save :
            saveToFile();
            delete m_competition;
            m_competition = NULL;
            m_fileName = "";
            return;
    case QMessageBox::Discard :
            delete m_competition;
            m_competition = NULL;
            m_fileName = "";
            return;
    case QMessageBox::Cancel :
            return;
    default:
            return;
    }
}

void MainWindow::saveToFile()
{
    if (m_fileName != "") {
        QFile file(m_fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "Datei konnte nicht geöffnet werden.", file.errorString());
                        return;
        }
        QDataStream out(&file);
        out << m_competition;
        file.close();
    } else {
        saveToFileAs();
    }
}

void MainWindow::saveToFileAs()
{
    QFileDialog saveFileDiag(this,
                             tr("Wettkampf speichern"),
                             "",
                             tr("Wettkampf (*.cmp);; AllFiles (*)"));
    saveFileDiag.setFileMode(QFileDialog::AnyFile);
    QStringList newFileNames;
    if (saveFileDiag.exec())
        newFileNames = saveFileDiag.selectedFiles();
    if (newFileNames.size() > 0) {
        m_fileName==newFileNames.at(0);
        saveToFile();
    }
}
