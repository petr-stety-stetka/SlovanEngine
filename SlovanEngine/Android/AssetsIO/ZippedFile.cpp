#include "ZippedFile.h"
#include "../../Core/Loggers/Logger.h"

ZippedFile::ZippedFile(AAsset *asset) : asset(asset) { }

ZippedFile::~ZippedFile() {
    AAsset_close(asset);
}

std::size_t ZippedFile::FileSize() const {
    return AAsset_getLength64(asset);
}

void ZippedFile::Flush() {
    Logger::printError("Flush() is unsupported for ZippedFile");
}

std::size_t ZippedFile::ZippedFile::Read(void *buf, std::size_t size, std::size_t count) {
    return AAsset_read(asset, buf, size * count);
}

aiReturn ZippedFile::Seek(std::size_t offset, aiOrigin origin) {
    AAsset_seek64(asset, offset, to_whence(origin));
}

std::size_t ZippedFile::Tell() const {
    return AAsset_getLength64(asset) - AAsset_getRemainingLength64(asset);
}

std::size_t ZippedFile::Write(const void *, std::size_t, std::size_t) {
    Logger::printError("Write() is unsupported for ZippedFile");
}

int ZippedFile::to_whence(aiOrigin origin) {
    if (origin == aiOrigin_SET) return SEEK_SET;
    if (origin == aiOrigin_CUR) return SEEK_CUR;
    if (origin == aiOrigin_END) return SEEK_END;
    Logger::printError("AndroidIOSystem to_whence: invalid aiOrigin");
}
