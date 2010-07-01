#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDockWidget>
#include <QTextEdit>
#include <QCloseEvent>
#include "ui/mainwindow.h"
#include "ui_mainwindow.h"
#include "modules/import/importmodule.h"
#include "ui/opendialog.h"
#include "modules/clublist/clublistwidget.h"
#include "modules/competitorlist/competitorlistwidget.h"
#include "ui/propertieswidget.h"

MainWindow::MainWindow(const QString& openFileName,QSettings* settings, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_competition(new Competition()),
    m_fileName(openFileName),
    m_settings(settings)
{   
    ui->setupUi(this);

    ClubListWidget* clubLW = new ClubListWidget("clublist",m_competition);
    connect(this,SIGNAL(competitionChanged()),clubLW,SLOT(updateWidget()));
    ModuleFactory::getInstance().addModule(clubLW);

    CompetitorListWidget* compLW = new CompetitorListWidget("competitorlist",m_competition);
    connect(this,SIGNAL(competitionChanged()),compLW,SLOT(updateWidget()));
    ModuleFactory::getInstance().addModule(compLW);

    connect(this,SIGNAL(competitionChanged()),this,SLOT(updateWindow()));

    openCompetitionFromFile(m_fileName);

    QDockWidget* propDock = new QDockWidget(tr("Properties"),this);
    PropertiesWidget* prop = new PropertiesWidget(m_competition,propDock);
    propDock->setWidget(prop);
    addDockWidget(Qt::RightDockWidgetArea,propDock);

    connect(this,SIGNAL(competitionChanged()),prop,SLOT(updateProperties()));
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
    connect(importWindow,SIGNAL(importReady()),this,SIGNAL(competitionChanged()));
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (closeCompetition()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool MainWindow::closeCompetition()
{
    QMessageBox msgBox(this);
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
            return true;
    case QMessageBox::Discard :
            delete m_competition;
            m_competition = NULL;
            m_fileName = "";
            return true;
    case QMessageBox::Cancel :
            return false;
    default:
            return false;
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
                             tr("save competition"),
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

void MainWindow::showModule(const QString &name)
{
    AbstractModule* module = ModuleFactory::getInstance().getModuleByName(name);
    if (module != NULL) {
        emit competitionChanged();
        module->show();
    }
}

void MainWindow::on_Btn_gemVer_clicked()
{
    showModule("clublist");
}

void MainWindow::on_Btn_startfeld_clicked()
{
    showModule("competitorlist");
}
