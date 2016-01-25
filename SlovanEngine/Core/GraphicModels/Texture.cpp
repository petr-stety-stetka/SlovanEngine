#include "Texture.h"
#include "../../../external/SOIL2/SOIL2.h"
#include "../Loggers/Logger.h"

#if defined(ANDROID)
#include "../../Android/AssetsIO/ReadAssetFile.h"
#endif

void Texture::loadFromFile(std::string &path) {
    Texture::path = path;
    glGenTextures(1, &ID);

    int width, height;

#if defined(PC)
    unsigned char *image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
#elif defined(ANDROID)
    std::string imageData(ReadAssetFile::ReadFileToMemory(path));
    unsigned char* image = SOIL_load_image_from_memory((unsigned char*) imageData.c_str(), (int) imageData.length(), &width, &height, 0, SOIL_LOAD_RGB);
#endif

    if (image == NULL)
        Logger::printError("Failed load texture: " + path);

    glBindTexture(GL_TEXTURE_2D, ID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    SOIL_free_image_data(image);

#if defined(ADDITIONAL_LOG)
    Logger::printInfo("Sucessfully loaded texture: " + path);
#endif
}

const std::string &Texture::getPath() const {
    return path;
}

GLuint Texture::getID() const {
    return ID;
}

void Texture::clean() {
    glDeleteTextures(1, &ID);
}