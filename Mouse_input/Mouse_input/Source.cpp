#include<Windows.h>
#include<iostream>
#include<glut.h>
#include<stdlib.h>

using namespace std;
const int n = 1500;
int xx = 45, yy = 45, zz = 0;
class points{
public:
	GLfloat x, y, z;
	void draw_points();
};

void points::draw_points()
{
	glPointSize(5);
	glColor3f(0, 1, 1);
	glBegin(GL_POINTS);
	glVertex3d(x, y, z);
	glEnd();
}


points p[n];

void particles()
{
	for (int k = 0; k < n; k++)
	{
		p[k].x = p[k].x + rand() % 3;

		p[k].x = p[k].x - rand() % 2;
		p[k].y = p[k].y - rand() % 2;
		p[k].y = p[k].y + rand() % 3;
		if (p[k].x>900)
			p[k].x = rand() % 500;
		if (p[k].y>900)
			p[k].y = rand() % 500;
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glRotatef(0, xx, yy, zz);
	for (int k = 0; k < n; k++)
		p[k].draw_points();

	particles();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(50);
}



void mymouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN);
	{
		for (int k = 0; k < n; k++)
		{
			p[k].x = x;
			p[k].y = y;
		}
	}
}

void mykeyboard(unsigned char Key, int x, int y)
{

}

int main(int argc, char **argv)
{
	for (int k = 0; k < n; k++)
	{
		p[k].x = rand() % 900;
		p[k].y = rand() % 900;
		p[k].z = rand() % 900;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("test");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 900, 0, 900, 900, -900);
	glutMouseFunc(mymouse);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}