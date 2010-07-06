#############################################################################
# Makefile for building: OpenCompetition
# Generated by qmake (2.01a) (Qt 4.6.2) on: Di. Jul 6 19:05:40 2010
# Project:  OpenCompetition.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile OpenCompetition.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SQL_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtSql -lQtXml -lQtGui -lQtCore -lpthread 
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
		modules/competitorlist/competitorlistwidget.cpp \
		ui/aboutdialog.cpp \
		modules/judgespanel/judgespanelwidget.cpp \
		modules/judgespanel/judgeeditorwidget.cpp moc_importmodule.cpp \
		moc_competition.cpp \
		moc_opendialog.cpp \
		moc_mainwindow.cpp \
		moc_newcompdialog.cpp \
		moc_clublistwidget.cpp \
		moc_modulefactory.cpp \
		moc_abstractmodule.cpp \
		moc_propertieswidget.cpp \
		moc_competitorlistwidget.cpp \
		moc_aboutdialog.cpp \
		moc_judgespanelwidget.cpp \
		moc_judgeeditorwidget.cpp \
		qrc_ressources.cpp
OBJECTS       = main.o \
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
		opendialog.o \
		mainwindow.o \
		newcompdialog.o \
		clublistwidget.o \
		modulefactory.o \
		propertieswidget.o \
		competitorlistwidget.o \
		aboutdialog.o \
		judgespanelwidget.o \
		judgeeditorwidget.o \
		moc_importmodule.o \
		moc_competition.o \
		moc_opendialog.o \
		moc_mainwindow.o \
		moc_newcompdialog.o \
		moc_clublistwidget.o \
		moc_modulefactory.o \
		moc_abstractmodule.o \
		moc_propertieswidget.o \
		moc_competitorlistwidget.o \
		moc_aboutdialog.o \
		moc_judgespanelwidget.o \
		moc_judgeeditorwidget.o \
		qrc_ressources.o
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

$(TARGET): ui_importmodule.h ui_opendialog.h ui_mainwindow.h ui_newcompdialog.h ui_clublistwidget.h ui_propertieswidget.h ui_competitorlistwidget.h ui_aboutdialog.h ui_judgespanelwidget.h ui_judgeeditorwidget.h $(OBJECTS)  
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
		/usr/lib/libQtXml.prl \
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
/usr/lib/libQtXml.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile OpenCompetition.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/OpenCompetition1.0.0 || $(MKDIR) .tmp/OpenCompetition1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents modules/import/importmodule.h modules/import/abstractimporter.h data/abstractperson.h data/competitor.h data/group.h data/club.h data/tomanycompetitorsexception.h data/judge.h data/judgespanel.h data/competition.h modules/import/text/textimporter.h modules/import/filenotopenedexception.h modules/import/importpluginprovider.h ui/opendialog.h ui/mainwindow.h ui/newcompdialog.h data/abstractXMLElement.h modules/clublist/clublistwidget.h modules/modulefactory.h modules/abstractmodule.h ui/propertieswidget.h modules/competitorlist/competitorlistwidget.h ui/aboutdialog.h modules/judgespanel/judgespanelwidget.h modules/judgespanel/judgeeditorwidget.h .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents ressources.qrc .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents main.cpp modules/import/importmodule.cpp modules/import/abstractimporter.cpp data/abstractperson.cpp data/competitor.cpp data/group.cpp data/club.cpp data/tomanycompetitorsexception.cpp data/judge.cpp data/judgespanel.cpp data/competition.cpp modules/import/text/textimporter.cpp modules/import/filenotopenedexception.cpp modules/import/importpluginprovider.cpp ui/opendialog.cpp ui/mainwindow.cpp ui/newcompdialog.cpp modules/clublist/clublistwidget.cpp modules/modulefactory.cpp ui/propertieswidget.cpp modules/competitorlist/competitorlistwidget.cpp ui/aboutdialog.cpp modules/judgespanel/judgespanelwidget.cpp modules/judgespanel/judgeeditorwidget.cpp .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents modules/import/importmodule.ui ui/opendialog.ui ui/mainwindow.ui ui/newcompdialog.ui modules/clublist/clublistwidget.ui ui/propertieswidget.ui modules/competitorlist/competitorlistwidget.ui ui/aboutdialog.ui modules/judgespanel/judgespanelwidget.ui modules/judgespanel/judgeeditorwidget.ui .tmp/OpenCompetition1.0.0/ && $(COPY_FILE) --parents lang/de_DE.ts .tmp/OpenCompetition1.0.0/ && (cd `dirname .tmp/OpenCompetition1.0.0` && $(TAR) OpenCompetition1.0.0.tar OpenCompetition1.0.0 && $(COMPRESS) OpenCompetition1.0.0.tar) && $(MOVE) `dirname .tmp/OpenCompetition1.0.0`/OpenCompetition1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/OpenCompetition1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_importmodule.cpp moc_competition.cpp moc_opendialog.cpp moc_mainwindow.cpp moc_newcompdialog.cpp moc_clublistwidget.cpp moc_modulefactory.cpp moc_abstractmodule.cpp moc_propertieswidget.cpp moc_competitorlistwidget.cpp moc_aboutdialog.cpp moc_judgespanelwidget.cpp moc_judgeeditorwidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_importmodule.cpp moc_competition.cpp moc_opendialog.cpp moc_mainwindow.cpp moc_newcompdialog.cpp moc_clublistwidget.cpp moc_modulefactory.cpp moc_abstractmodule.cpp moc_propertieswidget.cpp moc_competitorlistwidget.cpp moc_aboutdialog.cpp moc_judgespanelwidget.cpp moc_judgeeditorwidget.cpp
moc_importmodule.cpp: modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/abstractXMLElement.h \
		data/tomanycompetitorsexception.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		modules/import/filenotopenedexception.h \
		modules/import/importpluginprovider.h \
		modules/import/importmodule.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/import/importmodule.h -o moc_importmodule.cpp

moc_competition.cpp: data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		data/competition.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) data/competition.h -o moc_competition.cpp

moc_opendialog.cpp: data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui/opendialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/opendialog.h -o moc_opendialog.cpp

moc_mainwindow.cpp: data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/modulefactory.h \
		modules/abstractmodule.h \
		ui/mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/mainwindow.h -o moc_mainwindow.cpp

moc_newcompdialog.cpp: data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui/newcompdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/newcompdialog.h -o moc_newcompdialog.cpp

moc_clublistwidget.cpp: modules/abstractmodule.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/clublist/clublistwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/clublist/clublistwidget.h -o moc_clublistwidget.cpp

moc_modulefactory.cpp: modules/abstractmodule.h \
		modules/modulefactory.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/modulefactory.h -o moc_modulefactory.cpp

moc_abstractmodule.cpp: modules/abstractmodule.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/abstractmodule.h -o moc_abstractmodule.cpp

moc_propertieswidget.cpp: data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui/propertieswidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/propertieswidget.h -o moc_propertieswidget.cpp

moc_competitorlistwidget.cpp: modules/abstractmodule.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/competitorlist/competitorlistwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/competitorlist/competitorlistwidget.h -o moc_competitorlistwidget.cpp

moc_aboutdialog.cpp: ui/aboutdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui/aboutdialog.h -o moc_aboutdialog.cpp

moc_judgespanelwidget.cpp: modules/abstractmodule.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/judgespanel/judgespanelwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/judgespanel/judgespanelwidget.h -o moc_judgespanelwidget.cpp

moc_judgeeditorwidget.cpp: data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		modules/judgespanel/judgeeditorwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modules/judgespanel/judgeeditorwidget.h -o moc_judgeeditorwidget.cpp

compiler_rcc_make_all: qrc_ressources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_ressources.cpp
qrc_ressources.cpp: ressources.qrc \
		images/ImageLicence.txt \
		images/icons/folder_open_64_d.png \
		images/icons/print_preview_64_h.png \
		images/icons/print_preview_64.png \
		images/icons/history_64_h.png \
		images/icons/home_brown_64_h.png \
		images/icons/favorites_64.png \
		images/icons/open_document_64_d.png \
		images/icons/mail_64_h.png \
		images/icons/home_green_64.png \
		images/icons/properties_doc_64_h.png \
		images/icons/folder_open_64_h.png \
		images/icons/home_yellow_64.png \
		images/icons/undo_round_64_d.png \
		images/icons/views_64_h.png \
		images/icons/redo_64_h.png \
		images/icons/undo_64.png \
		images/icons/folder_options_64_h.png \
		images/icons/copy_clipboard_64.png \
		images/icons/folders_64_d.png \
		images/icons/undo_square_64_h.png \
		images/icons/search_64.png \
		images/icons/save_green_64_h.png \
		images/icons/cut_clipboard_64.png \
		images/icons/copy_to_folder_64_h.png \
		images/icons/properties_doc_64_d.png \
		images/icons/refresh_doc_64_h.png \
		images/icons/paste_clipboard_64_d.png \
		images/icons/home_purple_64_d.png \
		images/icons/views_64_d.png \
		images/icons/folder_closed_64_d.png \
		images/icons/copy_to_folder_64.png \
		images/icons/up_folder_64.png \
		images/icons/copy_clipboard_64_h.png \
		images/icons/copy_to_folder_64_d.png \
		images/icons/redo_square_64_h.png \
		images/icons/delete_x_64_d.png \
		images/icons/views_64.png \
		images/icons/print_preview_64_d.png \
		images/icons/refresh_doc_64.png \
		images/icons/folders_64.png \
		images/icons/up_folder_64_d.png \
		images/icons/folder_closed_64_h.png \
		images/icons/history_64_d.png \
		images/icons/folder_options_64.png \
		images/icons/home_brown_64_d.png \
		images/icons/arrowright_green_64.png \
		images/icons/copy_clipboard_64_d.png \
		images/icons/new_document_64_d.png \
		images/icons/save_64_h.png \
		images/icons/undo_round_64_h.png \
		images/icons/up_folder_64_h.png \
		images/icons/cut_clipboard_64_h.png \
		images/icons/folder_options_64_d.png \
		images/icons/arrowright_green_64_d.png \
		images/icons/move_to_folder_64_h.png \
		images/icons/undo_square_64.png \
		images/icons/save_green_64.png \
		images/icons/save_green_64_d.png \
		images/icons/refresh_doc_64_d.png \
		images/icons/home_purple_64.png \
		images/icons/redo_square_64.png \
		images/icons/print_64_h.png \
		images/icons/mail_64.png \
		images/icons/open_document_64.png \
		images/icons/move_to_folder_64_d.png \
		images/icons/arrowleft_green_64.png \
		images/icons/move_to_folder_64.png \
		images/icons/Trash_256x256.png \
		images/icons/home_green_64_h.png \
		images/icons/history_64.png \
		images/icons/redo_round64_h.png \
		images/icons/arrowleft_green_64_d.png \
		images/icons/undo_64_d.png \
		images/icons/delete_x_64.png \
		images/icons/new_document_64_h.png \
		images/icons/search_64_d.png \
		images/icons/stop_64_h.png \
		images/icons/home_green_64_d.png \
		images/icons/favorites_64_h.png \
		images/icons/save_64_d.png \
		images/icons/redo_round64_d.png \
		images/icons/arrowleft_green_64_h.png \
		images/icons/cut_clipboard_64_d.png \
		images/icons/arrowright_green_64_h.png \
		images/icons/stop_64_d.png \
		images/icons/folder_closed_64.png \
		images/icons/home_yellow_64_d.png \
		images/icons/search_64_h.png \
		images/icons/print_64.png \
		images/icons/properties_doc_64.png \
		images/icons/redo_64_d.png \
		images/icons/home_brown_64.png \
		images/icons/print_64_d.png \
		images/icons/folders_64_h.png \
		images/icons/undo_square_64_d.png \
		images/icons/new_document_64.png \
		images/icons/home_yellow_64_h.png \
		images/icons/redo_round64.png \
		images/icons/Logo.png \
		images/icons/paste_clipboard_64_h.png \
		images/icons/save_64.png \
		images/icons/undo_round_64.png \
		images/icons/home_purple_64_h.png \
		images/icons/undo_64_h.png \
		images/icons/open_document_64_h.png \
		images/icons/stop_64.png \
		images/icons/folder_open_64.png \
		images/icons/mail_64_d.png \
		images/icons/paste_clipboard_64.png \
		images/icons/redo_64.png \
		images/icons/favorites_64_d.png \
		images/icons/redo_square_64_d.png
	/usr/bin/rcc -name ressources ressources.qrc -o qrc_ressources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_importmodule.h ui_opendialog.h ui_mainwindow.h ui_newcompdialog.h ui_clublistwidget.h ui_propertieswidget.h ui_competitorlistwidget.h ui_aboutdialog.h ui_judgespanelwidget.h ui_judgeeditorwidget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_importmodule.h ui_opendialog.h ui_mainwindow.h ui_newcompdialog.h ui_clublistwidget.h ui_propertieswidget.h ui_competitorlistwidget.h ui_aboutdialog.h ui_judgespanelwidget.h ui_judgeeditorwidget.h
ui_importmodule.h: modules/import/importmodule.ui
	/usr/bin/uic-qt4 modules/import/importmodule.ui -o ui_importmodule.h

ui_opendialog.h: ui/opendialog.ui
	/usr/bin/uic-qt4 ui/opendialog.ui -o ui_opendialog.h

ui_mainwindow.h: ui/mainwindow.ui
	/usr/bin/uic-qt4 ui/mainwindow.ui -o ui_mainwindow.h

ui_newcompdialog.h: ui/newcompdialog.ui
	/usr/bin/uic-qt4 ui/newcompdialog.ui -o ui_newcompdialog.h

ui_clublistwidget.h: modules/clublist/clublistwidget.ui
	/usr/bin/uic-qt4 modules/clublist/clublistwidget.ui -o ui_clublistwidget.h

ui_propertieswidget.h: ui/propertieswidget.ui
	/usr/bin/uic-qt4 ui/propertieswidget.ui -o ui_propertieswidget.h

ui_competitorlistwidget.h: modules/competitorlist/competitorlistwidget.ui
	/usr/bin/uic-qt4 modules/competitorlist/competitorlistwidget.ui -o ui_competitorlistwidget.h

ui_aboutdialog.h: ui/aboutdialog.ui
	/usr/bin/uic-qt4 ui/aboutdialog.ui -o ui_aboutdialog.h

ui_judgespanelwidget.h: modules/judgespanel/judgespanelwidget.ui
	/usr/bin/uic-qt4 modules/judgespanel/judgespanelwidget.ui -o ui_judgespanelwidget.h

ui_judgeeditorwidget.h: modules/judgespanel/judgeeditorwidget.ui
	/usr/bin/uic-qt4 modules/judgespanel/judgeeditorwidget.ui -o ui_judgeeditorwidget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp ui/mainwindow.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/modulefactory.h \
		modules/abstractmodule.h \
		ui/opendialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

importmodule.o: modules/import/importmodule.cpp modules/import/importmodule.h \
		modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/abstractXMLElement.h \
		data/tomanycompetitorsexception.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		modules/import/filenotopenedexception.h \
		modules/import/importpluginprovider.h \
		ui_importmodule.h \
		modules/import/text/textimporter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o importmodule.o modules/import/importmodule.cpp

abstractimporter.o: modules/import/abstractimporter.cpp modules/import/abstractimporter.h \
		data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/abstractXMLElement.h \
		data/tomanycompetitorsexception.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		modules/import/filenotopenedexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractimporter.o modules/import/abstractimporter.cpp

abstractperson.o: data/abstractperson.cpp data/abstractperson.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractperson.o data/abstractperson.cpp

competitor.o: data/competitor.cpp data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/abstractXMLElement.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o competitor.o data/competitor.cpp

group.o: data/group.cpp data/group.h \
		data/competitor.h \
		data/abstractperson.h \
		data/club.h \
		data/abstractXMLElement.h \
		data/tomanycompetitorsexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o group.o data/group.cpp

club.o: data/club.cpp data/club.h \
		data/abstractXMLElement.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o club.o data/club.cpp

tomanycompetitorsexception.o: data/tomanycompetitorsexception.cpp data/tomanycompetitorsexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tomanycompetitorsexception.o data/tomanycompetitorsexception.cpp

judge.o: data/judge.cpp data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o judge.o data/judge.cpp

judgespanel.o: data/judgespanel.cpp data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o judgespanel.o data/judgespanel.cpp

competition.o: data/competition.cpp data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o competition.o data/competition.cpp

textimporter.o: modules/import/text/textimporter.cpp modules/import/text/textimporter.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/import/abstractimporter.h \
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
		data/abstractXMLElement.h \
		data/tomanycompetitorsexception.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		modules/import/filenotopenedexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o importpluginprovider.o modules/import/importpluginprovider.cpp

opendialog.o: ui/opendialog.cpp ui/opendialog.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui_opendialog.h \
		ui/newcompdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o opendialog.o ui/opendialog.cpp

mainwindow.o: ui/mainwindow.cpp ui/mainwindow.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/modulefactory.h \
		modules/abstractmodule.h \
		ui_mainwindow.h \
		modules/import/importmodule.h \
		modules/import/abstractimporter.h \
		modules/import/filenotopenedexception.h \
		modules/import/importpluginprovider.h \
		ui/opendialog.h \
		modules/clublist/clublistwidget.h \
		modules/competitorlist/competitorlistwidget.h \
		modules/judgespanel/judgespanelwidget.h \
		ui/propertieswidget.h \
		ui/aboutdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o ui/mainwindow.cpp

newcompdialog.o: ui/newcompdialog.cpp ui/newcompdialog.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui_newcompdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o newcompdialog.o ui/newcompdialog.cpp

clublistwidget.o: modules/clublist/clublistwidget.cpp modules/clublist/clublistwidget.h \
		modules/abstractmodule.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui_clublistwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o clublistwidget.o modules/clublist/clublistwidget.cpp

modulefactory.o: modules/modulefactory.cpp modules/modulefactory.h \
		modules/abstractmodule.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o modulefactory.o modules/modulefactory.cpp

propertieswidget.o: ui/propertieswidget.cpp ui/propertieswidget.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui_propertieswidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o propertieswidget.o ui/propertieswidget.cpp

competitorlistwidget.o: modules/competitorlist/competitorlistwidget.cpp modules/competitorlist/competitorlistwidget.h \
		modules/abstractmodule.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		ui_competitorlistwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o competitorlistwidget.o modules/competitorlist/competitorlistwidget.cpp

aboutdialog.o: ui/aboutdialog.cpp ui/aboutdialog.h \
		ui_aboutdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o aboutdialog.o ui/aboutdialog.cpp

judgespanelwidget.o: modules/judgespanel/judgespanelwidget.cpp modules/judgespanel/judgespanelwidget.h \
		modules/abstractmodule.h \
		data/competition.h \
		data/judgespanel.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		data/group.h \
		data/competitor.h \
		data/club.h \
		data/tomanycompetitorsexception.h \
		modules/judgespanel/judgeeditorwidget.h \
		ui_judgespanelwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o judgespanelwidget.o modules/judgespanel/judgespanelwidget.cpp

judgeeditorwidget.o: modules/judgespanel/judgeeditorwidget.cpp modules/judgespanel/judgeeditorwidget.h \
		data/judge.h \
		data/abstractperson.h \
		data/abstractXMLElement.h \
		ui_judgeeditorwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o judgeeditorwidget.o modules/judgespanel/judgeeditorwidget.cpp

moc_importmodule.o: moc_importmodule.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_importmodule.o moc_importmodule.cpp

moc_competition.o: moc_competition.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_competition.o moc_competition.cpp

moc_opendialog.o: moc_opendialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_opendialog.o moc_opendialog.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_newcompdialog.o: moc_newcompdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_newcompdialog.o moc_newcompdialog.cpp

moc_clublistwidget.o: moc_clublistwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_clublistwidget.o moc_clublistwidget.cpp

moc_modulefactory.o: moc_modulefactory.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_modulefactory.o moc_modulefactory.cpp

moc_abstractmodule.o: moc_abstractmodule.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_abstractmodule.o moc_abstractmodule.cpp

moc_propertieswidget.o: moc_propertieswidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_propertieswidget.o moc_propertieswidget.cpp

moc_competitorlistwidget.o: moc_competitorlistwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_competitorlistwidget.o moc_competitorlistwidget.cpp

moc_aboutdialog.o: moc_aboutdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_aboutdialog.o moc_aboutdialog.cpp

moc_judgespanelwidget.o: moc_judgespanelwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_judgespanelwidget.o moc_judgespanelwidget.cpp

moc_judgeeditorwidget.o: moc_judgeeditorwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_judgeeditorwidget.o moc_judgeeditorwidget.cpp

qrc_ressources.o: qrc_ressources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_ressources.o qrc_ressources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

