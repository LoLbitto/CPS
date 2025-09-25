#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <renderer.h>

int main(void) {

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "CPS", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    float vertices[] = {-1.0f, -0.25f, 0.5f, 0.0f, 1.0f, 0.5f, 1.0f, -0.25f, 0.5f};

    while (!glfwWindowShouldClose(window)) {
        start();
	draw(vertices, 9);

	glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
    
}
