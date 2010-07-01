# -------------------------------------------------
# Project created by QtCreator 2010-05-04T12:31:20
# -------------------------------------------------
QT += sql \
    xml
TARGET = OpenCompetition
TEMPLATE = app
TRANSLATIONS = lang/de_DE.ts
SOURCES += main.cpp \
    modules/import/importmodule.cpp \
    modules/import/abstractimporter.cpp \
    data/abstractperson.cpp \
    data/competitor.cpp \
    data/group.cpp \
    data/club.cpp \
    data/tomanycompetitorsexception.cpp \
    data/judge.cpp \
    data/judgespanel.cpp \
    data/competition.cpp \
    modules/import/text/textimporter.cpp \
    modules/import/filenotopenedexception.cpp \
    modules/import/importpluginprovider.cpp \
    ui/opendialog.cpp \
    ui/mainwindow.cpp \
    ui/newcompdialog.cpp \
    modules/clublist/clublistwidget.cpp \
    modules/modulefactory.cpp \
    ui/propertieswidget.cpp \
    modules/competitorlist/competitorlistwidget.cpp
HEADERS += modules/import/importmodule.h \
    modules/import/abstractimporter.h \
    data/abstractperson.h \
    data/competitor.h \
    data/group.h \
    data/club.h \
    data/tomanycompetitorsexception.h \
    data/judge.h \
    data/judgespanel.h \
    data/competition.h \
    modules/import/text/textimporter.h \
    modules/import/filenotopenedexception.h \
    modules/import/importpluginprovider.h \
    ui/opendialog.h \
    ui/mainwindow.h \
    ui/newcompdialog.h \
    data/abstractXMLElement.h \
    modules/clublist/clublistwidget.h \
    modules/modulefactory.h \
    modules/abstractmodule.h \
    ui/propertieswidget.h \
    modules/competitorlist/competitorlistwidget.h
FORMS += modules/import/importmodule.ui \
    ui/opendialog.ui \
    ui/mainwindow.ui \
    ui/newcompdialog.ui \
    modules/clublist/clublistwidget.ui \
    ui/propertieswidget.ui \
    modules/competitorlist/competitorlistwidget.ui
OTHER_FILES += lang/de_DE.ts
RESOURCES += ressources.qrc
