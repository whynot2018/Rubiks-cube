//#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define ESC 27

GLfloat fAspect;
GLint angle, gap = 2; // Gap between each cube
float d = 1;		  //width of the cube
int rot_x = 0, rot_y = 0, rot_z = 0;
int whole = 0;

// Structure to store the coordinates of the cube
struct point
{
	float x, y, z;
};

struct face
{
	struct point p[4];
};
struct cube
{

	float x;
	float y;
	float z;
	struct face f[6];

	int rotateX, rotateY, rotateZ;
};
struct cube c[27];

const GLfloat colors[][3] =
	{
		{1.0, 0.5, 0},
		{1.0, 0.0, 0},
		{0.0, 0.0, 1},
		{0.0, 1.0, 0},
		{1.0, 1.0, 0}, //yellow
		{1.0, 1.0, 1},
};

void fillstruct()
{
	int count = 0;
	for (int z = -1; z <= 1; z++)

		for (int y = -1; y <= 1; y++)

			for (int x = -1; x <= 1; x++)
			{
				c[count].x = x;
				c[count].y = y;
				c[count].z = z;

				c[count].f[0].p[0].x = x - d / 2;
				c[count].f[0].p[0].y = y + d / 2;
				c[count].f[0].p[0].z = z - d / 2;

				c[count].f[0].p[1].x = x - d / 2;
				c[count].f[0].p[01].y = y - d / 2;
				c[count].f[0].p[01].z = z - d / 2;

				c[count].f[0].p[02].x = x + d / 2;
				c[count].f[0].p[02].y = y - d / 2;
				c[count].f[0].p[02].z = z - d / 2;

				c[count].f[0].p[03].x = x + d / 2;
				c[count].f[0].p[03].y = y + d / 2;
				c[count].f[0].p[03].z = z - d / 2;
				//////////////////////////////////////////////////////////////////////////////////////////////
				c[count].f[01].p[0].x = x - d / 2;
				c[count].f[01].p[0].y = y + d / 2;
				c[count].f[01].p[0].z = z + d / 2;

				c[count].f[01].p[1].x = x - d / 2;
				c[count].f[01].p[01].y = y - d / 2;
				c[count].f[01].p[01].z = z + d / 2;

				c[count].f[01].p[02].x = x + d / 2;
				c[count].f[01].p[02].y = y - d / 2;
				c[count].f[01].p[02].z = z + d / 2;

				c[count].f[01].p[03].x = x + d / 2;
				c[count].f[01].p[03].y = y + d / 2;
				c[count].f[01].p[03].z = z + d / 2;
				////////////////////////////////////////////////////////////////////////////////////////////////////
				c[count].f[02].p[0].x = x + d / 2;
				c[count].f[02].p[0].y = y + d / 2;
				c[count].f[02].p[0].z = z - d / 2;

				c[count].f[02].p[1].x = x + d / 2;
				c[count].f[02].p[01].y = y - d / 2;
				c[count].f[02].p[01].z = z - d / 2;

				c[count].f[02].p[02].x = x + d / 2;
				c[count].f[02].p[02].y = y - d / 2;
				c[count].f[02].p[02].z = z + d / 2;

				c[count].f[02].p[03].x = x + d / 2;
				c[count].f[02].p[03].y = y + d / 2;
				c[count].f[02].p[03].z = z + d / 2;

				///////////////////////////////////////////////////////////////////////////////////////////

				c[count].f[03].p[0].x = x - d / 2;
				c[count].f[03].p[0].y = y + d / 2;
				c[count].f[03].p[0].z = z - d / 2;

				c[count].f[03].p[1].x = x - d / 2;
				c[count].f[03].p[01].y = y - d / 2;
				c[count].f[03].p[01].z = z - d / 2;

				c[count].f[03].p[02].x = x - d / 2;
				c[count].f[03].p[02].y = y - d / 2;
				c[count].f[03].p[02].z = z + d / 2;

				c[count].f[03].p[03].x = x - d / 2;
				c[count].f[03].p[03].y = y + d / 2;
				c[count].f[03].p[03].z = z + d / 2;
				//////////////////////////////////////////////////////////////////////////////////////
				c[count].f[04].p[0].x = x - d / 2;
				c[count].f[04].p[0].y = y - d / 2;
				c[count].f[04].p[0].z = z - d / 2;

				c[count].f[04].p[1].x = x - d / 2;
				c[count].f[04].p[01].y = y - d / 2;
				c[count].f[04].p[01].z = z + d / 2;

				c[count].f[04].p[02].x = x + d / 2;
				c[count].f[04].p[02].y = y - d / 2;
				c[count].f[04].p[02].z = z + d / 2;

				c[count].f[04].p[03].x = x + d / 2;
				c[count].f[04].p[03].y = y - d / 2;
				c[count].f[04].p[03].z = z - d / 2;
				/////////////////////////////////////////////////////////////////////////////////
				c[count].f[05].p[0].x = x - d / 2;
				c[count].f[05].p[0].y = y + d / 2;
				c[count].f[05].p[0].z = z - d / 2;

				c[count].f[05].p[1].x = x - d / 2;
				c[count].f[05].p[01].y = y + d / 2;
				c[count].f[05].p[01].z = z + d / 2;

				c[count].f[05].p[02].x = x + d / 2;
				c[count].f[05].p[02].y = y + d / 2;
				c[count].f[05].p[02].z = z + d / 2;

				c[count].f[05].p[03].x = x + d / 2;
				c[count].f[05].p[03].y = y + d / 2;
				c[count].f[05].p[03].z = z - d / 2;

				c[count].rotateX = 0;
				c[count].rotateY = 0;
				c[count].rotateZ = 0;

				count++;
			}
}

void rotateZf(int min, int max, int z)
{

	for (int i = 0; i < 27; i++)
	{

		if (c[i].z == z)
		{
			c[i].rotateZ += 10;

			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 4; l++)
				{

					float x = c[i].f[k].p[l].x;
					float y = c[i].f[k].p[l].y;
					float z = c[i].f[k].p[l].z;

					c[i].f[k].p[l].x = x * cos(10 * 3.146 / 180) - y * sin(10 * 3.146 / 180);
					c[i].f[k].p[l].y = y * cos(10 * 3.146 / 180) + x * sin(10 * 3.146 / 180);
				}
			}

			if (c[i].rotateZ % 90 == 0)
			{
				float x = c[i].x;
				float y = c[i].y;
				float z = c[i].z;

				c[i].x = x * cos(90 * 3.146 / 180) - y * sin(90 * 3.146 / 180);
				c[i].y = y * cos(90 * 3.146 / 180) + x * sin(90 * 3.146 / 180);
				c[i].x = round(c[i].x);
				c[i].y = round(c[i].y);
				if (c[i].x == -0.000f)
					c[i].x = 0.0f;
				if (c[i].y == -0.000f)
					c[i].y = 0.0f;
			}
		}
	}
	glutPostRedisplay();
}

void rotateYf(int min, int max, int y)
{
	int yy = 0;
	for (int i = 0; i < 27; i++)
	{
		if (c[i].y == y)
		{
			c[i].rotateY += 10;
			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 4; l++)
				{

					float x = c[i].f[k].p[l].x;
					float y = c[i].f[k].p[l].y;
					float z = c[i].f[k].p[l].z;

					c[i].f[k].p[l].x = x * cos(10 * 3.146 / 180) - z * sin(10 * 3.146 / 180);
					c[i].f[k].p[l].z = z * cos(10 * 3.146 / 180) + x * sin(10 * 3.146 / 180);
				}
			}

			if (c[i].rotateY % 90 == 0)
			{
				float x = c[i].x;
				float y = c[i].y;
				float z = c[i].z;

				c[i].x = x * cos(90 * 3.146 / 180) - z * sin(90 * 3.146 / 180);
				c[i].z = z * cos(90 * 3.146 / 180) + x * sin(90 * 3.146 / 180);
				c[i].x = round(c[i].x);
				c[i].z = round(c[i].z);
				if (c[i].x == -0.000f)
					c[i].x = 0.0f;
				if (c[i].z == -0.000f)
					c[i].z = 0.0f;
			}
		}
		glutPostRedisplay();
	}
}

void rotateXf(int min, int max, int x)
{

	for (int i = 0; i < 27; i++)
	{
		if (c[i].x == x)
		{
			c[i].rotateX += 10;
			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 4; l++)
				{

					float x = c[i].f[k].p[l].x;
					float y = c[i].f[k].p[l].y;
					float z = c[i].f[k].p[l].z;

					c[i].f[k].p[l].y = y * cos(10 * 3.146 / 180) - z * sin(10 * 3.146 / 180);
					c[i].f[k].p[l].z = z * cos(10 * 3.146 / 180) + y * sin(10 * 3.146 / 180);
				}
			}

			if (c[i].rotateX % 90 == 0)
			{
				float x = c[i].x;
				float y = c[i].y;
				float z = c[i].z;

				c[i].y = y * cos(90 * 3.146 / 180) - z * sin(90 * 3.146 / 180);
				c[i].z = z * cos(90 * 3.146 / 180) + y * sin(90 * 3.146 / 180);
				c[i].y = round(c[i].y);
				c[i].z = round(c[i].z);
				if (c[i].y == -0.000f)
					c[i].y = 0.0f;
				if (c[i].z == -0.000f)
					c[i].z = 0.0f;
			}
		}
	}
}
// Drawing the single cube
void drawcube(int i)
{
	glLineWidth(5);
	glPushMatrix();

	for (int j = 0; j < 6; j++)
	{
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP); //front face
		glVertex3f(c[i].f[j].p[0].x, c[i].f[j].p[0].y, c[i].f[j].p[0].z);
		glVertex3f(c[i].f[j].p[01].x, c[i].f[j].p[01].y, c[i].f[j].p[01].z);
		glVertex3f(c[i].f[j].p[02].x, c[i].f[j].p[02].y, c[i].f[j].p[02].z);
		glVertex3f(c[i].f[j].p[03].x, c[i].f[j].p[03].y, c[i].f[j].p[03].z);
		glEnd();

		glColor3fv(colors[j]); //Orange
		glBegin(GL_QUADS);	 //front face
		glVertex3f(c[i].f[j].p[0].x, c[i].f[j].p[0].y, c[i].f[j].p[0].z);
		glVertex3f(c[i].f[j].p[01].x, c[i].f[j].p[01].y, c[i].f[j].p[01].z);
		glVertex3f(c[i].f[j].p[02].x, c[i].f[j].p[02].y, c[i].f[j].p[02].z);
		glVertex3f(c[i].f[j].p[03].x, c[i].f[j].p[03].y, c[i].f[j].p[03].z);
		glEnd();
	}
	glPopMatrix();
}

void reshape_func(GLsizei w, GLsizei h)
{
	glOrtho(-3, 3, -3, 3, -3, 3);
} // reshape function

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0, 0, 0);
	glRotatef(rot_x, 1, 0, 0);
	glRotatef(rot_y, 0, 1, 0);
	glRotatef(rot_z, 0, 0, 1);

	for (int i = 0; i < 27; i++)
		drawcube(i);
	// flush opengl commands
	//glFlush();
	glutSwapBuffers();
}

void specialkey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case ESC:
		exit(0);
		break;

	case 'a':

		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0, 0, 0);
		rot_y = (rot_y - 20) % 360;
		glRotatef(rot_y, 0, 1, 0);
		glPopMatrix();
		break;

	case 'd':
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0, 0, 0);
		rot_y = (rot_y + 20) % 360;
		glRotatef(rot_y, 0, 1, 0);
		glPopMatrix();
		break;

	case 'w':
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0, 0, 0);
		rot_x = (rot_x - 20) % 360;
		glRotatef(rot_x, 1, 0, 0);
		glPopMatrix();
		break;

	case 's':
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0, 0, 0);
		rot_x = (rot_x + 20); //% 360;
		glRotatef(rot_x, 1, 0, 0);
		glPopMatrix();
		break;

	case 'f':
		rotateZf(18, 27, 1);
		break;

	case 'm':
		rotateZf(9, 18, 0);
		break;

	case 'b':
		rotateZf(0, 9, -1);
		break;

	case 't':
		rotateYf(6, 26, 1);
		break;

	case 'c':
		rotateYf(3, 23, 0);
		break;

	case 'v':
		rotateYf(0, 20, -1);
		break;

	case 'r':
		rotateXf(0, 24, -1);
		break;

	case 'l':
		rotateXf(2, 26, 1);

		break;

	case 'x':
		rotateXf(1, 25, 0);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void init_func(void)
{
	//glViewport(0, 0, GLUT_WINDOW_WIDTH, GLUT_WINDOW_HEIGHT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-3, 3, -3, 3, -3, 3);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	fillstruct();
} // init

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glHint(GL_POINT_SMOOTH_HINT, GL_FALSE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rubix 3D");
	glutReshapeFunc(reshape_func);
	glutDisplayFunc(display);
	glutKeyboardFunc(&specialkey);
	init_func();
	glutMainLoop();
	return 0;
} // main