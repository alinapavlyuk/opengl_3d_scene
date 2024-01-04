#include "Object.h"

glm::mat4 Object::getModelMatrix() {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, m_scale);
    model = glm::translate(model, m_translation);
    model = glm::rotate(model, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    return model;
}

void Object::spin(const glm::vec3& center, float alpha, float radius, float frequency, bool isMirrored) {
    float direction = isMirrored ? 180.0f : 0.0f;
    m_translation = center + radius * glm::vec3(cos(2 * M_PI * alpha * frequency), 0, sin(2 * M_PI * alpha * frequency));
    m_rotation = glm::vec3(0.0f, direction + 360.0f * alpha * -frequency, 0.0f);
}
