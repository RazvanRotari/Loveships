#include "ResourceManager.hpp"

#include <boost/filesystem.hpp>


namespace LoveShips {
extern const std::string defaultFontName = "LiberationSans-Regular.ttf";

sf::Font& ResourceManager::getDefaultFont() { return defaultFont; }

sf::Font& ResourceManager::getFontByName(const std::string& name) {
    return getResourceByNameFrom(name, fontCache, fontDirPath);
}

sf::Texture& ResourceManager::getTextureByName(const std::string& name) {
    return getResourceByNameFrom(name, textureCache, textureDirPath);
}

sf::SoundBuffer& ResourceManager::getSoundBufferByName(
    const std::string& name) {
    return getResourceByNameFrom(name, soundCache, soundDirPath);
}

template <class T>
T& ResourceManager::getResourceByNameFrom(const std::string& name,
                                          std::map<const std::string, T>& cache,
                                          boost::filesystem::path& dirPath) {
    auto fontIt = cache.find(name);

    T resource;
    if (fontIt == cache.end()) {
        boost::filesystem::path path(dirPath);
        path /= name;
        resource.loadFromFile(path.string());
        cache[name] = resource;
    }
    return cache[name];
}
}
