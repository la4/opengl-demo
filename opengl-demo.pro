include(src/game/game.pri)
include(src/engine/engine.pri)

SOURCES += \
    src/main.cpp

target.path = $$PWD
INSTALLS += target

QMAKE_MAC_SDK = macosx10.12

DISTFILES += \
    src/engine/renderingengineshaders/fragment_shader.frag \
    src/engine/renderingengineshaders/vertex_shader.vert \

copydata.commands = $(COPY_DIR) $$PWD/src/engine/renderingengine/shaders $$OUT_PWD/opengl-demo.app/Contents/MacOS
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
