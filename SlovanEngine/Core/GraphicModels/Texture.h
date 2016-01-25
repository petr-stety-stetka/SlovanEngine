#pragma once

#include "string"
#include "../GL/GLHeader.h"

class Texture {
private:
    GLuint ID;
    std::string path;
public:
    /**
     * Load texture from file.
     */
    void loadFromFile(std::string &path);

    /**
     * Get path of texture file.
     */
    const std::string &getPath() const;

    /**
     * Get ID of texture.
     */
    GLuint getID() const;

    /**
     * Delete texture.
     */
    void clean();
};