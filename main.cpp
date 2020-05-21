#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

static int slices = 50;
static int stacks = 50;
static int rr = 0;
static double xx=0;
static double yy=0;
//static double zz=0;
static double xxx=0;
static double yyy=0;
//static double zzz=0;
static double l=-10;
static bool flag=false;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    int a = t*90.0;
    rr=t-(int)t%60;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10);


    glPushMatrix();
        glTranslatef(0+xx,0+yy,0);
        glRotated(xxx+30,1,0,0);
        glRotated(yyy+20,0,1,0);
        //glRotated(30,1,0,0);
        //glRotated(20,0,1,0);
        //glRotated(90,1,0,0);
        //glRotated(-90,0,1,0);
        glScaled(0.5,0.5,0.5);

        glPushMatrix();
            glColor3d(1,1,1);
            glTranslated(0,0,0);
            glScaled(8,1.1,1.1);
            glutSolidSphere(1,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            glRotated(-15,0,1,0);
            //glColor3d(0.4, 0.686, 0.921);
            glTranslated(3,0,-1);
            glScaled(1,0.3,8);
            glutSolidCone(1,1,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            glRotated(15+180,0,1,0);
            //glColor3d(0.4, 0.686, 0.921);
            glTranslated(-3,0,-1);
            glScaled(1,0.3,8);
            glutSolidCone(1,1,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            glRotated(-18,0,1,0);
            //glColor3d(0.4, 0.686, 0.921);
            glTranslated(-6,0,2);
            glScaled(0.8,0.3,4);
            glutSolidCone(1,1,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            glRotated(18+180,0,1,0);
            //glColor3d(0.4, 0.686, 0.921);
            glTranslated(6,0,2);
            glScaled(0.8,0.3,4);
            glutSolidCone(1,1,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            //glRotated(18+180,0,1,0);
            glRotated(-90,1,0,0);
            glRotated(-20,0,1,0);
            //glColor3d(0.4, 0.686, 0.921);
            glTranslated(-6,0,2);
            glScaled(0.8,0.3,4);
            glutSolidCone(1,1,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            glColor3d(1,0,0);
            glTranslated(2.8,-0.5,3);
            glScaled(2,0.8,0.8);
            glutSolidSphere(0.5,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            glTranslated(3.8,-0.5,3);
            glRotated(a,1,0,0);

            glPushMatrix();
                glColor3d(0,0,0);
                //glTranslated(3.8,-0.5,3);
                glScaled(0.1,2,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glColor3d(0,0,0);
                //glTranslated(3.8,-0.5,3);
                glScaled(0.1,0.1,2);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glColor3d(1,0,0);
            glTranslated(2.8,-0.5,-3);
            glScaled(2,0.8,0.8);
            glutSolidSphere(0.5,slices,stacks);
        glPopMatrix();

        glPushMatrix();
            glTranslated(3.8,-0.5,-3);
            glRotated(a,1,0,0);

            glPushMatrix();
                glColor3d(0,0,0);
                //glTranslated(3.8,-0.5,3);
                glScaled(0.1,2,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glColor3d(0,0,0);
                //glTranslated(3.8,-0.5,3);
                glScaled(0.1,0.1,2);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();

     glPushMatrix();//stars
        glScaled(0.5,0.5,0.5);
          glPushMatrix();//star1
                glColor3d(0.6,0.6,0.6);
                glTranslated(-10,10,l);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();

            glPushMatrix();//star1
                glColor3d(0.6,0.6,0.6);
                glTranslated(-10,10,l);
                glRotated(55,0,0,1);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();

            glPushMatrix();//star2
                glColor3d(0.6,0.6,0.6);
                glTranslated(-15,15,l);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star2
                glColor3d(0.6,0.6,0.6);
                glTranslated(-15,15,l);
                glRotated(55,0,0,1);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();

            glPushMatrix();//star3
                glColor3d(0.6,0.6,0.6);
                glTranslated(5,-7,l);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star3
                glColor3d(0.6,0.6,0.6);
                glTranslated(5,-7,l);
                glRotated(55,0,0,1);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star4
                glColor3d(0.6,0.6,0.6);
                glTranslated(13,-9,l);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star4
                glColor3d(0.6,0.6,0.6);
                glTranslated(13,-9,l);
                glRotated(55,0,0,1);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star5
                glColor3d(0.6,0.6,0.6);
                glTranslated(9,7,l);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star5
                glColor3d(0.6,0.6,0.6);
                glTranslated(9,7,l);
                glRotated(55,0,0,1);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star6
                glColor3d(0.6,0.6,0.6);
                glTranslated(-6,-10,l);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star6
                glColor3d(0.6,0.6,0.6);
                glTranslated(-6,-10,l);
                glRotated(55,0,0,1);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star7
                glColor3d(0.6,0.6,0.6);
                glTranslated(-9,7,l);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();
            glPushMatrix();//star7
                glColor3d(0.6,0.6,0.6);
                glTranslated(-9,7,l);
                glRotated(55,0,0,1);
                glRotated(a,0,0,1);
                glutSolidSphere(0.5,3,stacks);
            glPopMatrix();

        glPopMatrix();


        if(flag)
        {
            glPushMatrix();
                glColor3d(0,1,0);
                glTranslated(6,-2,0);
                glutSolidSphere(0.5,slices,stacks);
            glPopMatrix();
        }

        glPushMatrix();//UFO
        glTranslated(-8,8,0);
        if(t-rr<25){
            if(t-rr<14)
                glTranslatef(t-rr,0,0);
            else if(t-rr>20){
                glTranslatef(t-rr-6,0,0);
                flag=true;
            }
            else{
                glTranslated(14,0,0);
                glPushMatrix();//light
                    glColor3d(1,1,0.3);
                    glRotated(-90,1,0,0);
                    glTranslated(0,0,-10.5);
                    glutSolidCone(2,10,slices,stacks);
                glPopMatrix();
            }
        }
        else{
            if(t-rr<14+30)
                glTranslatef(t-rr-30,0,0);
            else if(t-rr>20+30){
                glTranslatef(t-rr-6-30,0,0);
                flag=false;
            }
            else{
                glTranslated(14,0,0);
                glPushMatrix();//light
                    glColor3d(1,1,0.3);
                    glRotated(-90,1,0,0);
                    glTranslated(0,0,-10.5);
                    glutSolidCone(2,10,slices,stacks);
                glPopMatrix();
            }
        }
            glPushMatrix();
                glScaled(3,1,1);
                glColor3d(0,1,0);
                glTranslated(0,0,3);
                glutSolidSphere(0.5,slices,stacks);
            glPopMatrix();

            glPushMatrix();
                glScaled(1,1,1);
                glColor3d(0,1,0);
                glTranslated(0,0.5,3);
                glutSolidSphere(0.5,slices,stacks);
            glPopMatrix();

        glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;

        case 'w':
            yy+=0.1;
            break;

        case 's':
            yy-=0.1;
            break;

        case 'd':
            xx+=0.1;
            break;

        case 'a':
            xx-=0.1;
            break;

        case 'l':
            yyy+=5;
            break;

        case 'j':
            yyy-=5;
            break;

        case 'k':
            xxx+=5;
            break;

        case 'i':
            xxx-=5;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0.4, 0.686, 0.921,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
