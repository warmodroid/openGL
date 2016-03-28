/*   It reminds you old TV
Coded my Mohit Agrawal   */

#include<Windows.h>
#include<iostream>
#include<glut.h>
#include<stdlib.h>


using namespace std;

int i = 3;
float point_size = 3;

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
	glPointSize(point_size);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);   //it shows only lines of any solid primitive

	for (int k = 0; k < i; k++)
	{
		aa[k].dropes();
	}

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(50);
}
void mykeyfunction(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q': i = i + 3;
		break;
	case 'a': i = i - 3;
		break;
	case 'w': point_size = point_size + 0.3;
		break;
	case 's': point_size = point_size - 0.3;
		break;
	}
}

void print_instructions()
{
	cout << "USE 'Q' AND 'A' TO INCREASE AND REDUCE THE NO. OF PARTICLES" << endl;
	cout << "USE 'W' AND 'S' TO INCREASE AND DECREASE THE NO SIZE OF PARTICLES" << endl;
}

int  main(int argc, char **argv)
{
	print_instructions();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("test");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 900, 0, 900, 900, -900);
	glutKeyboardFunc(mykeyfunction);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}