#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QFile>
#include <QTextStream>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::changeEvent(QEvent *e)
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

void AboutDialog::on_pushButton_clicked()
{
    QFile inputFile(":/licences/images/ImageLicence.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString licence = in.readAll();
    inputFile.close();

    QTextEdit* licenceEdit = new QTextEdit(licence);
    licenceEdit->setMinimumSize(300,500);
    licenceEdit->setWindowModality(Qt::WindowModal);
    licenceEdit->show();
}
