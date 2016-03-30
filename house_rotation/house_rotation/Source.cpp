#include<glut.h>

int a = 0, k = 1;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	if (k == 1)
	{
		glTranslated(300, 400, 0);
		glRotatef(a, 0, 0, 1);
		glTranslated(-300, -400, 0);
		k = 0;
	}
	glBegin(GL_TRIANGLES);
	glVertex3d(250, 250, 0);
	glVertex3d(450, 250, 0);
	glVertex3d(300, 400, 0);
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':a = a + 1; k = 1; break;
	}
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("test");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 900, 0, 900, 900, -900);
	//glutMouseFunc(mymouse);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}