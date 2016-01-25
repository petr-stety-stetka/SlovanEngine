#pragma once

#include "../GL/GLHeader.h"
#include <vector>
#include "../GraphicModels/Texture.h"


/**
 * Shader program for drawing models with assimp.
 */
class AssimpProgram {
private:
    static GLuint uMVPMatrix;
    static GLuint programID;
public:
    /**
     * Render.
     * @param VAOID ID of Vertex Array Attribute (VAO)
     * @param indicesCountCount Number of indices to draw.
     */
    static void draw(GLuint *VAOID, GLsizei indicesCount, std::vector<Texture> *textures);

    /** Compiles this shader program. */
    static void compile();

    /** Delete this shader program. */
    static void deleteShaderProgram();

    /** Get ID uniform: uMVPMatrix. For model+view+projection matrix. */
    static GLuint getUMVPMatrix();
};
