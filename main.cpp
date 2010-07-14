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

    //QLocale::setDefault(QLocale::system());
    QLocale german(QLocale::German,QLocale::Germany);
    QLocale::setDefault(german);
    QTranslator qtTranslator;
    qtTranslator.load("lang/"+german.name());
    std::cout << german.name().toStdString().c_str() << std::endl;
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
