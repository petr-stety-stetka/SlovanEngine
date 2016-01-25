#include "Model.h"
#include "../Loggers/Logger.h"
#include "../../../external/assimp/Importer.hpp"
#include "../../../external/assimp/postprocess.h"

#if defined(ANDROID)
#include "../../Android/AssetsIO/AndroidIOSystem.h"
#endif

Model::~Model() {
    for (unsigned int i = 0; i < meshes.size(); i++)
        meshes[i].clean();
}

void Model::loadModel(std::string *path) {
    Assimp::Importer importer;

#if defined(ANDROID)
    AndroidIOSystem* androidIOSystem = new AndroidIOSystem();
    importer.SetIOHandler(androidIOSystem);
#endif

    const aiScene *scene = importer.ReadFile(*path,
                                             aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_OptimizeMeshes |
                                             aiProcess_ImproveCacheLocality);

    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        Logger::printError(std::string("Failed loading model: ") + *path + std::string("\n\tASSIMP: ") +
                           importer.GetErrorString());
        return;
    }

    string directory;
    if (size_t(path->find('/') != string::npos))
        directory = path->substr(0, path->find_last_of('/'));

    vector<Texture> texturesLoaded;
    processNode(scene->mRootNode, scene, &directory, &texturesLoaded);

#if defined(ADDITIONAL_LOG)
    Logger::printInfo(std::string("Sucessfully loaded model: ") + *path);
#endif
}

void Model::processNode(aiNode *node, const aiScene *scene, string *directory, vector<Texture> *texturesLoaded) {
    for (GLuint i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene, directory, texturesLoaded));
    }

    for (GLuint i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene, directory, texturesLoaded);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene, string *directory, vector<Texture> *texturesLoaded) {
    vector<Vertex> vertices;
    vector<GLuint> indices;
    vector<Texture> textures;

    for (GLuint i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        vertex.position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        vertex.normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);

        if (mesh->mTextureCoords[0]) {
            vertex.textureCoords = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        }
        else
            vertex.textureCoords = glm::vec2(0.0f, 0.0f);
        vertices.push_back(vertex);
    }

    for (GLuint i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (GLuint j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];

    vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, directory, texturesLoaded);
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

    /* TODO
    vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, , directory, texturesLoaded);
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

    vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_NORMALS, directory, texturesLoaded);
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    */
    return Mesh(&vertices, &indices, &textures);
}

vector<Texture> Model::loadMaterialTextures(aiMaterial *material, aiTextureType type, string *directory,
                                            vector<Texture> *texturesLoaded) {
    vector<Texture> textures;
    for (GLuint i = 0; i < material->GetTextureCount(type); i++) {
        aiString file;
        material->GetTexture(type, i, &file);

        bool skip = false;
        for (GLuint j = 0; j < texturesLoaded->size(); j++) {
            if (texturesLoaded->at(j).getPath() == string(file.C_Str())) {
                textures.push_back(texturesLoaded->at(j));
                skip = true;
                break;
            }
        }
        if (!skip) {
            if (!directory->empty())
                file = *directory + "/" + file.C_Str();

            Texture texture;
            {
                std::string filePath = file.C_Str();
                texture.loadFromFile(filePath);
            }
            textures.push_back(texture);
            texturesLoaded->push_back(texture);
        }
    }
    return textures;
}

void Model::draw(ShaderPrograms::shaderPrograms *shaderProgram) {
    for (GLuint i = 0; i < meshes.size(); i++)
        meshes[i].draw(shaderProgram);
}