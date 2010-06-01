# -------------------------------------------------
# Project created by QtCreator 2010-05-04T12:31:20
# -------------------------------------------------
QT += sql
TARGET = OpenCompetition
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
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
    modules/import/importpluginprovider.cpp
HEADERS += mainwindow.h \
    modules/import/importmodule.h \
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
    modules/import/importpluginprovider.h
FORMS += mainwindow.ui \
    modules/import/importmodule.ui
