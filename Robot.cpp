#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <Math.h>


GLfloat  lightPos[] = { 1.0, 0.0, 1.0, 0.5 };
GLfloat  specular[] = { 1.0, 0.8, 0.4, 0.5};

int FRight=0;
int FLeft=0;

int DN_L_Left = 0;
int DN_L_Right = 0;

int ALeft = 0;
int ARight = 0;

int shoulder=0;

static int ball_bosition=1;
float x=0;

bool isSwingForward = false;
bool isLighting = false;


void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);




      glPushMatrix();
    glBegin(GL_QUADS);
    //Sky
    glColor3f(0.4,0.6,0.8);
    glVertex3i(-10,0,2);
    glVertex3i(10,0,2);
    glVertex3i(10,7,2);
    glVertex3i(-10,7,2);
    glEnd();
	  glPopMatrix();



   //grass
    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3f(0,0.9,0);
    glVertex3i(10,-3,2);
    glVertex3i(-10,-3,2);
    glVertex3i(-10,-5,2);
    glVertex3i(10,-5,2);
    glEnd();
	  glPopMatrix();


	  //===============ROAD===================
      glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex3i(10,-2,2);
    glVertex3i(-10,-2,2);
    glVertex3i(-10,-3,2);
    glVertex3i(10,-3,2);
    glEnd();
	  glPopMatrix();


	  //=================SUN====================
      glPushMatrix();
	glTranslatef (-5.0,3.5, 0.0);
	glColor3f(1,1,0);
	glPushMatrix();
    glutSolidSphere(0.7,20,20);
	glPopMatrix();
	  glPopMatrix();



	//================ROBOT==================

    glPushMatrix();
    glScaled(.4,.4,.4);
    glRotatef ((GLfloat) shoulder, 0.0, 1.0, 0.0);

    //face
    glPushMatrix();
	glTranslatef (0.0,3.0, 0.0);
	glColor3f(1,1,1);
	glPushMatrix();
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
	//end face

		//----------eyes--------------------

    //--right eye--
    glPushMatrix();
	glTranslatef (0.3, 3.4, 0);
	glColor3f(0.2,0.2,0.2);
	glPushMatrix();
	glScalef (0.2, 0.1, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();
    glPopMatrix();

    //--left eye--
    glPushMatrix();
	glTranslatef (-0.3, 3.4, 0);
	glColor3f(0.2,0.2,0.2);
	glPushMatrix();
	glScalef (0.2, 0.1, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();
    glPopMatrix();

    //-------------end eyes---------------------------


    //mouth
    glPushMatrix();
	glTranslatef (0, 2.8, 0.0);
	glColor3f(1,0.1,0.3);
	glPushMatrix();
	glScalef (0.4, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
   //end mouth




    //body
	  glPushMatrix();
	glTranslatef (0.0, 1.0,  0.0);
	glColor3f(1.0,0.7,0.1);
	glPushMatrix();
	glScalef (3.0,3, 1);
	glutSolidCube(1.0);
	glPopMatrix();
	  glPopMatrix();
   //end body



	//right arm
    glPushMatrix();
    glTranslatef (1.8 , 2.5 , 0.0);
    glRotatef ((GLfloat) ARight, 1.0, 0.0, 0.0);
    glTranslatef (0 , -1. , 0.0);
	glColor3f(1.0,0.0,0);
	glPushMatrix();
	glScalef (0.5,2.0,1);
	glutSolidCube(1.0);
	glPopMatrix();
    glPopMatrix();
    //end right arm



    //left arm
    glPushMatrix();
   	glTranslatef (-1.8 , 2.5 , 0.0);
	glRotatef ((GLfloat) ALeft, 1.0, 0.0, 0.0);
    glTranslatef (0 , -1. , 0.0);
    glTranslatef (0 , 0.01 , 0.0);
	glColor3f(1.0,0.0,0);
	glPushMatrix();
	glScalef (0.5,2.0,1);
	glutSolidCube(1.0);
	glPopMatrix();
    glPopMatrix();
    //end left arm




  	//------------------------------left leg-----------------------------------------
	glPushMatrix();

    glTranslatef (-1.0 , -1 , 0.0);
	glRotatef ((GLfloat) FLeft, 1.0, 0.0, 0.0);
    glTranslatef (0 , -0.5 , 0.0);
    //glTranslatef (1.0, -1.5,  0.0);
	glColor3f(0.0,0.7,0.1);
	glPushMatrix();
	glScalef (0.8,2.0,1);
	glutSolidCube(1.0);
	glPopMatrix();


    glPushMatrix();

    glTranslatef (0 , -1.5 , 0);
	glRotatef ((GLfloat) DN_L_Left, 1.0, 0.0, 0.0);
    glTranslatef (0 , -0.4 , 0.0);
	glColor3f(0.3,0.4,0.1);
	glPushMatrix();
	glScalef (0.6,2.0,1);
	glutSolidCube(1.0);
	glPopMatrix();




	    //left feet
	    glPushMatrix();
    glTranslatef (0, -1, 0);
	glColor3f(0.3,0.3,0.3);
	glPushMatrix();
	glScalef (0.6, 0.5, 1);
    glutSolidCube(1);
    glPopMatrix();
	     glPopMatrix();
       //end left feet

   glPopMatrix();

    glPopMatrix();
    //---------------------------------------end left leg-------------------------------------






  	//-------------------------------------------right leg--------------------------------------
	glPushMatrix();

    glTranslatef (1.0 , -1 , 0.0);
	glRotatef ((GLfloat) FRight, 1.0, 0.0, 0.0);
    glTranslatef (0 , -0.5 , 0.0);
	glColor3f(0.0,0.7,0.1);
	glPushMatrix();
	glScalef (0.8,2.0,1);
	glutSolidCube(1.0);
	glPopMatrix();


    glPushMatrix();

    glTranslatef (0 , -1.5 , 0);
	glRotatef ((GLfloat) DN_L_Right, 1.0, 0.0, 0.0);
    glTranslatef (0 , -0.4 , 0.0);

	glColor3f(0.3,0.4,0.1);
	glPushMatrix();
	glScalef (0.6,2.0,1);
	glutSolidCube(1.0);
	glPopMatrix();

	    //right feet
	    glPushMatrix();
    glTranslatef (0, -1, 0);
	glColor3f(0.3,0.3,0.3);
	glPushMatrix();
	glScalef (0.6, 0.5, 1);
    glutSolidCube(1);
    glPopMatrix();
	     glPopMatrix();

   glPopMatrix();

    glPopMatrix();
    //-----------------------------------------end right leg------------------------------------------


glPopMatrix();

//========================================== END ROBOT ==============================

      //==================BALL=========
      glPushMatrix();
	glTranslatef (0,-2, (GLfloat) ball_bosition);
	glColor3f(0.5,0.1,0.6);
	glPushMatrix();
    glutSolidSphere(0.4,20,20);
	glPopMatrix();
	  glPopMatrix();


	  //=======================CLOUDS========================

	  //Clouds 1


	 	    glPushMatrix();
    glTranslatef (4, 3, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

	 	    glPushMatrix();
    glTranslatef (4.4, 3, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

	 	    glPushMatrix();
    glTranslatef (4.8, 3, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

	     	    glPushMatrix();
    glTranslatef (4.8, 2.79, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

        glPushMatrix();
    glTranslatef (4.4, 2.79, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

        glPushMatrix();
    glTranslatef (4, 2.79, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();


    //---------Cloud 2 -------


	 	    glPushMatrix();
    glTranslatef (-1, 3, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

	 	    glPushMatrix();
    glTranslatef (-1.4, 3, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

	 	    glPushMatrix();
    glTranslatef (-1.8, 3, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

	     	    glPushMatrix();
    glTranslatef (-1.8, 2.79, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

        glPushMatrix();
    glTranslatef (-1.4, 2.79, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

        glPushMatrix();
    glTranslatef (-1, 2.79, 0);
	glColor3f(0.8,0.8,1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

//================================END CLOUDS =================================

	     //BIRD

        glPushMatrix();
    glTranslatef ((GLfloat) x,4, 0);
	glColor3f(0,0,0.1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.1,25,25);
    glPopMatrix();
	     glPopMatrix();



//=================================== HOUSES =========================================


	     //--------HOUSE1 ------------
glPushMatrix();

glBegin(GL_POLYGON);  //start house
	glColor3f(0.3, 0.2, 0.3);
	glVertex2i(-7, 1);
	glVertex2i(-9, 1);
	glVertex2i(-9, -2);
	glVertex2i(-7, -2);
	glEnd();

glPopMatrix();


	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.2, 0.0);
	glVertex2f(-8.2, -1);
	glVertex2f(-8.7, -1);
	glVertex2f(-8.7, -2);
	glVertex2f(-8.2, -2);
	glEnd();

//------------HOUSE 2------------------------
	glPushMatrix();

glBegin(GL_POLYGON);  //start house
	glColor3f(0.3, 0.2, 0.3);
	glVertex2i(-4, 1);
	glVertex2i(-6, 1);
	glVertex2i(-6, -2);
	glVertex2i(-4, -2);
	glEnd();

glPopMatrix();



	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.2, 0.0);
	glVertex2f(-5.2, -1);
	glVertex2f(-5.7, -1);
	glVertex2f(-5.7, -2);
	glVertex2f(-5.2, -2);
	glEnd();

//------------HOUSE 3------------------------

glPushMatrix();

glBegin(GL_POLYGON);  //start house
	glColor3f(0.3, 0.2, 0.3);
	glVertex2i(7, 1);
	glVertex2i(3, 1);
	glVertex2i(3, -2);
	glVertex2i(7, -2);
	glEnd();
glPopMatrix();

	glBegin(GL_POLYGON); //DOOR

	glColor3f(1, 0.2, 0.7);
	glVertex2f(6, -1);
	glVertex2f(4, -1);
	glVertex2f(4, -2);
	glVertex2f(6, -2);
	glEnd();


	glBegin(GL_POLYGON); //RIGHT-WINDOW

	glColor3f(1, 1, 0.5);
	glVertex2f(6.9, 0.8);
	glVertex2f(5.2, 0.8);
	glVertex2f(5.2, -0.1);
	glVertex2f(6.9, -0.1);
	glEnd();

	glBegin(GL_POLYGON); //LEFT-WINDOW

	glColor3f(1, 1, 0.5);
	glVertex2f(4.8, 0.8);
	glVertex2f(3.1, 0.8);
	glVertex2f(3.1, -0.1);
	glVertex2f(4.8, -0.1);
	glEnd();
//------------   END HOUSE 3------------------------



//========================================= END HOUOSES ==================================================


//=========================TREE 1==============================

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.325,0.208,0.039);
    glVertex2f(4, -3.8);
	glVertex2f(3.5, -3.8);
	glVertex2f(3.5, -4.8);
	glVertex2f(4,-4.8);
	glEnd();
    glPopMatrix();


        glPushMatrix();
    glTranslatef (4, -3.6, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();

        glPushMatrix();
    glTranslatef (3.5, -3.6, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();


        glPushMatrix();
    glTranslatef (3.5, -3, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();

	             glPushMatrix();
    glTranslatef (4, -3, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();



//==========================TREE 2==============================
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.325,0.208,0.039);
    glVertex2f(-4.5, -3.8);
	glVertex2f(-5, -3.8);
	glVertex2f(-5, -4.8);
	glVertex2f(-4.5,-4.8);
	glEnd();
    glPopMatrix();


        glPushMatrix();
    glTranslatef (-4.5, -3.6, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();

        glPushMatrix();
    glTranslatef (-5, -3.6, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();


        glPushMatrix();
    glTranslatef (-4.5, -3, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();


        glPushMatrix();
    glTranslatef (-5, -3, 0);
	glColor3f(0,0.8,0);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.3,25,25);
    glPopMatrix();
	     glPopMatrix();


//========================================= END TREES ===============================================

	     //============CAR======================

        glPushMatrix();
    glTranslatef ((GLfloat) x,-3.2, 0);
	glColor3f(0,0.4,0.1);
	glPushMatrix();
	glScalef (1.5,0.5,-1);
    glutSolidCube(1);
    glPopMatrix();
	     glPopMatrix();


        glPushMatrix();
    glTranslatef ((GLfloat) x-0.5,-3.7, 0);
	glColor3f(0,0,0.1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();


        glPushMatrix();
    glTranslatef ((GLfloat) x+0.5,-3.7, 0);
	glColor3f(0,0,0.1);
	glPushMatrix();
	glScalef (1.6,1,1);
    glutSolidSphere(0.2,25,25);
    glPopMatrix();
	     glPopMatrix();

	     //=====================END CAR===============================


glutSwapBuffers();


}

void moveBall(void){
        ball_bosition=(ball_bosition+0.05);
        glutPostRedisplay();
}


void reshape (int w, int h)
{

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -8.0);
}



void keyEvent(unsigned char key, int x, int y)
{
   switch (key) {
	  case 'c':
		 if(isLighting){
			 glDisable(GL_LIGHTING);
			 isLighting = false;
			 glutPostRedisplay();
		 }
		 else{
			 glEnable(GL_LIGHTING);
			 isLighting = true;
			 glutPostRedisplay();
		 }
         break;



     case 'r':
         ARight = (ARight + 5) % 360;
         glutPostRedisplay();
         break;



    case 'l':
         ALeft = (ALeft +5) % 360;
         glutPostRedisplay();
         break;

    case 'd':
         FLeft = (FLeft - 5) % 90;
         glutPostRedisplay();
         break;



    case 'e':
         FRight = (FRight - 5) % 90;
         glutPostRedisplay();
         break;


    case 'a':
         DN_L_Right = (DN_L_Right- 5) % 90;
         glutPostRedisplay();
         break;


    case 'q':
         DN_L_Left = (DN_L_Left- 5) % 90;
         glutPostRedisplay();
         break;


   case 'b':
            DN_L_Right = (DN_L_Right- 10) % 90;
            ball_bosition = (ball_bosition+ 1) % 5;
            glutPostRedisplay();
         break;


    case 'w':
         FRight = (FRight + 1) % 90;
         FLeft = (FLeft - 1) % 90;
         glutPostRedisplay();
         break;

    case 'z':
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;

    case 27:
         exit(0);
         break;


    default:
         break;
   }
}





void MenuFunc(int data)
{
	switch(data){
	case 1:

         FLeft = (FLeft - 5) % 90;
         glutPostRedisplay();
		break;
	case 2:
         FRight = (FRight - 5) % 90;
         glutPostRedisplay();
		break;

		default:
         	break;
	}
}

void move(void){
    x=x+0.01;
    if(x>10){
            x=-10;
    glutPostRedisplay();
    }
    if(x<-10){
        x=10;
        glutPostRedisplay();
        }
    glutPostRedisplay();
    }



void init(void)
{

    glClearColor (0.2, 0.1, 0.0, 0.0);
	//glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_SPECULAR,specular);
	glMateriali(GL_FRONT, GL_SHININESS,5);

	glutCreateMenu(MenuFunc);
	glutAddMenuEntry("move The Left leg",1);
	glutAddMenuEntry("move The Right leg",2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

}



int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 700);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("robot");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyEvent);
   glutIdleFunc(move);
   glutMainLoop();
   return 0;
}
