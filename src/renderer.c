#include <stdlib.h>

#include <glad/glad.h>

#include <renderer.h>
#include <shaders.h>

struct Program {
    unsigned int program; // NOTE: idk what i will do with this struct, but i feel like using a different VAO and VBO for each program in the future
};

Program crate_program() {
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

    Program sav_program;

    sav_program.program = program;
}
