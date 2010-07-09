#include "resultswidget.h"
#include "ui_resultswidget.h"
#include "data/group.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

ResultsWidget::ResultsWidget(const QString &name, Competition *comp, QWidget *parent) :
    AbstractModule(name,parent),
    ui(new Ui::ResultsWidget),
    m_competition(comp)
{
    ui->setupUi(this);

    ui->startlist->setColumnWidth(0,150);
    ui->startlist->setColumnWidth(1,150);
}

ResultsWidget::~ResultsWidget()
{
    delete ui;
}

void ResultsWidget::updateWidget()
{
    if(m_competition!= NULL) {
        showStartList();
    }

}

void ResultsWidget::showStartList()
{
    QTableWidgetItem* item;
        int rows = m_competition->getStartList().size();
        ui->startlist->setRowCount(rows);
        ui->startlist->clearContents();
        for (int row = 0; row < rows; row++)
        {
            Group* current = m_competition->getStartList().at(row);

            item = new QTableWidgetItem(current->getClub().toString());
            ui->startlist->setItem(row,0,item);

            QString comp;
            for (int i = 0; i < current->getCompetitors().size();i++)
            {
               comp.append(current->getCompetitors().at(i).getName());
               comp.append("(");
               comp.append(QString::number(current->getCompetitors().at(i).getBirth()));
               comp.append(")");
               if (i < current->getCompetitors().size()-1){
                   comp.append(", ");
               }
            }
            item = new QTableWidgetItem(comp);
            ui->startlist->setItem(row,1,item);


            QString a,b,s,line,chair;
            for (int i = 0; i < current->getScores().size(); i++)
            {
                switch (current->getScores().at(i).getType())
                {
                case Judge::ARTISTIC:
                    a.append("("+QString::number(current->getScores().at(i).getValue(),'f',1)+")");
                    break;
                case Judge::EXECUTION:
                    b.append("("+QString::number(current->getScores().at(i).getValue(),'f',1)+")");
                    break;
                case Judge::DIFFICULTY:
                    s.append("("+QString::number(current->getScores().at(i).getValue(),'f',1)+")");
                    break;
                case Judge::CHAIR:
                    chair = QString::number(current->getScores().at(i).getValue(),'f',1);
                    break;
                case Judge::LINE:
                    line += QString::number(current->getScores().at(i).getValue(),'f',1);
                    break;
                default: //nothing;
                    break;
                }
            }

            item = new QTableWidgetItem(a);
            ui->startlist->setItem(row,2,item);

            item = new QTableWidgetItem(b);
            ui->startlist->setItem(row,3,item);

            item = new QTableWidgetItem(s);
            ui->startlist->setItem(row,4,item);

            item = new QTableWidgetItem(chair);
            ui->startlist->setItem(row,5,item);

            item = new QTableWidgetItem(line);
            ui->startlist->setItem(row,6,item);

            item = new QTableWidgetItem(QString::number(current->getFinalScore(),'f',3));
            ui->startlist->setItem(row,7,item);
        }
}

void ResultsWidget::changeEvent(QEvent *e)
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

void ResultsWidget::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("CSV (*.csv *.txt)"));

    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if (fileNames.size() > 0)
    {
        QFile outputFile(fileNames.at(0));
        if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
                 return;
        } else {
            QString trenner = "; ";
            QTextStream out(&outputFile);
            out << tr("Club") << trenner << tr("Starter") << trenner << tr("Artistic");
            out << trenner << tr("Execution") << trenner << tr("Difficulty");
            out << trenner << tr("Chair") << trenner << tr("Line");
            out << trenner << tr("Final") << "\n";
            for (int i = 0; i< ui->startlist->rowCount(); i++)
            {     
                for (int j = 0; j < ui->startlist->columnCount() -1; j++)
                {
                   out << ui->startlist->item(i,j)->text() << trenner;
                }
                out << ui->startlist->item(i,ui->startlist->columnCount() -1)->text() << "\n";
            }
        }
        outputFile.close();
    }
}
