#include <QTreeWidgetItem>
#include <QMessageBox>
#include "ui/opendialog.h"
#include "ui_opendialog.h"
#include "ui/newcompdialog.h"

OpenDialog::OpenDialog(QSettings* settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDialog),
    m_fileToOpen(),
    m_settings(settings),
    m_recentComp()
{
    ui->setupUi(this);

    connect(this,SIGNAL(competitionChanged(Competition*,QString)),this,SLOT(setShownCompetition(Competition*,QString)));
    connect(this,SIGNAL(competitionChanged(smallCompT)),this,SLOT(setShownCompetition(smallCompT)));
    connect(this,SIGNAL(openFileChanged(QString)),ui->openLineEdit,SLOT(setText(QString)));

    //Read settings
    QString base;
    for (unsigned int i = 0; i<=5; i++)
    {
        base = "recent/comp"+QString::number(i)+"/";
        QString filename = m_settings->value(base+"filename","NULL").toString();
        if (filename != "NULL"){
            smallCompT comp(filename,
                            m_settings->value(base+"name","").toString(),
                            m_settings->value(base+"date",QDate()).toDate(),
                            m_settings->value(base+"time",QTime()).toTime(),
                            m_settings->value(base+"rlt",false).toBool(),
                            m_settings->value(base+"description",QString()).toString());
            m_recentComp.push_back(comp);
        }
    }
    updateHistoryWidget();

}

QString OpenDialog::getSelectedFile()
{
    int ret;
    while (m_fileToOpen == "" && ret != QDialog::Rejected){
        ret = exec();
    }
    return ret == QDialog::Rejected ? "" : m_fileToOpen;
}


OpenDialog::~OpenDialog()
{
    delete ui;
}

void OpenDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void OpenDialog::addToHistory(smallCompT& comp)
{
    std::vector<smallCompT>::iterator it;
    // delete competions already listed equal to this
    for (it = m_recentComp.begin(); it != m_recentComp.end();it++)
    {
        if ((*it) == comp) m_recentComp.erase(it);
    }
    //add to history
    m_recentComp.push_back(comp);

    //cut history List
    if (m_recentComp.size() > 5)
    {
        it = m_recentComp.begin();
        m_recentComp.erase(it);
    }
    updateHistoryWidget();
    saveHistory();
}

void OpenDialog::addToHistory(Competition *comp,const QString& filename)
{
    smallCompT compSmall(filename,
                         comp->getName(),
                         comp->getDate(),
                         comp->getTime(),
                         comp->isRLT(),
                         comp->getDescription());
    addToHistory(compSmall);
}

void OpenDialog::updateHistoryWidget()
{
    ui->historyWidget->clear();
    for (unsigned int i = 0; i<m_recentComp.size(); i++)
    {
        ui->historyWidget->insertTopLevelItem(0,new QTreeWidgetItem(ui->historyWidget,QStringList(m_recentComp.at(i).name)));
    }
}

void OpenDialog::saveHistory()
{
    QString base;
    for (unsigned int i = 0; i < m_recentComp.size(); i++)
    {
        base = "recent/comp"+QString::number(i)+"/";
        m_settings->setValue(base+"filename",m_recentComp.at(i).filename);
        m_settings->setValue(base+"name",m_recentComp.at(i).name);
        m_settings->setValue(base+"date",m_recentComp.at(i).date);
        m_settings->setValue(base+"time",m_recentComp.at(i).time);
        m_settings->setValue(base+"rlt",m_recentComp.at(i).isRLT);
        m_settings->setValue(base+"description",m_recentComp.at(i).description);
    }
}

void OpenDialog::setShownCompetition(smallCompT competition)
{
    ui->name->setText(competition.name);
    ui->date->setText(competition.date.toString(Qt::SystemLocaleLongDate));
    ui->time->setText(competition.time.toString(Qt::SystemLocaleLongDate));
    ui->isRLTBox->setChecked(competition.isRLT);
    ui->description->setText(competition.description);
    ui->historyWidget->isItemSelected()
    emit openFileChanged(competition.filename);
}

void OpenDialog::setShownCompetition(Competition* competition,const QString& filename)
{
    smallCompT compSmall(filename,
                         competition->getName(),
                         competition->getDate(),
                         competition->getTime(),
                         competition->isRLT(),
                         competition->getDescription());
    setShownCompetition(compSmall);
}

void OpenDialog::on_historyWidget_itemSelectionChanged()
{
    // Get selected Item
    int selectedIndex = ui->historyWidget->indexOfTopLevelItem(ui->historyWidget->selectedItems().at(0));
    emit competitionChanged(m_recentComp.at(selectedIndex));
}

QString OpenDialog::getFilenameFromDialog(const QString& title, QFileDialog::FileMode fileMode)
{
    QString filename = "";
    QFileDialog filenameDiag(this,
                                 title,
                                 "",
                                 tr("Competition *.cmp"));
    filenameDiag.setFileMode(fileMode);
    filenameDiag.setDefaultSuffix("cmp");
    QStringList filenames;
    if (filenameDiag.exec())
    {
        filenames = filenameDiag.selectedFiles();
        filename = filenames.size() > 0?filenames.at(0):"";
    }
    return filename;
}

void OpenDialog::on_createNewBtn_clicked()
{
    QString filename = getFilenameFromDialog(tr("Specify the name of the competition."), QFileDialog::AnyFile);
    if (filename != "")
    {
        NewCompDialog newCompDiag("Properties - "+filename.section('/',-1),this);
        Competition* compToOpen = newCompDiag.getNewCompetition();
        if (compToOpen != NULL) {
            emit competitionChanged(compToOpen, filename);
            addToHistory(compToOpen, filename);
        }
        compToOpen->saveToFile(filename);
        emit openFileChanged(filename);
    }
}

void OpenDialog::on_openBtn_clicked()
{
    QString filename = getFilenameFromDialog(tr("Open Competition."),QFileDialog::ExistingFile);
    if (filename!="")
    {
        Competition cmp;
        if (cmp.loadFromFile(filename))
        {
            addToHistory(*cmp);
            setShownCompetition(&cmp,filename);

            emit openFileChanged(filename);
        } else {
            QMessageBox::information(this,
                                     tr("Open Error."),
                                     tr("Opening competition file failed. "),
                                     QMessageBox::Ok,
                                     QMessageBox::Ok);
        }
    }
}
