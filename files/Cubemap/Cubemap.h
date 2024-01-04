#ifndef LAB2_CUBEMAP_H
#define LAB2_CUBEMAP_H

#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Shader/Shader.h"

class Cubemap {
    unsigned int VAO{}, VBO{};
    std::vector<float> vertices;
    unsigned int texture;

public:
    Cubemap(std::vector<float> vertices, std::vector<std::string> faces);
    void Draw() const;
private:
    void setup();
    static unsigned int loadCubemap(std::vector<std::string> faces);
};

#endif //LAB2_CUBEMAP_H
