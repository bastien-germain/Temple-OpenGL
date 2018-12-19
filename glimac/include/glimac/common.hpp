#pragma once

#include <GL/glew.h>
#include "glm.hpp"

namespace glimac {

struct ShapeVertex {
    glm::vec3 m_Position;
    glm::vec3 m_Normal;
    glm::vec2 m_TexCoords;
    
};

}
