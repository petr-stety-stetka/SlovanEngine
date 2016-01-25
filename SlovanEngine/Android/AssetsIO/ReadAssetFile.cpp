#include "ReadAssetFile.h"
#include "../../Android/AssetsIO/AndroidIOSystem.h"
#include <android/asset_manager.h>
#include "../../Core/Loggers/Logger.h"

std::string ReadAssetFile::ReadFileToMemory(std::string &path) {
    AAsset *asset = AAssetManager_open(AndroidIOSystem::getAssetManager(), path.c_str(), AASSET_MODE_UNKNOWN);
    if (asset == NULL)
        Logger::printError("Failed open file from assets: " + path);

    std::size_t size = AAsset_getLength64(asset);
    std::string data;
    data.resize(size);
    AAsset_read(asset, &data[0], size);
    AAsset_close(asset);
    return data;
}