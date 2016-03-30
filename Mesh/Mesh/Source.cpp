#include<glut.h>


int x[10] = { 15, 30, 45, 60, 75, 90, 105, 120, 135, 150 };
int y[10] = { 20, 40, 60, 80, 100, 120, 140, 160, 180, 200 };

void draw_mesh()
{
	
	for (int i = 0; i < 9;i++)
	for (int j = 0; j < 9; j++)
	{
		glBegin(GL_LINE_LOOP);
		glVertex3d(x[i], y[j], 0);
		glVertex3d(x[i+1], y[j], 0);
		glVertex3d(x[i + 1], y[j+1], 0);
		glVertex3d(x[i], y[j+1], 0);
		glEnd();
	}

}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	draw_mesh();
	glFlush();
	glutSwapBuffers();
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
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}