#include "Mesh.h"
#include "../ShaderPrograms/AssimpProgram.h"

Mesh::Mesh(vector<Vertex> *vertices, vector<GLuint> *indices, vector<Texture> *textures) {
    this->vertices = *vertices;
    this->indices = *indices;
    this->textures = *textures;

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, textureCoords));

    glBindVertexArray(0);
}

void Mesh::clean() {
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);

    for (unsigned int i = 0; i < textures.size(); i++)
        textures[i].clean();
}

void Mesh::draw(ShaderPrograms::shaderPrograms *shaderProgram) {
    switch (*shaderProgram) {
        case ShaderPrograms::shaderPrograms::AssimpProgram:
            AssimpProgram::draw(&VAO, indices.size(), &textures);
            break;
    }
}