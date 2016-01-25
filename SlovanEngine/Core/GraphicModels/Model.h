#pragma once

#include "Model.h"
#include "../GL/GLHeader.h"
#include "../ShaderPrograms/ShaderPrograms.h"
#include "Mesh.h"

#define GLOB_MEASURE_TIME = 1

#include "../../../external/assimp/scene.h"

using namespace std;

/**
 * Graphic model
 */
class Model {
public:
    /**
     * Load model from path.
     */
    void loadModel(std::string *path);

    /**
     * Draw model.
     */
    void draw(ShaderPrograms::shaderPrograms *shaderProgram);

    ~Model();

private:
    vector<Mesh> meshes;

    void processNode(aiNode *node, const aiScene *scene, string *directory, vector<Texture> *texturesLoaded);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene, string *directory, vector<Texture> *texturesLoaded);

    vector<Texture> loadMaterialTextures(aiMaterial *material, aiTextureType type, string *directory,
                                         vector<Texture> *texturesLoaded);
};