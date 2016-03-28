#include<Windows.h>
#include<iostream>
#include<glut.h>
#include<stdlib.h>

using namespace std;

int l=3;
int k = 1;

class cubes{
public:
	int x, y, ll;
	void draw_cubes();
};

void cubes::draw_cubes()
{


	x = rand() % 900;
	y = rand() % 900;
	
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);                   //face one
	glVertex3d(x, y,0);
	glVertex3d(x+ll, y,0);
	glVertex3d(x+ll, y+ll,0);
	glVertex3d(x, y+ll,0);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);                   //face second
	glVertex3d(x+ll, y, 0);
	glVertex3d(x + ll, y, 5);
	glVertex3d(x + ll, y +ll, 5);
	glVertex3d(x+ll, y + ll, 0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);                   //face third
	glVertex3d(x , y, 5);
	glVertex3d(x + ll, y, 5);
	glVertex3d(x + ll, y+ll, 5);
	glVertex3d(x , y + ll, 5);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);                   //face fourth
	glVertex3d(x , y, 0);
	glVertex3d(x , y, 5);
	glVertex3d(x , y+ll, 5);
	glVertex3d(x , y + ll, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 1, 1);                   //face fifth
	glVertex3d(x , y+ll, 0);
	glVertex3d(x + ll, y+ll,0 );
	glVertex3d(x + ll, y+ll, 5);
	glVertex3d(x , y + ll, 5);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);                   //face sixth
	glVertex3d(x , y, 0);
	glVertex3d(x + ll, y, 0);
	glVertex3d(x + ll, y, 5);
	glVertex3d(x , y , 5);
	glEnd();
}
cubes c[5000];
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
//	glLoadIdentity();
	if (k == 1)
	{

		glRotatef(40, 1, 1, 1);
		k = 0;
	}
	for (int k = 0; k < 100; k++)
	{
		c[k].draw_cubes();
		c[k].ll = l;
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(50);
}

void mykeyboard(unsigned char key, int x, int y)
{
	
		switch (key)
		{
		case 'q': l = l + 1;
			break;
		case 'a': l = l - 1;
			break;
		
		}
}

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("World of cubes");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 900, 0, 900, 900, -900);
	glutKeyboardFunc(mykeyboard);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}