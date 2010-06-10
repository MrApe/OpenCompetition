#include <QtGui/QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QLocale>
#include "ui/mainwindow.h"
#include "ui/opendialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings("TUBS","OpenCompetition");

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    QTranslator appTranslator;
    appTranslator.load("myapp_" + QLocale::system().name());
    a.installTranslator(&appTranslator);

    OpenDialog od(&settings);
    QString openFileName = od.getSelectedFile();

    if (openFileName != "") {
        MainWindow w(openFileName, &settings);
        w.show();
        return a.exec();
    }

    return 0;
}
