#include "ui/mainwindow.h"
#include "ui_mainwindow.h"
#include "modules/import/importmodule.h"
#include "ui/opendialog.h"
#include "modules/clublist/clublistwidget.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(const QString& openFileName,QSettings* settings, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_competition(new Competition()),
    m_fileName(openFileName),
    m_settings(settings)
{   
    ui->setupUi(this);

    ClubListWidget* clw = new ClubListWidget("clublist",m_competition);
    connect(this,SIGNAL(competitionChanged()),clw,SLOT(updateWidget()));

    ModuleFactory::getInstance().addModule(clw);

    connect(this,SIGNAL(competitionChanged()),this,SLOT(updateWindow()));
    emit competitionChanged();

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

void MainWindow::updateWindow()
{
    setWindowTitle(m_competition!=NULL?tr("OpenCompetition - ")+m_fileName.section('/',-1):("OpenCompetition"));
}

void MainWindow::on_Btn_import_clicked()
{
    importModule* importWindow = new importModule(m_competition);
    importWindow->show();
    emit competitionChanged();
}

void MainWindow::openCompetition()
{
    closeCompetition();

    OpenDialog openDiag(m_settings,this);
    m_fileName = openDiag.getSelectedFile();

    openCompetitionFromFile(m_fileName);

    emit competitionChanged();
}

void MainWindow::openCompetitionFromFile(const QString &filename)
{
    if (!m_competition->loadFromFile(filename))
    {
        QString errorMsg;
        int line = 0;
        int column = 0;
        QMessageBox info(this);
        info.setText(tr("Open Error."));
        info.setInformativeText(tr("Opening competition file failed."));
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setIcon(QMessageBox::Information);
        QString lineNum;
        QString colNum;
        info.setDetailedText(errorMsg + lineNum.setNum(line) + colNum.setNum(column));
        info.exec();
    } else {
        emit competitionChanged();
    }
}

void MainWindow::closeCompetition()
{
    QMessageBox msgBox;
    msgBox.setText(tr("The current competition will be closed."));
    msgBox.setInformativeText(tr("Save changes?"));
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
        m_competition->saveToFile(m_fileName);
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

void MainWindow::on_Btn_gemVer_clicked()
{
    AbstractModule* clw = ModuleFactory::getInstance().getModuleByName("clublist");
    if (clw != NULL) {
        emit competitionChanged();
        clw->show();
    }
}
