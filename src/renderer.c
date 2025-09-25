#include <stdlib.h>

#include <glad/glad.h>

#include <renderer.h>
#include <shaders.h>

/*
struct Program {
    unsigned int program; // NOTE: idk what i will do with this struct, but i feel like using a different VAO and VBO for each program in the future
};
*/

// For now, I really have no ideia how to organize this code, that's the issue with being object-oriented pilled :(

void create_program() {
    unsigned int vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &main_vertex, NULL);
    glCompileShader(vertex_shader);

    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &main_fragment, NULL);
    glCompileShader(fragment_shader);

    unsigned int program;
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    glUseProgram(program);
}

void start() {
    unsigned int vao;
    unsigned int vbo;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    create_program();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    //glEnableVertexAttribArray(0);
}

void draw (float* vertices, int size) {
    glBufferData(GL_ARRAY_BUFFER, size, &vertices, GL_STATIC_DRAW);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
