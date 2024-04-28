# pragma once

# include <math.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/freeglut.h>

void translate();
void rotate();
void scale();
void reflect();

void init(int *argc, char **argv);
void display();
void on_close();
