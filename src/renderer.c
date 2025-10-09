#        /* Poll for and process events */include <stdlib.h>
#include <stdio.h>

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
    
    int comp_stt;
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &comp_stt);

    printf("Comp vert: %i\n", comp_stt);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &comp_stt);

    printf("Comp frag: %i\n", comp_stt);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void start() {
    unsigned int vao;
    unsigned int vbo;

    create_program();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    printf("VAO: %d, VBO: %d\n", vao, vbo);
}

void draw (GLfloat vertices[], int size) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.8f, 0.3f, 0.3f, 1.0f);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    glUseProgram(1);
    glBindVertexArray(1);

    glDrawArrays(GL_TRIANGLES, 0, size * 3);
}
