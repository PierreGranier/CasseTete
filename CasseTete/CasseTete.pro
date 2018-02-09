#-------------------------------------------------
#
# Project created by QtCreator 2018-01-17T15:10:04
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

LIBS     += -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CasseTete
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    View/interface.cpp \
    View/modelisation.cpp \
    View/pieceangle.cpp \
    View/pieced.cpp \
    View/pieceg.cpp \
    View/piecel.cpp \
    View/piecep.cpp \
    View/pieceplus.cpp \
    View/piecet.cpp \
    View/piecey.cpp \
    View/piecez.cpp \
    position.cpp \
    View/pieceView.cpp \
    Model/solution.cpp \
    Model/problem.cpp \
    Model/solver.cpp \
    Model/piecerotation.cpp \
    Model/piecemodel.cpp \
    controler.cpp

HEADERS  += \
    View/interface.h \
    View/modelisation.h \
    View/pieceangle.h \
    View/pieced.h \
    View/pieceg.h \
    View/piecel.h \
    View/piecep.h \
    View/pieceplus.h \
    View/piecet.h \
    View/piecey.h \
    View/piecez.h \
    position.h \
    View/pieceView.h \
    Model/solution.h \
    Model/problem.h \
    Model/solver.h \
    Model/piecerotation.h \
    Model/piecemodel.h \
    controler.h

FORMS    += interface.ui
