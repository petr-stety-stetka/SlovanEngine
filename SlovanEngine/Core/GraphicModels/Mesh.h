#pragma once

#include "../ShaderPrograms/ShaderPrograms.h"
#include "vector"
#include "../VertexData/Vertex.h"
#include "Texture.h"

using namespace std;

class Mesh {
public:
    /**
     * Create mesh for model
     */
    Mesh(vector<Vertex> *vertices, vector<GLuint> *indices, vector<Texture> *textures);

    /**
     * Draw mesh.
     */
    void draw(ShaderPrograms::shaderPrograms *shaderProgram);

    /**
     * Delete mesh.
     */
    void clean();

private:
    GLuint VAO, VBO, EBO;
    vector<Vertex> vertices;
    vector<GLuint> indices;
    vector<Texture> textures;
};


