#pragma once

#include <string>
#include <map>

#include "LoveTypes.hpp"

namespace LoveShips {
extern const std::string defaultFontName;

class ResourceManager {
public:
    explicit ResourceManager() : resourceDirPath("resources") {
        fontDirPath = resourceDirPath;
        textureDirPath = resourceDirPath;
        soundDirPath /= resourceDirPath;
        Path font("fonts");
        Path texture("textures");
        Path sounds("sounds");

        fontDirPath /= font;
        textureDirPath /= texture;
        soundDirPath /= sounds;

        defaultFont = getFontByName(defaultFontName);
    }

    Font& getDefaultFont();
    Font& getFontByName(const std::string& name);
    Texture& getTextureByName(const std::string& name);
    SoundBuffer& getSoundBufferByName(const std::string& name);

private:
    template <class T>
    T& getResourceByNameFrom(const std::string& name,
                             std::map<const std::string, T>& cache,
                             Path& dirPath);

private:
    boost::filesystem::path resourceDirPath;
    boost::filesystem::path fontDirPath;
    boost::filesystem::path textureDirPath;
    boost::filesystem::path soundDirPath;
    sf::Font defaultFont;
    std::map<const std::string, Font> fontCache;
    std::map<const std::string, Texture> textureCache;
    std::map<const std::string, SoundBuffer> soundCache;
};
}
