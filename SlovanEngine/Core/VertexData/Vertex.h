#pragma once

#include "../../../external/assimp/types.h"
#include "../../../external/glm/detail/type_vec3.hpp"
#include "../../../external/glm/detail/type_vec2.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoords;
};