#include<glut.h>
int angle = 0, k = 1;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	if (k == 1)
	{

		glRotatef(angle, 1, 1, 0);
		k = 0;
	}


	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3d(100+100, 100+100, 0);
	glVertex3d(200+100, 100+100, 0);
	glVertex3d(200+100, 200+100, 0);
	glVertex3d(100+100, 200+100, 0);
	glEnd();



	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3d(200+100, 100+100, 0);
	glVertex3d(200+100, 100+100, 100);
	glVertex3d(200+100, 200+100, 100);
	glVertex3d(200+100, 200+100, 0);
	glEnd();


	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3d(200+100, 200+100, 100);
	glVertex3d(100+100, 200+100, 100);
	glVertex3d(100+100, 100+100, 100);
	glVertex3d(200+100, 100+100, 100);
	glEnd();


	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3d(100+100, 200+100, 100);
	glVertex3d(100+100, 200+100, 0);
	glVertex3d(100+100, 100+100, 0);
	glVertex3d(100+100, 100+100, 100);
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}


void mykey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':angle = angle + 1; k = 1; break;
	case 'a':angle = angle - 1; k = 1; break;
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
	glutKeyboardFunc(mykey);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
