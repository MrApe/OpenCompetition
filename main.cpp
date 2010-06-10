#include <QtGui/QApplication>
#include "ui/mainwindow.h"
#include "ui/opendialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings("TUBS","OpenCompetition");

    OpenDialog od(&settings);
    QString openFileName = od.getSelectedFile();

    if (openFileName != "") {
        MainWindow w(openFileName, &settings);
        w.show();
        return a.exec();
    }

    return 0;
}
