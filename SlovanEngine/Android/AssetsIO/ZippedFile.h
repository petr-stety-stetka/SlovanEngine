#pragma once

#include <string>
#include <android/asset_manager.h>
#include "../../../external/assimp/IOStream.hpp"

class ZippedFile final : public Assimp::IOStream {
public:
    ZippedFile(AAsset *asset);

    ~ZippedFile();

    /** @brief Returns filesize
     *  Returns the filesize.
     */
    std::size_t FileSize() const override;

    /**
     * Flush() is unsupported for ZippedFile
     */
    void Flush() override;

    /** @brief Read from the file
     *
     * See fread() for more details
     * This fails for write-only files
     */
    std::size_t Read(void *buf, std::size_t size, std::size_t count) override;

    /** @brief Set the read/write cursor of the file
     *
     * Note that the offset is _negative_ for aiOrigin_END.
     * See fseek() for more details
     */
    aiReturn Seek(std::size_t offset, aiOrigin origin) override;

    /** @brief Get the current position of the read/write cursor
     *
     * See ftell() for more details
     */
    std::size_t Tell() const override;

    /**
     * Write() is unsupported for ZippedFile
     */
    std::size_t Write(const void *, std::size_t, std::size_t) override;

private:
    int to_whence(aiOrigin origin);

    AAsset *asset;
};
