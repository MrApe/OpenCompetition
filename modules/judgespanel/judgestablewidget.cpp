#include "judgestablewidget.h"
#include <QMessageBox>
#include <QStandardItemModel>

judgesTableWidget::judgesTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
   setToolTip("This is a judgesTabelWidget");
   setAcceptDrops(true);
   setDragEnabled(true);
   setDropIndicatorShown(true);
   setDefaultDropAction(Qt::IgnoreAction);
   setDragDropOverwriteMode(false);
}

void judgesTableWidget::dragMoveEvent(QDragMoveEvent *event) {
    if (event->source() == this) {
        event->ignore();
    }
}

void judgesTableWidget::dropEvent(QDropEvent *event) {
    if (event->source()->inherits("judgesTableWidget")) {
        QStandardItemModel container;
        container.dropMimeData(event->mimeData(),Qt::CopyAction,0,0,QModelIndex());
        if (!isListed(container.item(0,0)->text())) {
            insertRow(rowCount());
            for (int col = 0; col < container.columnCount() && col < columnCount(); col++) {
                QTableWidgetItem *item = new QTableWidgetItem(container.item(0,col)->text());
                setItem(rowCount()-1,col,item);
            }
            judgesTableWidget* source = (judgesTableWidget*)(event->source());
            source->remove(container.item(0,0)->text());
            event->accept();
        }
        emit tableChanged();
    }
}

bool judgesTableWidget::isListed(QString name) {
    for (int row = 0; row < rowCount(); row++) {
        if (name == item(row,0)->text()) return true;
    }
    return false;
}

bool judgesTableWidget::isListed(QTableWidgetItem name) {
    return isListed(name.text());
}

const Judge judgesTableWidget::remove(QString name){
    //check if contains the judge
    if (isListed(name)) {
        //find it
        for (int row = 0; row < rowCount(); row++) {
            QString toCheck = item(row,0)->text();
            if (name == toCheck) {
                Judge retJudge(name,Judge::stringToBrevetType(item(row,2)->text()));
                removeRow(row);
                return retJudge;
            }
        }
    }
    return Judge();
}
