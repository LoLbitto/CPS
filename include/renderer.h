#pragma once

struct Program;

typedef struct Program Program;

void draw(float* vertex, int size);
void draw_text();

Program create_program();

void use_program(Program program);

