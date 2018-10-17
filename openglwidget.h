#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtOpenGL>
#include <QOpenGLExtraFunctions>

#include <memory>

#define NUM_STARS 500

class OpenGLWidget : public QOpenGLWidget, public QOpenGLExtraFunctions
{
    Q_OBJECT

    GLuint vao = 0;
    GLuint vboVertices = 0;
    GLuint vboIndices = 0;
    GLuint vboColors = 0;

    GLuint shaderProgram;

    std::unique_ptr<QVector4D []> vertices = nullptr;
    std::unique_ptr<QVector4D []> colors = nullptr;
    std::unique_ptr<unsigned int[]> indices = nullptr;

    QVector3D starPos[NUM_STARS]; // Position of each star in NDC

    QTimer timer;
    QTime time;

public:
    OpenGLWidget(QWidget *parent = nullptr);

    void createVBOs();
    void createShaders();
    void destroyVBOs();
    void destroyShaders();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

public slots:
    void animate();
};

#endif // OPENGLWIDGET_H
