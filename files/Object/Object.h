#ifndef LAB2_OBJECT_H
#define LAB2_OBJECT_H

#include <stdexcept>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Object
{
public:
    glm::vec3 m_rotation = {0.0f, 0.0f, 0.0f};
    glm::vec3 m_translation = {0.0f, 0.0f, 0.0f};
    glm::vec3 m_scale = {1.0f, 1.0f, 1.0f};

    glm::mat4 getModelMatrix();

    void spin(const glm::vec3& center, float alpha, float radius, float frequency, bool isMirrored);
};

#endif //LAB2_OBJECT_H
