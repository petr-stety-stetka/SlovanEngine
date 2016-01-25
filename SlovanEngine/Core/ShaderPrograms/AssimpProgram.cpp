#include "AssimpProgram.h"
#include "../Shader/Shader.h"
#include "../Shader/Matrices.h"

#define GLM_FORCE_RADIANS

#include "../../../external/glm/gtc/type_ptr.hpp"
#include <sstream>

GLuint AssimpProgram::uMVPMatrix;
GLuint AssimpProgram::programID;

void AssimpProgram::draw(GLuint *VAOID, GLsizei indicesCount, std::vector<Texture> *textures) {
    glUseProgram(programID);

    Matrices::setMVPMatrix(Matrices::getProjectionMatrix() * Matrices::getViewMatrix() * Matrices::getModelMatrix());
    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(Matrices::getMVPMatrix()));

    for (GLuint i = 0; i < textures->size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, textures->at(i).getID());
    }

    glBindVertexArray(*VAOID);
    glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    for (GLuint i = 0; i < textures->size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    glUseProgram(0);
}

void AssimpProgram::compile() {
    std::string vertexShaderCode("layout (location = 0) in vec3 position;\n"
                                         "layout (location = 1) in vec3 normal;\n"
                                         "layout (location = 2) in vec2 texCoords;\n"
                                         "\n"
                                         "out vec2 TexCoords;\n"
                                         "\n"
                                         "uniform mat4 uMVPMatrix;\n"
                                         "\n"
                                         "void main()\n"
                                         "{\n"
                                         "    gl_Position = uMVPMatrix * vec4(position, 1.0f);\n"
                                         "    TexCoords = texCoords;\n"
                                         "}");
    std::string fragmentShaderCode("\n"
                                           "in vec2 TexCoords;\n"
                                           "\n"
                                           "out vec4 color;\n"
                                           "\n"
                                           "uniform sampler2D textureDiffuse;\n"
                                           "\n"
                                           "void main()\n"
                                           "{\n"
                                           "    color = vec4(texture(textureDiffuse, TexCoords));\n"
                                           "}");

    programID = Shader::createShaderProgram(vertexShaderCode, fragmentShaderCode);
    uMVPMatrix = (GLuint) glGetUniformLocation(programID, "uMVPMatrix");
}

void AssimpProgram::deleteShaderProgram() {
    Shader::deleteShaderProgram(programID);
}

GLuint AssimpProgram::getUMVPMatrix() {
    return uMVPMatrix;
}