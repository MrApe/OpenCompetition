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
    data/judgespanel.cpp
HEADERS += mainwindow.h \
    modules/import/importmodule.h \
    modules/import/abstractimporter.h \
    data/abstractperson.h \
    data/competitor.h \
    data/group.h \
    data/club.h \
    data/tomanycompetitorsexception.h \
    data/judge.h \
    data/judgespanel.h
FORMS += mainwindow.ui \
    modules/import/importmodule.ui
