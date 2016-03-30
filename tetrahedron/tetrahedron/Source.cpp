#include<stdio.h>
#include<glut.h>


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
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
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}