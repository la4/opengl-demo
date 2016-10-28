include(openglwindow.pri)

SOURCES += \
    main.cpp \
    render_object.cpp

target.path = $$PWD
INSTALLS += target

QMAKE_MAC_SDK = macosx10.12

DISTFILES += \
    shaders/fragment_shader.frag \
    shaders/vertex_shader.vert

copydata.commands = $(COPY_DIR) $$PWD/shaders $$OUT_PWD/openglwindow.app/Contents/MacOS
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

HEADERS += \
    render_object.h \
    constants.h
