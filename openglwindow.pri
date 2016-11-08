INCLUDEPATH += $$PWD

RESOURCES =

SOURCES += $$PWD/openglwindow.cpp \
    $$PWD/engine.cpp \
    $$PWD/rendersettingsinitializations.cpp
HEADERS += $$PWD/openglwindow.h \
    $$PWD/irenderingengine.h \
    $$PWD/engine.h \
    $$PWD/iinputhandler.h \
    $$PWD/rendersettingsinitializations.h

DISTFILES += \
    $$PWD/vertex_shader.vert
