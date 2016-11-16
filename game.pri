INCLUDEPATH += $$PWD

RESOURCES =

SOURCES += $$PWD/openglwindow.cpp \
    $$PWD/engine.cpp \
    $$PWD/rendersettingsinitializations.cpp \
    $$PWD/cube.cpp \
    $$PWD/game.cpp
HEADERS += $$PWD/openglwindow.h \
    $$PWD/irenderingengine.h \
    $$PWD/engine.h \
    $$PWD/iinputhandler.h \
    $$PWD/rendersettingsinitializations.h \
    $$PWD/cube.h \
    $$PWD/iprimitiverenderobject.h \
    $$PWD/itsrobject.h \
    $$PWD/game.h

DISTFILES += \
    $$PWD/vertex_shader.vert
