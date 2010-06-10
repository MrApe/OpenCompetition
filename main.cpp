#include <QtGui/QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QLocale>
#include "ui/mainwindow.h"
#include "ui/opendialog.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings("TUBS","OpenCompetition");

    QLocale::setDefault(QLocale::system());
    QTranslator qtTranslator;
    qtTranslator.load(QLocale::system().name(),"lang");
    a.installTranslator(&qtTranslator);

    OpenDialog od(&settings);
    QString openFileName = od.getSelectedFile();

    if (openFileName != "") {
        MainWindow w(openFileName, &settings);
        w.show();
        return a.exec();
    }

    return 0;
}
