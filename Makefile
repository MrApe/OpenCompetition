#############################################################################
# Makefile for building: OpenCompetition
# Generated by qmake (2.01a) (Qt 4.6.2) on: Mo. Mai 31 21:07:02 2010
# Project:  OpenCompetition.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile OpenCompetition.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtSql -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
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
		modules/import/importpluginprovider.cpp moc_mainwindow.cpp \
		moc_importmodule.cpp \
		moc_competition.cpp
OBJECTS       = main.o \
		mainwindow.o \
		importmodule.o \
		abstractimporter.o \
		abstractperson.o \
		competitor.o \
		group.o \
		club.o \
		tomanycompetitorsexception.o \
		judge.o \
		judgespanel.o \
		competition.o \
		textimporter.o \
		filenotopenedexception.o \
		importpluginprovider.o \
		moc_mainwindow.o \
		moc_importmodule.o \
		moc_competition.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		OpenCompetition.pro
QMAKE_TARGET  = OpenCompetition
DESTDIR       = 
TARGET        = OpenCompetition

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_importmodule.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: OpenCompetition.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtSql.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile OpenCompetition.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtSql.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile OpenCompetition.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/OpenCompetition1.0.0 || $(MKDIR) .tmp/OpenCompetition1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents mainwindow.h modules/import/importmodule.h modules/import/abstractimporter.h data/abstractperson.h data/competitor.h data/group.h data/club.h data/tomanycompetitorsexception.h data/judge.h data/judgespanel.h data/competition.h modules/import/text/textimporter.h modules/import/filenotopenedexception.h modules/import/importpluginprovider.h .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp modules/import/importmodule.cpp modules/import/abstractimporter.cpp data/abstractperson.cpp data/competitor.cpp data/group.cpp data/club.cpp data/tomanycompetitorsexception.cpp data/judge.cpp data/judgespanel.cpp data/competition.cpp modules/import/text/textimporter.cpp modules/import/filenotopenedexception.cpp modules/import/importpluginprovider.cpp .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents mainwindow.ui modules/import/importmodule.ui .tmp/OpenCompetition1.0.0/ && (cd `dirname .tmp/OpenCompetition1.0.0` && $(TAR) OpenCompetition1.0.0.tar OpenCompetition1.0.0 && $(COMPRESS) OpenCompetition1.0.0.tar) && $(MOVE) `dirname .tmp/OpenCompetition1.0.0`/OpenCompetition1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/OpenCompetition1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_importmodule.cpp moc_competition.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_importmodule.cpp moc_competition.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_importmodule.cpp: modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/import/filenotopenedexception.h \
		modules/import/importmodule.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/import/importmodule.h -o moc_importmodule.cpp

moc_competition.cpp: data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		data/competition.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) data/competition.h -o moc_competition.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_importmodule.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_importmodule.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_importmodule.h: modules/import/importmodule.ui
	/usr/bin/uic-qt4 modules/import/importmodule.ui -o ui_importmodule.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		modules/import/importmodule.h \
		modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/import/filenotopenedexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

importmodule.o: modules/import/importmodule.cpp modules/import/importmodule.h \
		modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/import/filenotopenedexception.h \
		ui_importmodule.h \
		modules/import/text/textimporter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o importmodule.o modules/import/importmodule.cpp

abstractimporter.o: modules/import/abstractimporter.cpp modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/import/filenotopenedexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractimporter.o modules/import/abstractimporter.cpp

abstractperson.o: data/abstractperson.cpp data/abstractperson.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractperson.o data/abstractperson.cpp

competitor.o: data/competitor.cpp data/competitor.h \
		data/abstractperson.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o competitor.o data/competitor.cpp

group.o: data/group.cpp data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/tomanycompetitorsexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o group.o data/group.cpp

club.o: data/club.cpp data/club.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o club.o data/club.cpp

tomanycompetitorsexception.o: data/tomanycompetitorsexception.cpp data/tomanycompetitorsexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tomanycompetitorsexception.o data/tomanycompetitorsexception.cpp

judge.o: data/judge.cpp data/judge.h \
		data/abstractperson.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o judge.o data/judge.cpp

judgespanel.o: data/judgespanel.cpp data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o judgespanel.o data/judgespanel.cpp

competition.o: data/competition.cpp data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o competition.o data/competition.cpp

textimporter.o: modules/import/text/textimporter.cpp modules/import/text/textimporter.h \
		modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/import/filenotopenedexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o textimporter.o modules/import/text/textimporter.cpp

filenotopenedexception.o: modules/import/filenotopenedexception.cpp modules/import/filenotopenedexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o filenotopenedexception.o modules/import/filenotopenedexception.cpp

importpluginprovider.o: modules/import/importpluginprovider.cpp modules/import/importpluginprovider.h \
		modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/import/filenotopenedexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o importpluginprovider.o modules/import/importpluginprovider.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_importmodule.o: moc_importmodule.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_importmodule.o moc_importmodule.cpp

moc_competition.o: moc_competition.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_competition.o moc_competition.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
