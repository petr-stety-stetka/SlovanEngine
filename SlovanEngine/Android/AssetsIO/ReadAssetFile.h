#pragma once

#include <string>

class ReadAssetFile {
public:
    /**
     * Load file to memory, and return data.
     */
    static std::string ReadFileToMemory(std::string &path);
};
