#include "ShaderController.h"

namespace ShaderController {

void ShaderController::initialize() {
    shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, QString(":/VertexShader.vsh"));
    shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, QString(":/FragmentShader.fsh"));
    shaderProgram.link();
}

void ShaderController::startWork() {
    shaderProgram.bind();
    shaderProgram.enableAttributeArray("vertex");
}

void ShaderController::endWork() {
    shaderProgram.disableAttributeArray("vertex");
    shaderProgram.release();
}

void ShaderController::setVertex() {
    shaderProgram.setAttributeArray("vertex", GL_FLOAT, 0, 3);
}

void ShaderController::setMatrix(const QMatrix4x4 &matrix) {
    shaderProgram.setUniformValue("matrix", matrix);
}

void ShaderController::setArcadeMode(bool enabled) {
    shaderProgram.setUniformValue("arcadeMode", enabled);
}

void ShaderController::setStartTailSize(float size) {
    shaderProgram.setUniformValue("startTailSize", size);
}

void ShaderController::setFinalTailSize(float size) {
    shaderProgram.setUniformValue("finalTailSize", size);
}

void ShaderController::setTailLength(size_t length) {
    shaderProgram.setUniformValue("tailLength", static_cast<int>(length));
}

void ShaderController::setStartVertexIndex(size_t index) {
    shaderProgram.setUniformValue("startIndex", static_cast<int>(index));
}

void ShaderController::setColor(const QColor &color) {
    shaderProgram.setUniformValue("color", color);
}

} //namespace ShaderController