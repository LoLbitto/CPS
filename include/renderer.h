#pragma once

struct Program;

typedef struct Program Program;

void start();

void draw(float* vertex, int size);
void draw_text();
void create_program();

void use_program(Program program);

