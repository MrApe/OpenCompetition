#include "importmodule.h"
#include "ui_importmodule.h"
#include <QFileDialog>
#include "text/textimporter.h"

importModule::importModule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::importModule),
    m_pluginProvider()
{
    ui->setupUi(this);
    TextImporter* textimporter = new TextImporter("txt");
    m_pluginProvider.addPlugin(textimporter);
}

importModule::~importModule()
{
    delete ui;
}

void importModule::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void importModule::importFiles(){
    std::vector<Group> foundGroups;
    for (int i = 0; i < ui->meldungenListe->count();i++ )
    {
        QString current = ui->meldungenListe->itemAt(i,0)->text();
        foundGroups = m_pluginProvider.getPluginFor(current.section('.',1,2))->importFile(current);
    }
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);
}

void importModule::selectFiles(){
    QStringList fileNames;
    QFileDialog dialog(this);
    dialog.setWindowTitle(tr("Select Registration"));
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter("Registration *.doc *.pdf *.txt");
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    ui->meldungenListe->clearSelection();
    for (QList<QString>::iterator i = fileNames.begin();i != fileNames.end();i++) {
        QString act = *i;
        QList<QListWidgetItem*> duplicates = ui->meldungenListe->findItems(act,Qt::MatchExactly);
        for (QList<QListWidgetItem*>::iterator dup = duplicates.begin(); dup != duplicates.end(); dup++) {
            //QListWidgetItem* toRemove = (*dup);
            (*dup)->setSelected(true);
            //ui->meldungenListe->removeItemWidget(toRemove);
        }  
    }
    on_remove_clicked();

    ui->meldungenListe->addItems(fileNames);
}

void importModule::on_remove_clicked()
{
    for (int i = 0; i < ui->meldungenListe->count() ;i++) {
        if (ui->meldungenListe->item(i)->isSelected()) {
           delete ui->meldungenListe->takeItem(i);
        }
    }
}
