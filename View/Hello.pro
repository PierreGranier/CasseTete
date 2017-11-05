QT += widgets
QT += opengl
QT += core
QT += gui
CONFIG += c++11
CONFIG += console
LIBS   += -lopengl32
LIBS   += -lglu32
LIBS   += -lglut32
SOURCES += \
    main.cpp \
    glclass.cpp \
    mywindow.cpp \
    cube.cpp \
    transform3d.cpp \
    camera3d.cpp \
    pieceplus.cpp \
    piecep.cpp \
    pieceangle.cpp \
    piecel.cpp \
    piecet.cpp \
    piecey.cpp \
    pieced.cpp \
    pieceg.cpp \
    piecez.cpp

HEADERS += \
    glclass.h \
    mywindow.h \
    cube.h \
    vertex.h \
    transform3d.h \
    camera3d.h \
    pieceplus.h \
    piecep.h \
    pieceangle.h \
    piecel.h \
    piecet.h \
    piecey.h \
    pieced.h \
    pieceg.h \
    piecez.h

RESOURCES += \
    textures.qrc \
    resources.qrc






