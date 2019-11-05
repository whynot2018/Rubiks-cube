//#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define ESC 27

float d = 1; //width of the cube
int rot_x = 0, rot_y = 0, rot_z = 0;
int dir = 1, x, y, z;
int animate = 1;

// Structure to store x,y,z of the vertex of the cube
struct point
{
	float x, y, z;
};

// Structure to store the coordinates of the face
struct face
{
	struct point p[4];
};

// Structure to store the coordinates of center of the cube,face and rotation
struct cube
{
	float x;
	float y;
	float z;
	struct face f[6];
	int rotateX, rotateY, rotateZ;
};
struct cube c[27];

//Storing the colors
const GLfloat colors[][3] =
	{
		{1.0, 0.5, 0}, //Orange
		{1.0, 0.0, 0}, //Red
		{0.0, 0.0, 1}, // Blue
		{0.0, 1.0, 0}, //Green
		{1.0, 1.0, 0}, //Yellow
		{1.0, 1.0, 1}, //White
};

// Fills the initial values all the structure
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

// Used to rotote the face in Z-direction
void rotateZf(int dir, int z)
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

					c[i].f[k].p[l].x = x * cos(10 * dir * 3.146 / 180) - y * sin(10 * dir * 3.146 / 180);
					c[i].f[k].p[l].y = y * cos(10 * dir * 3.146 / 180) + x * sin(10 * dir * 3.146 / 180);
				}
			}

			if (c[i].rotateZ % 90 == 0)
			{
				float x = c[i].x;
				float y = c[i].y;
				float z = c[i].z;

				c[i].x = x * cos(90 * dir * 3.146 / 180) - y * sin(90 * dir * 3.146 / 180);
				c[i].y = y * cos(90 * dir * 3.146 / 180) + x * sin(90 * dir * 3.146 / 180);
				c[i].x = round(c[i].x);
				c[i].y = round(c[i].y);
				if (c[i].x == -0.000f)
					c[i].x = 0.0f;
				if (c[i].y == -0.000f)
					c[i].y = 0.0f;

				animate = 0;
			}
		}
	}
	glutPostRedisplay();
}

// Used for the animation of the cubes
void timerZ(int value)
{
	if (animate)
	{
		rotateZf(dir, z);
		glutPostRedisplay();
		glutTimerFunc(80, timerZ, value);
	}
}

// Used to rotote the face in Y-direction
void rotateYf(int dir, int y)
{
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

					c[i].f[k].p[l].x = x * cos(10 * dir * 3.146 / 180) - z * sin(10 * dir * 3.146 / 180);
					c[i].f[k].p[l].z = z * cos(10 * dir * 3.146 / 180) + x * sin(10 * dir * 3.146 / 180);
				}
			}

			if (c[i].rotateY % 90 == 0)
			{
				float x = c[i].x;
				float y = c[i].y;
				float z = c[i].z;

				c[i].x = x * cos(90 * dir * 3.146 / 180) - z * sin(90 * dir * 3.146 / 180);
				c[i].z = z * cos(90 * dir * 3.146 / 180) + x * sin(90 * dir * 3.146 / 180);
				c[i].x = round(c[i].x);
				c[i].z = round(c[i].z);
				if (c[i].x == -0.000f)
					c[i].x = 0.0f;
				if (c[i].z == -0.000f)
					c[i].z = 0.0f;

				animate = 0;
			}
		}
	}
	glutPostRedisplay();
}

void timerY(int value)
{
	if (animate)
	{
		rotateYf(dir, y);
		z = INT8_MIN;
		x = INT8_MIN;
		glutPostRedisplay();
		glutTimerFunc(80, timerY, value);
	}
}

// Rotate the face in X - direction
void rotateXf(int dir, int x)
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

					c[i].f[k].p[l].y = y * cos(10 * dir * 3.146 / 180) - z * sin(10 * dir * 3.146 / 180);
					c[i].f[k].p[l].z = z * cos(10 * dir * 3.146 / 180) + y * sin(10 * dir * 3.146 / 180);
				}
			}

			if (c[i].rotateX % 90 == 0)
			{
				float x = c[i].x;
				float y = c[i].y;
				float z = c[i].z;

				c[i].y = y * cos(90 * dir * 3.146 / 180) - z * sin(90 * dir * 3.146 / 180);
				c[i].z = z * cos(90 * dir * 3.146 / 180) + y * sin(90 * dir * 3.146 / 180);
				c[i].y = round(c[i].y);
				c[i].z = round(c[i].z);
				if (c[i].y == -0.000f)
					c[i].y = 0.0f;
				if (c[i].z == -0.000f)
					c[i].z = 0.0f;

				animate = 0;
			}
		}
	}
	glutPostRedisplay();
}

void timerX(int value)
{
	if (animate)
	{
		rotateXf(dir, x);
		glutPostRedisplay();
		glutTimerFunc(80, timerX, value);
	}
}

// Used to draw each cube
void drawcube(int i)
{
	glLineWidth(5);
	glPushMatrix();

	glRotatef(20, 1, 0, 0);
	glRotatef(30, 0, 1, 0);

	for (int j = 0; j < 6; j++)
	{
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP); //Drawing borders for the cube
		glVertex3f(c[i].f[j].p[00].x, c[i].f[j].p[00].y, c[i].f[j].p[00].z);
		glVertex3f(c[i].f[j].p[01].x, c[i].f[j].p[01].y, c[i].f[j].p[01].z);
		glVertex3f(c[i].f[j].p[02].x, c[i].f[j].p[02].y, c[i].f[j].p[02].z);
		glVertex3f(c[i].f[j].p[03].x, c[i].f[j].p[03].y, c[i].f[j].p[03].z);
		glEnd();

		glColor3fv(colors[j]);
		glBegin(GL_QUADS); //Drawing the cube
		glVertex3f(c[i].f[j].p[00].x, c[i].f[j].p[00].y, c[i].f[j].p[00].z);
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

	glRotatef(rot_x, 1, 0, 0);
	glRotatef(rot_y, 0, 1, 0);
	glRotatef(rot_z, 0, 0, 1);

	for (int i = 0; i < 27; i++)
		drawcube(i);

	glutSwapBuffers();
}

// Used for handling keyboard values
void specialkey(unsigned char key, int x1, int y1)
{
	animate = 1;
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
		rot_x = (rot_x + 20);
		glRotatef(rot_x, 1, 0, 0);
		glPopMatrix();
		break;

	case 'f':
		rotateZf(1, 1);
		dir = 1;
		z = 1;
		glutTimerFunc(0, timerZ, 0);
		break;
	case 'F':
		rotateZf(-1, 1);
		dir = -1;
		z = 1;
		glutTimerFunc(0, timerZ, 0);
		break;

	case 'm':
		rotateZf(1, 0);
		dir = 1;
		z = 0;
		glutTimerFunc(0, timerZ, 0);
		break;
	case 'M':
		rotateZf(-1, 0);
		dir = -1;
		z = 0;
		glutTimerFunc(0, timerZ, 0);
		break;

	case 'b':
		rotateZf(1, -1);
		dir = 1;
		z = -1;
		glutTimerFunc(0, timerZ, 0);
		break;
	case 'B':
		rotateZf(-1, -1);
		dir = -1;
		z = -1;
		glutTimerFunc(0, timerZ, 0);
		break;

	case 't':
		rotateYf(1, 1);
		dir = 1;
		y = 1;
		glutTimerFunc(0, timerY, 0);
		break;
	case 'T':
		rotateYf(-1, 1);
		dir = -1;
		y = 1;
		glutTimerFunc(0, timerY, 0);
		break;

	case 'c':
		rotateYf(1, 0);
		dir = 1;
		y = 0;
		glutTimerFunc(0, timerY, 0);
		break;
	case 'C':
		rotateYf(-1, 0);
		dir = -1;
		y = 0;
		glutTimerFunc(0, timerY, 0);
		break;

	case 'v':
		rotateYf(1, -1);
		dir = 1;
		y = -1;
		glutTimerFunc(0, timerY, 0);
		break;
	case 'V':
		rotateYf(-1, -1);
		dir = -1;
		y = -1;
		glutTimerFunc(0, timerY, 0);
		break;

	case 'r':
		rotateXf(1, -1);
		dir = 1;
		x = -1;
		glutTimerFunc(0, timerX, 0);
		break;
	case 'R':
		rotateXf(-1, -1);
		dir = -1;
		x = -1;
		glutTimerFunc(0, timerX, 0);
		break;

	case 'l':
		rotateXf(1, 1);
		dir = 1;
		x = 1;
		glutTimerFunc(0, timerX, 0);
		break;
	case 'L':
		rotateXf(-1, 1);
		dir = -1;
		x = 1;
		glutTimerFunc(0, timerX, 0);
		break;

	case 'x':
		rotateXf(1, 0);
		dir = 1;
		x = 0;
		glutTimerFunc(0, timerX, 0);
		break;
	case 'X':
		rotateXf(-1, 0);
		dir = -1;
		x = 0;
		glutTimerFunc(0, timerX, 0);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void init_func(void)
{
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
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rubix 3D");
	glutReshapeFunc(reshape_func);
	glutDisplayFunc(display);
	glutKeyboardFunc(&specialkey);
	init_func();
	glutMainLoop();
	return 0;
} // main