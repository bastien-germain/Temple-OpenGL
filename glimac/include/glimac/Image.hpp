#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "glm.hpp"
#include "FilePath.hpp"

namespace glimac {

class Image {
private:
    unsigned int m_nWidth = 0u;
    unsigned int m_nHeight = 0u;
    std::unique_ptr<glm::vec4[]> m_Pixels;
public:
    Image(unsigned int width, unsigned int height):
        m_nWidth(width), m_nHeight(height), m_Pixels(new glm::vec4[width * height]) {
    }

    Image(const Image &copied): 
    m_nWidth(copied.m_nWidth), m_nHeight(copied.m_nHeight), m_Pixels(new glm::vec4[copied.m_nWidth * copied.m_nHeight]) 
    {
        for (int i = 0; i < m_nWidth*m_nHeight; ++i)
        {
            m_Pixels[i] = copied.m_Pixels[i];
        }
    }

    unsigned int getWidth() const {
        return m_nWidth;
    }

    unsigned int getHeight() const {
        return m_nHeight;
    }

    const glm::vec4* getPixels() const {
        return m_Pixels.get();
    }

    glm::vec4* getPixels() {
        return m_Pixels.get();
    }
};

std::unique_ptr<Image> loadImage(const FilePath& filepath);

class ImageManager {
private:
    static std::unordered_map<FilePath, std::unique_ptr<Image>> m_ImageMap;
public:
    static  Image* loadImage(const FilePath& filepath);
};

}
