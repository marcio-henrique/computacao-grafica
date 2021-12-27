#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6

int year = 0;

void init(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

void displaySpheres (void) {
    GLfloat position[] = { 0, 0, 0, 2};
    glLightfv (GL_LIGHT0, GL_POSITION, position);
    glPushMatrix();

    glDisable (GL_LIGHTING);
    glColor3f(AMARELO);
    glutSolidSphere(0.6, 16, 255);   /* desenha o sol */
    glEnable (GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
    glColor3f(VERMELHO);
    glRotatef ( 1.5 * year, 0.0, 1.0, 0.0);
    glTranslatef (2.45, 0.1, 2.0); //Translada a partir do novo sistema de coordenadas resultante da Rotacao
    glutSolidSphere(0.09, 16, 255);    /* desenha um planeta */
    glPopMatrix();

    /*Planeta com luas*/
    glPushMatrix();
    glColor3f(CINZA);
    glRotatef ((GLfloat) year, 0.0, 1.2, 0.0);
    glTranslatef(2.0, 0, 0);
    glPushMatrix();
    glutSolidSphere(0.2, 16, 255);
    glPopMatrix();

    //lua 1
    glPushMatrix();
    glColor3f(LARANJA);
    glRotatef (1.7 * year, 0.0, 1.1, 0.0);
    glTranslatef(0.3, 0, 0);
    glutSolidSphere(0.05, 16, 255);
    glPopMatrix();

    //lua 2
    glPushMatrix();
    glColor3f(CYAN);
    glRotatef (2.1 * year, 1.1, 1.1, 0.0);
    glTranslatef(0.3, 0, 0);
    glutSolidSphere(0.03, 16, 255);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(AZUL);
    glRotatef (0.2 * year, 0.0, 1.3, 0.0);
    glTranslatef(4.3, 0, 0);
    glutSolidSphere(0.3, 16, 255);
    glPopMatrix();

    glPushMatrix();
    glColor3f(VERDE);
    glRotatef (2 * year, 0.0, 1.4, 0.0);
    glTranslatef(1.2, 0, 0);
    glutSolidSphere(0.1, 16, 255);
    glPopMatrix();

    glPushMatrix();
    glColor3f(ROSEO);
    glRotatef (3 * year, 0.0, 1.5, 0.0);
    glTranslatef(2.8, 0, 0);
    glutSolidSphere(0.24, 16, 255);
    glPopMatrix();


}

void display(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glPushMatrix();
    glTranslatef (0.0, 0.0, -2.0);
    displaySpheres();
    glPopMatrix();

    glutSwapBuffers(); //pois estamos adotando o GLUT_DOUBLE
}

void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //posicao da camera
}

void keyboard (unsigned char key, int x, int y){
    switch (key) {
        case 'y':
            year = (year + 5);
            glutPostRedisplay();
            break;
        case 'Y':
            year = (year - 5);
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 255);
    glutCreateWindow ("Sistema Solar Iluminado");

    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}