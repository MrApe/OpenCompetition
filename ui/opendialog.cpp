#include <QTreeWidgetItem>
#include <QFileDialog>
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

    connect(this,SIGNAL(competitionChanged(Competition*)),this,SLOT(setShownCompetition(Competition*)));

    //Read settings
    for (unsigned int i = 0; i<=5; i++)
    {
        QString base = "recent/comp"+QString::number(i)+"/";
        smallCompT comp;
        comp.filename = m_settings->value(base+"filename","NULL").toString();
        if (comp.filename != "NULL"){
            comp.name = m_settings->value(base+"name","").toString();
            comp.date = m_settings->value(base+"date",QDate()).toDate();
            comp.time = m_settings->value(base+"time",QTime()).toTime();
            comp.isRLT = m_settings->value(base+"rlt",false).toBool();
            comp.description = m_settings->value(base+"description",QString()).toString();
            m_recentComp.push_back(comp);
        }
    }

    for (unsigned int i = 0; i<m_recentComp.size(); i++)
    {
        ui->historyWidget->insertTopLevelItem(0,new QTreeWidgetItem(ui->historyWidget,QStringList(m_recentComp.at(i).name)));
    }
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

void OpenDialog::setShownCompetition(Competition* competition)
{
    ui->name->setText(competition->getName());
    ui->date->setText(competition->getDate().toString(Qt::SystemLocaleLongDate));
    ui->time->setText(competition->getTime().toString(Qt::SystemLocaleLongDate));
    ui->isRLTBox->setChecked(competition->isRLT());
    ui->description->setText(competition->getDescription());
}

void OpenDialog::on_historyWidget_itemSelectionChanged()
{

}

void OpenDialog::on_createNewBtn_clicked()
{
    QFileDialog filenameDiag(this,
                             tr("Namen des neuen Wettkampfes angeben"),
                             "",
                             tr("Wettkampf *.cmp"));
    filenameDiag.setFileMode(QFileDialog::AnyFile);
    filenameDiag.setDefaultSuffix("cmp");
    QStringList filenames;
    if (filenameDiag.exec())
    {
        filenames = filenameDiag.selectedFiles();
        if (filenames.size() > 0)
        {
            QString filename = filenames.at(0);
            NewCompDialog newCompDiag("Eigenschaften - "+filename.section('/',-1),this);
            Competition* compToOpen = newCompDiag.getNewCompetition();
            if (compToOpen != NULL) {
                emit competitionChanged(compToOpen);
            }
            compToOpen->saveToFile(filename);
            m_fileToOpen = filename;
        }

    }

}
