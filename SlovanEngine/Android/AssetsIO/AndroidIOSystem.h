#pragma once

#include "../../../external/assimp/IOSystem.hpp"
#include <android/asset_manager.h>
#include <string>

class AndroidIOSystem : public Assimp::IOSystem {
public:
    /** @brief Open a new file with a given path.
     *
     *  When the access to the file is finished, call Close() to release
     *  all associated resources (or the virtual dtor of the IOStream).
     *
     *  @param pFile Path to the file
     *  @param pMode Desired file I/O mode. Required are: "wb", "w", "wt",
     *         "rb", "r", "rt".
     *
     *  @return New IOStream interface allowing the lib to access
     *         the underlying file.
     *  @note When implementing this class to provide custom IO handling,
     *  you probably have to supply an own implementation of IOStream as well.
     */
    Assimp::IOStream *Open(const char *pFile, const char *pMode) override;

    /** @brief Closes the given file and releases all resources
     *    associated with it.
     *  @param pFile The file instance previously created by Open().
     */
    void Close(Assimp::IOStream *zipped_file) override;

    /** @brief Compares two paths and check whether the point to
     *         identical files.
     *
     * The dummy implementation of this virtual member performs a
     * case-insensitive comparison of the given strings. The default IO
     * system implementation uses OS mechanisms to convert relative into
     * absolute paths, so the result can be trusted.
     * @param one First file
     * @param second Second file
     * @return true if the paths point to the same file. The file needn't
     *   be existing, however.
     */
    bool ComparePaths(const char *one, const char *second) const override;

    /** @brief Tests for the existence of a file at the given path.
     *
     * @param pFile Path to the file
     * @return true if there is a file with this path, else false.
     */
    bool Exists(const char *pFile) const override;

    /** @brief Returns the system specific directory separator
     *  @return System specific directory separator
     */
    char getOsSeparator() const override;

    /**
     * Set asset manager.
     */
    static void setAssetManager(AAssetManager *assetManager);

    /**
     * Get asset manager.
     */
    static AAssetManager *getAssetManager();

private:
    static AAssetManager *assetManager;
    std::string last_path;

    std::string directory(const char *filepath);
};
