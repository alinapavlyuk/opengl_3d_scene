#ifndef LAB2_MODEL_H
#define LAB2_MODEL_H

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../Mesh/Mesh.h"
#include "../Shader/Shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

class Model
{
public:
    std::vector<Texture> textures_loaded;
    std::vector<Mesh>    meshes;
    std::string directory;
    bool gammaCorrection;

    Model(std::string const &path, bool gamma = false);
    void Draw(Shader &shader);

private:
    void loadModel(std::string const &path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, const std::string& typeName);
};
#endif //LAB2_MODEL_H
