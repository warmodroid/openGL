#include<stdio.h>
#include<glut.h>

int a = 0, k = 1;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	if (k == 1)
	{
		glRotatef(a, 0, 1, 1);
		k = 0;
	}

	glColor3f(1, 0, 0);
	
	glBegin(GL_TRIANGLES);
	glVertex3d(0, 0, 0);
	glVertex3d(500, 0, 0);
	glVertex3d(250, 500, 0);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(500, 0, 0);
	glVertex3d(250, 0, 500);
	glVertex3d(250, 500, 0);
	glEnd();



	glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3d(250, 500, 0);
	glVertex3d(250, 0, 500);
	glVertex3d(0, 0, 0);
	glEnd();



	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}
void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q': a = a + 1; k = 1; break;
	case 'a' : a = a - 1; k = 1; break;
	}
}
int main(int argc, char **argv)
{ 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Tetrahedron");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, 500, -500);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}