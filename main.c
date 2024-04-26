#include <GL/freeglut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void on_close() {
	exit(0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 250);
	glutCreateWindow("OpenGL Window");
	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
	glutDisplayFunc(display);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutCloseFunc(on_close);
	glutMainLoop();
	return 0;
}
