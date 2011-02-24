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
    connect(this,SIGNAL(openFileChanged(QString)),this,SLOT(setOpenFileName(QString)));

    //Read settings
    QString base;
    for (unsigned int i = 0; i<=5; i++)
    {
        base = "recent/comp"+QString::number(i)+"/";
        QString filename = m_settings->value(base+"filename","NULL").toString();
        if (filename != "NULL")
        {
            if (QFile::exists(filename))  //File exists
            {
                smallCompT comp(filename,
                                m_settings->value(base+"name","").toString(),
                                m_settings->value(base+"date",QDate()).toDate(),
                                m_settings->value(base+"time",QTime()).toTime(),
                                m_settings->value(base+"rlt",false).toBool(),
                                m_settings->value(base+"description",QString()).toString());
                addToHistory(comp);
            } else {                     //File does not exist
                m_settings->remove(base);//remove from History
            }
        }
    }
    updateHistoryWidget();

}

QString OpenDialog::getSelectedFile()
{
    int ret = -1;
    while (m_fileToOpen == "" && ret != QDialog::Rejected){
        ret = exec();
    }
    return ret == QDialog::Rejected ? "" : m_fileToOpen;
}

void OpenDialog::setOpenFileName(const QString &filename){
    m_fileToOpen = filename;
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

int OpenDialog::addToHistory(smallCompT& comp)
{
    QList<smallCompT>::iterator it;
    QList<QList<smallCompT>::iterator> toDelete;
    // delete competions already listed equal to this
    for (it = m_recentComp.begin(); it != m_recentComp.end();it++)
    {

        if ((*it) == comp) toDelete.append(it);;
    }
    for (int i = 0; i<toDelete.size();i++)
    {
        m_recentComp.erase(toDelete.at(i));
    }
    //add to history
    m_recentComp.append(comp);

    //cut history List
    if (m_recentComp.size() > 5)
    {
        it = m_recentComp.begin();
        m_recentComp.erase(it);
    }
    updateHistoryWidget();
    saveHistory();

    return m_recentComp.size()-1;
}

int OpenDialog::addToHistory(Competition *comp,const QString& filename)
{
    smallCompT compSmall(filename,
                         comp->getName(),
                         comp->getDate(),
                         comp->getTime(),
                         comp->isRLT(),
                         comp->getDescription());
    return addToHistory(compSmall);
}

void OpenDialog::updateHistoryWidget()
{
    ui->historyWidget->clear();
    for (int i = 0; i<m_recentComp.size(); i++)
    {
        ui->historyWidget->insertTopLevelItem(0,new QTreeWidgetItem(ui->historyWidget,QStringList(m_recentComp.at(i).name)));
    }
}

void OpenDialog::saveHistory()
{
    QString base = "recent";
    m_settings->remove(base);
    for (int i = 0; i < m_recentComp.size(); i++)
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

    //Check if shown competition is selected in the history widget
    int index = 0;
    bool contains = false;
    while (!contains && index<m_recentComp.size())
    {
        contains = m_recentComp.at(index).filename == competition.filename;
        index++;
    }
    //otherwise select it
    if (contains && !ui->historyWidget->topLevelItem(index-1)->isSelected())
    {
        ui->historyWidget->topLevelItem(index-1)->setSelected(true);
    }

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
    QList<QTreeWidgetItem*> selectedItems = ui->historyWidget->selectedItems();
    if (selectedItems.size() > 0) {
        int selectedIndex = ui->historyWidget->indexOfTopLevelItem(selectedItems.at(0));
        emit competitionChanged(m_recentComp.at(selectedIndex));
    } else {

    }
}

void OpenDialog::clearWidget()
{
    ui->name->setText("");
    ui->date->setText("");
    ui->time->setText("");
    ui->isRLTBox->setChecked(false);
    ui->description->setText("");
    emit openFileChanged("");
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
    QString filename =
            QFileDialog::getSaveFileName(this,
                                         tr("Specify the name of the competition."),
                                         "",
                                         tr("Competition *.cmp"));
    if (filename != "")
    {
        NewCompDialog newCompDiag(tr("Properties - ")+filename.section('/',-1),this);
        Competition* compToOpen = newCompDiag.getNewCompetition();
        if (compToOpen != NULL) {
            addToHistory(compToOpen, filename);
            emit competitionChanged(compToOpen, filename);
            compToOpen->saveToFile(filename);
            emit openFileChanged(filename);
        }
    }
}

void OpenDialog::on_openBtn_clicked()
{
    QString filename = getFilenameFromDialog(tr("Open Competition."),QFileDialog::ExistingFile);
    if (filename!="")
    {
        Competition cmp;
        QString errorMsg;
        int line,column;
        if (cmp.loadFromFile(filename,&errorMsg,&line, &column))
        {
            addToHistory(&cmp,filename);
            emit competitionChanged(&cmp,filename);
            emit openFileChanged(filename);
        } else {
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
        }
    }
}

void OpenDialog::on_remove_clicked()
{
    if (ui->historyWidget->selectedItems().size() > 0)
    {
        QTreeWidgetItem* selected = ui->historyWidget->selectedItems().at(0);
        int index = ui->historyWidget->indexOfTopLevelItem(selected);
        if (index != -1)
        {
            m_recentComp.removeAt(index);
            updateHistoryWidget();
            saveHistory();
            if (ui->historyWidget->itemAt(0,0) != NULL)
            {
                ui->historyWidget->itemAt(0,0)->setSelected(true);
            }
        }
    }
}
