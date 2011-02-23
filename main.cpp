#include <QtGui/QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QLocale>
#include "ui/mainwindow.h"
#include "ui/opendialog.h"
#include <iostream>

#ifdef Q_WS_MAC
#include <CoreFoundation/CFURL.h>
#include <CoreFoundation/CFBundle.h>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings("TUBS","OpenCompetition");

    #ifdef Q_WS_MAC
        //determine path
        CFURLRef appUrlRef = CFBundleCopyBundleURL(CFBundleGetMainBundle());
        CFStringRef macPath = CFURLCopyFileSystemPath(appUrlRef, kCFURLPOSIXPathStyle);
        QString bundlepath = (CFStringGetCStringPtr(macPath, CFStringGetSystemEncoding()));
        CFRelease(appUrlRef);
        CFRelease(macPath);

        //set resource path
        QString path = bundlepath + "/Contents/Resources/";
    #else
            QString path = "";
    #endif


    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(path+ QString("OpenCompetition_") + locale);
    a.installTranslator(&translator);

    OpenDialog od(&settings);
    QString openFileName = od.getSelectedFile();

    if (openFileName != "") {
        MainWindow w(openFileName, &settings);
        w.show();
        return a.exec();
    }

    return 0;
}
