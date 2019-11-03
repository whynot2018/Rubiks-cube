//#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include<math.h>

#define ESC 27

GLfloat fAspect;
GLint angle, gap = 2; // Gap between each cube
float d = 1;		  //width of the cube
int rot_x = 0, rot_y = 0, rot_z = 0;
int whole=0;


// Structure to store the coordinates of the cube
struct cube
{
    //int id;
	float x, nx;
	float y, ny;
	float z, nz;
    int  rotateX, rotateY, rotateZ;
    

};
struct cube c[27];

const GLfloat colors[][3] =
	{
		{1.0, 0.5, 0},
		{1.0, 0.0, 0},
		{0.0, 0.0, 1},
		{0.0, 1.0, 0},
		{1.0, 1.0, 0},//yellow
		{1.0, 1.0, 1},
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
                c[count].rotateX=0;
                c[count].rotateY=0;
                c[count].rotateZ=0;
               // c[count].id = count;
				count++;


			}
}



void rotateZf(int min, int max){
        
        for(int i=min; i<max; i++){
           
                
        	c[i].rotateZ+=10;
			

			 if(c[i].rotateZ %90 ==0){
				float x= c[i].x;
				float y= c[i].y;
				float z= c[i].z;

				c[i].x = x*cos(c[i].rotateZ*3.146/180) + y*sin(c[i].rotateZ*3.146/180);
				c[i].y = y*cos(c[i].rotateZ*3.146/180) - x*sin(c[i].rotateZ*3.146/180);

				c[i].x = round(c[i].x);
				c[i].y = round(c[i].y);
				
				if(i==24)
					printf("front = 24=> %f, %f, %f, %f, %f, %f\n", x,y,z,c[24].x, c[24].y, c[24].z );
				
			 }	
					
        }
}

void rotateYf(int min, int max){

        for(int i=min; i<=max-2; i+=9){
            for(int j=i;j<i+3; j++){
                        c[j].rotateY+=10;
						if(c[j].rotateY %90 ==0){
								float x= c[j].x;
								float y= c[j].y;
								float z= c[j].z;

								c[j].x = x*cos(c[j].rotateY*3.146/180) + z*sin(c[j].rotateY*3.146/180);
								c[j].z = z*cos(c[j].rotateY*3.146/180) - x*sin(c[j].rotateY*3.146/180);

								c[j].x = round(c[j].x);
								c[j].z = round(c[j].z);
								if(j==24)
									printf("top = 24=> %f, %f, %f, %f, %f, %f\n", x,y,z,c[24].x, c[24].y, c[24].z );
								
							}	
            }
        }

		
}

void rotateXf(int min, int max){

        for(int i=min; i<=max; i+=3){
            
        	c[i].rotateX+=10;
                       
            if(c[i].rotateX %90 ==0){
				float x= c[i].x;
				float y= c[i].y;
				float z= c[i].z;

				c[i].y = y*cos(c[i].rotateX*3.146/180) + z*sin(c[i].rotateX*3.146/180);
				c[i].z = z*cos(c[i].rotateX*3.146/180) - y*sin(c[i].rotateX*3.146/180);

				c[i].z = round(c[i].z);
				c[i].y = round(c[i].y);
				
			
				
				}	
                                                     
        }
}



// Drawing the single cube
void drawcube(int i)
{
	glLineWidth(5);
	glPushMatrix();

	//glTranslatef(c[i].x, c[i].y, c[i].z);
    glRotatef(c[i].rotateX, 1, 0, 0);
    glRotatef(c[i].rotateY, 0, 1, 0);
    glRotatef(c[i].rotateZ, 0, 0, 1);
	//glTranslatef(-c[i].x, -c[i].y, -c[i].z);
	if(i==24 && c[i].rotateZ==90)
		printf("\n%f, %f, %f\n", c[i].x, c[i].y, c[i].z);

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP); //front face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glEnd();
	glColor3fv(colors[0]); //Orange
	glBegin(GL_QUADS);	 //front face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP); //back face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glEnd();
	glColor3fv(colors[1]); //Red
	glBegin(GL_QUADS);	 //back face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP); //left face
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glEnd();
	glColor3fv(colors[2]); //Blue
	glBegin(GL_QUADS);	 //left face
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP); //right face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glEnd();
	glColor3fv(colors[3]); //Green
	glBegin(GL_QUADS);	 //right face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP); //top face
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glEnd();
	glColor3fv(colors[4]); // Yellow
	glBegin(GL_QUADS);	 //top face
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y - d / 2, c[i].z - d / 2);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP); //bottom face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glEnd();
	glColor3fv(colors[5]); //White
	glBegin(GL_QUADS);	 //bottom face
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glVertex3f(c[i].x - d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z + d / 2);
	glVertex3f(c[i].x + d / 2, c[i].y + d / 2, c[i].z - d / 2);
	glEnd();

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

    glTranslatef(0,0,0);
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
            rotateZf(18,27); // 1 because rotation in z , so rotateF is 0,0,1 = 001= 1
            //glTranslatef(c[22].x, c[22].y, c[22].z );
            glutPostRedisplay();
            break;   

    case 'm':
            rotateZf(9,18);
            //glTranslatef(0,0,0);
            glutPostRedisplay();
            break;

    case 'b':
            rotateZf(0,9);
            //glTranslatef(c[4].x, c[4].y, c[4].z);
            glutPostRedisplay();
            break;


    case 't':
            rotateYf(6, 26);
            //glTranslatef(c[4].x, c[4].y, c[4].z);
            glutPostRedisplay();
            break;     
            
    case 'c':
            rotateYf(3, 23);
            //glTranslatef(c[4].x, c[4].y, c[4].z);
            glutPostRedisplay();
            break;     

    case 'v':
            rotateYf(0,20);
            //glTranslatef(c[4].x, c[4].y, c[4].z);
            glutPostRedisplay();
            break;


    case 'r':
            rotateXf(0, 24);
            //glTranslatef(c[4].x, c[4].y, c[4].z);
            glutPostRedisplay();
            break;     
            
    case 'l':
            rotateXf(2, 26);
            //glTranslatef(c[4].x, c[4].y, c[4].z);
            glutPostRedisplay();
            break;     

    case 'x':
            rotateXf(1, 25);
            //glTranslatef(c[4].x, c[4].y, c[4].z);
            glutPostRedisplay();
            break;             

	case 'g':
		glPushMatrix();

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