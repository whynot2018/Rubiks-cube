#include <GL/glut.h>
#include <stdio.h>

#define ESC 27
#define ENTER 13

int main_menu = 1;
GLfloat black[] = {0, 0, 0};
float d = 1; //width of the cube
int rx = 0, ry = 0, rz = 0, color_value = 0;
void *names = GLUT_BITMAP_HELVETICA_18;
void *heading = GLUT_BITMAP_TIMES_ROMAN_24;
int w = GLUT_WINDOW_WIDTH, h = GLUT_WINDOW_HEIGHT;
int animate = 1, dir = 1, min = 0, max = 0;

// Structure to store the coordinates of the cube
struct cube
{
    float x, y, z;
    float nx, ny, nz;
    int rot_x, rot_y, rot_z;
    int now_x, now_y, now_z;
};

struct cube c[27];
void rotationZ(int, int, int);
void rotationY(int, int, int);
void updateZ(int, int, int);
float color[6][3] =
    {
        {1.0, 0.5, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0},
        {0.0, 1.0, 0.0},
        {1.0, 1.0, 0.0},
        {1.0, 1.0, 1.0},
};

//Used to fill the center of the cube in the structure format
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
                c[count].nx = x;
                c[count].ny = y;
                c[count].nz = z;
                c[count].rot_x = 0;
                c[count].rot_y = 0;
                c[count].rot_z = 0;
                c[count].now_x = 0;
                c[count].now_y = 0;
                c[count].now_z = 0;
                count++;
            }
}

void updateZ(int low, int high, int dir)
{
    printf("Inside updateZ\n");
    glPushMatrix();
    for (int i = low; i < high; i++)
    {
        
        c[i].rot_z += c[i].now_z;
        
        c[i].now_z += 90.0 * (-dir);
        glRotatef(c[i].now_z, 0, 0, 1);
        c[i].nz = 99; //random nos to identify rotated face
        
    }
    printf("%d, %d\n", c[low].now_z, c[low].rot_z);
    //printf("%f, %f\n", c[low].now_z, c[low].rot_z);
    glPopMatrix();
    glutPostRedisplay();
}

void updateY(int low, int high)
{

    int count = 1;
    printf("Inside updateY\n");
    glPushMatrix();
    for (int i = low; i < high;)
    {
        //  printf("y-before--->%d\t%d\t%d\t%d\n", i, c[i].rot_x, c[i].rot_y, c[i].rot_z);
        c[i].rot_y += c[i].now_y;
        c[i].now_y += 90 * (-dir);
        glRotatef(c[i].now_y, 0, -1, 0);

        c[i].ny = 99;
        if (count % 3 != 0)
            i++;
        else
            i += 7;
        count++;
    }
    glPopMatrix();
    glutPostRedisplay();
    //printf("--------------\n");
}

void timerz(int value)
{
    if (animate)
    {
        rotationZ(min, max, dir);
        glutPostRedisplay();
        glutTimerFunc(1000/60, timerz, 0);
    }
    else
    {
        updateZ(min, max, dir);
    }
}

void timery(int value)
{
    if (animate)
    {
        rotationY(min, max, dir);
        glutPostRedisplay();
        glutTimerFunc(25, timery, 0);
    }
    else
    {
        updateY(min, max);
    }
}

void rotationZ(int low, int high, int dir)
{
    int i;
    for (i = low; i < high; i++)
    {
        c[i].now_z += dir * 1.0;
        //glRotatef(c[i].rot_z, 0, 0, 1);
    }
    if ((c[high - 1].now_z % 90) == 0.0)
        animate = 0;
}

void rotationY(int low, int high, int dir)
{
    int i;
    int count = 1;
    for (i = low; i < high;)
    {
        // printf("y---->%d\t%f\t%f\t%f\t%d\n", i, c[i].x, c[i].y, c[i].z, c[i].rot_y);
        c[i].now_y += dir * 1.0;
        glRotatef(c[i].now_y, 0, 1, 0);
        if (count % 3 != 0)
            i++;
        else
            i += 7;
        count++;
    }
    // for (i = low; i < high;)
    // {
    //     // printf("y---->%d\t%f\t%f\t%f\t%d\n", i, c[i].x, c[i].y, c[i].z, c[i].rot_y);
    //     c[i].now_y += dir * 5.0;
    //    // glRotatef(c[i].now_y, 0, 1, 0);
    //     if (count % 3 != 0)
    //         i++;
    //     else
    //         i += 7;
    //     count++;
    // }
    if ((c[low].now_y % 90) == 0.0)
        animate = 0;
}

//Drawing the single cube
void drawcube(int i)
{
    glLineWidth(5);
    glPushMatrix();

    //glRotatef(20, 1, 0, 0);
    //glRotatef(30, 0, 1, 0);
   
 
    if (c[i].nx == 99 && animate == 0)
    {
        glTranslatef(c[i].x, c[i].y, c[i].z);
        glRotatef(c[i].rot_x, 1, 0, 0);
        glTranslatef(-c[i].x, -c[i].y, -c[i].z);
    }
    else
    {
        //glPushMatrix();
        glTranslatef(c[i].x, c[i].y, c[i].z);
        glRotatef(c[i].rot_x, 1, 0, 0);
        glTranslatef(-c[i].x, -c[i].y, -c[i].z);
        glRotatef(c[i].now_x, 1, 0, 0);
    }

      
    if (c[i].ny == 99 && animate == 0)
    {
        glTranslatef(c[i].x, c[i].y, c[i].z);
        glRotatef(c[i].rot_y, 0, 1, 0);
        glTranslatef(-c[i].x, -c[i].y, -c[i].z);
    }
    else
    {
        // glTranslatef(c[i].x, c[i].y, c[i].z);
        // glRotatef(c[i].rot_y, 0, 1, 0);
        // glTranslatef(-c[i].x, -c[i].y, -c[i].z);
        glRotatef(c[i].now_y, 0, 1, 0);
    }

     if (c[i].nz == 99 && animate == 0)
    {
        glTranslatef(c[i].x, c[i].y, c[i].z);
        glRotatef(c[i].rot_z, 0, 0, 1);
        glTranslatef(-c[i].x, -c[i].y, -c[i].z);
    }
    else
    {
        // glTranslatef(c[i].x, c[i].y, c[i].z);
        // glRotatef(c[i].rot_z, 0, 0, 1);
        // glTranslatef(-c[i].x, -c[i].y, -c[i].z);
        glRotatef(c[i].now_z, 0, 0, 1);
    }


    glColor3fv(black);
    glBegin(GL_LINE_LOOP); //front face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glEnd();
    glColor3fv(color[0]); //Orange
    glBegin(GL_QUADS);    //Front face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_LOOP); //back face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glEnd();
    glColor3fv(color[1]); //Red
    glBegin(GL_QUADS);    //back face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_LOOP); //left face
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glEnd();
    glColor3fv(color[2]); //Blue
    glBegin(GL_QUADS);    //left face
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_LOOP); //right face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glEnd();
    glColor3fv(color[3]); //Green
    glBegin(GL_QUADS);    //right face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_LOOP); //top face
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glEnd();
    glColor3fv(color[4]); // Yellow
    glBegin(GL_QUADS);    //top face
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_LOOP); //bottom face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glEnd();
    glColor3fv(color[5]); //White
    glBegin(GL_QUADS);    //bottom face
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
    glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
    glEnd();
    glPopMatrix();
}

void select_color(int color_value)
{
    ry = 0;
    rx = 0;
    if (color_value == 2) // green
    {
        ry = (ry + 90) % 360;
    }
    else if (color_value == 3) //yellow
    {
        rx = (rx - 90) % 360;
    }
    else if (color_value == 4) //blue
    {
        ry = (ry - 90) % 360;
    }
    else if (color_value == 5) //white
    {
        rx = (rx + 90) % 360;
    }
    else if (color_value == 6) //orange
    {
        ry = (ry - 180) % 360;
    }
}

// It tells which submenu is selected
void menu(int val)
{
    if (val != 0)
    {
        color_value = val;
        select_color(color_value);
    }
}

//Used to create menubar
void createmenu(void)
{
    glutCreateMenu(menu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Yellow", 3);
    glutAddMenuEntry("Blue", 4);
    glutAddMenuEntry("White", 5);
    glutAddMenuEntry("Orange", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshape_func(GLsizei w, GLsizei h)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glViewport(0, 0, w, h);
    glEnable(GL_DEPTH_TEST);
    float aspect = (float)w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    {
        glOrtho(-3, 3, -3 / aspect, 3 / aspect, -3, 3);
    }
    else
    {
        glOrtho(-3 * aspect, 3 * aspect, -3, 3, -3, 3);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    fillstruct();
    glutPostRedisplay();
} // reshape function

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rx, 1, 0, 0);
    glRotatef(ry, 0, 1, 0);
    glRotatef(rz, 0, 0, 1);

    for (int i = 0; i < 27; i++)
        drawcube(i);

    glFlush();
    glutSwapBuffers();
}

void keyboard_func(unsigned char key, int x, int y)
{
    float aspect = (float)w / h;
    animate = 1;
    switch (key)
    {
    case ESC:
        exit(0);
        break;

    case 'a':
        animate = 0;
        //glPushMatrix();
        //glLoadIdentity();
        ry = (ry - 30) % 360;
        //glPopMatrix();
        break;

    case 'd':
        animate = 0;
        //glPushMatrix();
        //glLoadIdentity();
        //glTranslatef(0, 0, 0);
        ry = (ry + 30) % 360;
        //glRotatef(ry, 0, 1, 0);
        //glPopMatrix();
        break;

    case 'w':
        animate = 0;
        //glPushMatrix();
        //glLoadIdentity();
        //glTranslatef(0, 0, 0);
        rx = (rx - 30) % 360;
        //glRotatef(rx, 1, 0, 0);
        //glPopMatrix();
        break;

    case 's':
         animate = 0;
        //glPushMatrix();
        //glLoadIdentity();
        //glTranslatef(0, 0, 0);
        rx = (rx + 30) % 360;
        //glRotatef(rx, 1, 0, 0);
        //glPopMatrix();
        break;

    case 'b':
        glPushMatrix();
        rotationZ(0, 9, -1);
        min = 0;
        max = 9;
        dir = -1;
        glutTimerFunc(0, timerz, 0);
        glPopMatrix();
        break;

    case 'B':
        glPushMatrix();
        rotationZ(0, 9, 1);
        min = 0;
        max = 9;
        dir = 1;
        glutTimerFunc(0, timerz, 0);
        glPopMatrix();
        break;

    case 'c':
        glPushMatrix();
        rotationZ(9, 18, -1);
        min = 9;
        max = 18;
        dir = -1;
        glutTimerFunc(0, timerz, 0);
        glPopMatrix();
        break;

    case 'C':
        // glPushMatrix();
        rotationZ(9, 18, 1);
        min = 9;
        max = 18;
        dir = 1;
        glutTimerFunc(0, timerz, 0);
        //  glPopMatrix();
        break;

    case 'f':
        rotationZ(18, 27, -1);
        min = 18;
        max = 27;
        dir = -1;
        glutTimerFunc(0, timerz, 0);
        break;

    case 'F':
        rotationZ(18, 27, 1);
        min = 18;
        max = 27;
        dir = 1;
        glutTimerFunc(0, timerz, 0);
        break;

    case 't':
        rotationY(6, 27, -1);
        min = 6;
        max = 27;
        dir = -1;
        glutTimerFunc(0, timery, 0);

        break;

    case 'T':
        rotationY(6, 27, 1);
        min = 6;
        max = 27;
        dir = 1;
        glutTimerFunc(0, timery, 0);
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void mouse_func(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glRotatef(ry, 0, 1, 0);
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rubix 3D");
    createmenu();
    glutDisplayFunc(display);

    glutKeyboardFunc(&keyboard_func);
    glutReshapeFunc(reshape_func);
    glutMouseFunc(&mouse_func);
    glutMainLoop();
    return 0;
}