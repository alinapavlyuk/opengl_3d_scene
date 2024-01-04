#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "files/Model/Model.h"
#include "files/Shader/Shader.h"
#include "files/Object/Object.h"
#include "files/Cubemap/Cubemap.h"

void init();
GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* name);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
bool firstMouse = true;
float yaw   = -90.0f;
float pitch =  0.0f;
float lastX =  800.0f / 2.0;
float lastY =  600.0 / 2.0;
float fov   =  45.0f;
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main() {
    init();
    GLFWwindow* window = createWindow(SCR_WIDTH, SCR_HEIGHT, "Lab 3");

    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glEnable(GL_DEPTH_TEST);

    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    Shader shader("../shaders/vertex_shader.glsl", "../shaders/fragment_shader.glsl");
    Shader cubemapShader("../shaders/cubemap_vertex_shader.glsl", "../shaders/cubemap_fragment_shader.glsl");

    std::vector<float> skyboxVertices = {
            -1.0f,  1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            -1.0f,  1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            1.0f, -1.0f,  1.0f
    };

    Model cat("/Users/apvlk/Desktop/kpi/графіка/lab2/models/Cat/cat.obj");
    Model fish("/Users/apvlk/Desktop/kpi/графіка/lab2/models/Fish/fish.obj");

    Object catObj, fish1Obj, fish2Obj;

    catObj.m_scale = glm::vec3 (0.01f, 0.01f, 0.01f);
    catObj.m_rotation = glm::vec3(-90.0f, 0.0f, 0.0f);
    catObj.m_translation = glm::vec3(0.0f, 0.0f, 15.0f);

    fish1Obj.m_scale = glm::vec3 (0.05f, 0.05f, 0.05f);
    fish1Obj.m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);

    fish2Obj.m_scale = glm::vec3 (0.05f, 0.05f, 0.05f);
    fish2Obj.m_rotation = glm::vec3(0.0f, 180.0f, 0.0f);

    std::vector<std::string> faces
    {
            "../skybox/heaven_rt.jpg",
            "../skybox/heaven_lf.jpg",
            "../skybox/heaven_up.jpg",
            "../skybox/heaven_dn.jpg",
            "../skybox/heaven_bk.jpg",
            "../skybox/heaven_ft.jpg"
    };

    Cubemap cubemap(skyboxVertices, faces);

    glm::vec3 pointLightPositions[] = {
            glm::vec3( 2.0f,  2.0f,  2.0f),
            glm::vec3( -3.0f, -3.0f, -3.0f),
    };

    float aplha = 0;

    shader.use();
    shader.setInt("texture_diffuse1", 0);

    cubemapShader.use();
    cubemapShader.setInt("skybox", 0);

    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();
        shader.setVec3("viewPos", cameraPos);
        shader.setFloat("material.shininess", 256.0f);
        shader.setVec3("pointLights[0].position", pointLightPositions[0]);
        shader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
        shader.setVec3("pointLights[0].diffuse", 0.8f, 0.0f, 0.7f);
        shader.setVec3("pointLights[0].specular", 1.0f, 0.0f, 0.9f);
        shader.setFloat("pointLights[0].constant", 1.0f);
        shader.setFloat("pointLights[0].linear", 0.09f);
        shader.setFloat("pointLights[0].quadratic", 0.032f);

        shader.setVec3("pointLights[1].position", pointLightPositions[1]);
        shader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
        shader.setVec3("pointLights[1].diffuse", 0.7f, 0.8f, 0.0f);
        shader.setVec3("pointLights[1].specular", 0.9f, 1.0f, 0.0f);
        shader.setFloat("pointLights[1].constant", 1.0f);
        shader.setFloat("pointLights[1].linear", 0.09f);
        shader.setFloat("pointLights[1].quadratic", 0.032f);

        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        shader.setMat4("model", catObj.getModelMatrix());

        cat.Draw(shader);
        aplha += deltaTime;

        shader.setFloat("material.shininess", 4.0f);
        fish1Obj.spin(glm::vec3(0.0f, 3.0f, 0.0f), aplha, 10, 0.3, false);
        shader.setMat4("model", fish1Obj.getModelMatrix());
        fish.Draw(shader);

        fish2Obj.spin(glm::vec3(0.0f, 3.0f, 0.0f), -aplha, 15, 0.2,  true);
        shader.setMat4("model", fish2Obj.getModelMatrix());
        fish.Draw(shader);
        glBindVertexArray(0);

        glDepthFunc(GL_LEQUAL);
        cubemapShader.use();
        view = glm::mat4(glm::mat3(glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp)));
        cubemapShader.setMat4("view", view);
        cubemapShader.setMat4("projection", projection);
        cubemap.Draw();
        glDepthFunc(GL_LESS);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    const float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* name)
{
    GLFWwindow* window = glfwCreateWindow(width, height, name, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    return window;
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}


