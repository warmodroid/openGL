/*   It reminds you old TV
Coded my Mohit Agrawal   */

#include<Windows.h>
#include<iostream>
#include<glut.h>
#include<stdlib.h>


using namespace std;


class rain_dropes
{
public:
	GLfloat x, y;
	void dropes();

};
void rain_dropes::dropes()
{
	x = rand() % 900;
	y = rand() % 900;

	glBegin(GL_POINTS);
	glColor3f(x / 899, y / 899, 0);
	glVertex3d(x, y, 0);
	glEnd();
}

rain_dropes aa[500];
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glPointSize(6);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);   //it shows only lines of any solid primitive

	for (int i = 0; i < 500; i++)
	{
		aa[i].dropes();
	}

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(50);
}

int  main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("test");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 900, 0, 900, 900, -900);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}