#pragma once

#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <boost/filesystem.hpp>

extern const std::string defaultFontName;
class ResourceManager {
public:
    explicit ResourceManager() : resourceDirPath("resources") {
        fontDirPath = resourceDirPath;
        textureDirPath = resourceDirPath;
        soundDirPath /= resourceDirPath;
        boost::filesystem::path font("fonts");
        boost::filesystem::path texture("textures");
        boost::filesystem::path sounds("sounds");

        fontDirPath /= font;
        textureDirPath /= texture;
        soundDirPath /= sounds;

        defaultFont = getFontByName(defaultFontName);
    }

    sf::Font& getDefaultFont();
    sf::Font& getFontByName(const std::string& name);
    sf::Texture& getTextureByName(const std::string& name);
    sf::SoundBuffer& getSoundBufferByName(const std::string& name);

private:
    template <class T>
    T& getResourceByNameFrom(const std::string& name,
                             std::map<const std::string, T>& cache,
                             boost::filesystem::path& dirPath);

private:
    boost::filesystem::path resourceDirPath;
    boost::filesystem::path fontDirPath;
    boost::filesystem::path textureDirPath;
    boost::filesystem::path soundDirPath;
    sf::Font defaultFont;
    std::map<const std::string, sf::Font> fontCache;
    std::map<const std::string, sf::Texture> textureCache;
    std::map<const std::string, sf::SoundBuffer> soundCache;
};
