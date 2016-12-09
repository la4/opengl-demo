#include <QtCore/QCoreApplication>
#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>

#include <QtCore/qmath.h>
#include <QDir>
#include <QTime>

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>

#include "renderingengine.h"
#include "rendersettingsinitializations.h"
#include "gameobject.h"

RenderingEngine::RenderingEngine()
    : m_context(nullptr)
    , m_surface(nullptr)
    , m_program(nullptr)
    , m_frame(0) {

    perspectiveMat.perspective(60.0f, 4.0f/3.0f, 0.1f, 1000.0f); // needs to be moved out
}

void RenderingEngine::initialize(const RenderSettingsInitializations& renderSettings) {
    m_renderingWidth = renderSettings.width();
    m_renderingHeight = renderSettings.height();
    m_devicePixelRatio = renderSettings.devicePixelRatio();
    m_refreshRate = renderSettings.refreshRate();

    srand(time(NULL));
    QString vertexShaderPath = QDir(qApp->applicationDirPath()).absoluteFilePath("shaders/vertex_shader.vert");
    QString fragmentShaderPath = QDir(qApp->applicationDirPath()).absoluteFilePath("shaders/fragment_shader.frag");

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath);
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Scene *RenderingEngine::getScene() {
    return this->m_scene;
}

void RenderingEngine::render() {
    const qreal retinaScale = m_devicePixelRatio;
    glViewport(0, 0, m_renderingWidth * retinaScale, m_renderingHeight * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_program->bind();

    for (auto it : (m_scene->getObjectsContainer())) {
        GameObject *objectToRender = it;

        QMatrix4x4 resultMat = m_scene->getCameraSet().at(0)->getViewProjection();

        resultMat *= objectToRender->getTransform()->getTransformation();

        m_program->setUniformValue(m_matrixUniform, resultMat);

        glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, objectToRender->getMesh()->getVertices());
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, objectToRender->getMesh()->getColors());


        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawElements(objectToRender->getMesh()->getPrimitiveType(),
                       objectToRender->getMesh()->indicesCount(),
                       objectToRender->getMesh()->getIndicesType(),
                       objectToRender->getMesh()->getIndices());

        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);
    }

    m_program->release();

    ++m_frame;

    m_context->swapBuffers(m_surface);
}

void RenderingEngine::setScene(Scene *scene) {
    m_scene = scene;
}

void RenderingEngine::setContext(QOpenGLContext *context) {
    m_context = context;
}

void RenderingEngine::setSurface(QSurface *surface) {
    m_surface = surface;
}
