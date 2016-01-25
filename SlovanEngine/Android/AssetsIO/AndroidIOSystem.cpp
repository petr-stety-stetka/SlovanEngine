#include "AndroidIOSystem.h"
#include "ZippedFile.h"
#include "../../Core/Loggers/Logger.h"

AAssetManager *AndroidIOSystem::assetManager;

Assimp::IOStream *AndroidIOSystem::Open(const char *pFile, const char *pMode = "rb") {
    AAsset *asset = AAssetManager_open(assetManager, pFile, AASSET_MODE_UNKNOWN);
    return new ZippedFile(asset);
}

void AndroidIOSystem::Close(Assimp::IOStream *zipped_file) {
    delete ((ZippedFile *) zipped_file);
}

bool AndroidIOSystem::ComparePaths(const char *one, const char *second) const {
    return strcmp(one, second) == 0;
}

bool AndroidIOSystem::Exists(const char *pFile) const {
    AAsset *asset = AAssetManager_open(assetManager, pFile, AASSET_MODE_UNKNOWN);
    if (asset != NULL) {
        AAsset_close(asset);
        return true;
    }
    else
        return false;
}

char AndroidIOSystem::getOsSeparator() const {
    return '/';
}

std::string AndroidIOSystem::directory(const char *filepath) {
    std::string dir = filepath;
    std::size_t i = dir.rfind('/');
    if (i != std::string::npos)
        dir = dir.substr(0, i);
    return dir;
}

void AndroidIOSystem::setAssetManager(AAssetManager *assetManager) {
    AndroidIOSystem::assetManager = assetManager;
}

AAssetManager *AndroidIOSystem::getAssetManager() {
    return assetManager;
}