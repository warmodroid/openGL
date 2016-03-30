/*   It reminds you old TV
Coded my Mohit Agrawal   */

#include<Windows.h>
#include<iostream>
#include<glut.h>
#include<IL\ilu.h>
#include<IL\il.h>
#include<stdlib.h>
#include"LTexture.h"

using namespace std;

int i = 3;
float point_size = 3;
LTexture text[3];


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
	//glColor3f(x / 899, y / 899, 0);
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
	
	text[0].rotate();
	text[0].angle += 10;



	glPushMatrix();
	glTranslatef(0, 0, -500);

	for (int k = 0; k < i; k++)
	{
		aa[k].dropes();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -500);

	for (int k = 0; k < i; k++)
	{
		aa[k].dropes();
	}
	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(90);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	
	text[0].rotate();
	text[0].angle += 10;

	glutSwapBuffers();
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



bool init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 900, 900);
	glOrtho(0, 900, 0, 900, 900, -900);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	ilInit();
	glEnable(GL_TEXTURE_2D);
	ilClearColor(255, 255, 255, 000);
	glClearColor(0, 0, 0, 0);
	GLenum erro = glGetError();

	if (erro != GL_NO_ERROR)
		return false;

	ILenum error = ilGetError();
	if (error != IL_NO_ERROR)
		return false;

	return true;

}


bool loadMedia()
{

	std::string path = "G:\\1bg13cs053\\rrr\\MultiplePoints_with_keyboard_input\\MultiplePoints_with_keyboard_input\\moon.png";
	if (text[0].LoadTextureFromImage(path))
	{
		return true;
	}

	return false;
}


int  main(int argc, char **argv)
{
	print_instructions();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 900);
	glutCreateWindow("test");
	
	if (!init())
	{
		return -1;
	}

	if (!loadMedia())
	{
		return -1;
	}

	
	glutKeyboardFunc(mykeyfunction);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}