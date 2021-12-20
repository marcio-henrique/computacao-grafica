
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
}

void displaySpheres (void) {
    glPushMatrix();
    glColor3f(AMARELO);
    glutWireSphere(0.6, 16, 16);   /* desenha o sol */
    glPopMatrix();

    glPushMatrix();
    glColor3f(VERMELHO);
    glRotatef ( 1.5 * year, 0.0, 1.0, 0.0);
    glTranslatef (2.45, 0.1, 2.0); //Translada a partir do novo sistema de coordenadas resultante da Rotacao
    glutWireSphere(0.09, 16, 16);    /* desenha um planeta */
    glPopMatrix();

    /*Planeta com luas*/
    glPushMatrix();
    glColor3f(CINZA);
    glRotatef ((GLfloat) year, 0.0, 1.2, 0.0);
    glTranslatef(2.0, 0, 0);
    glPushMatrix();
    glutWireSphere(0.2, 16, 16);
    glPopMatrix();

    //lua 1
    glPushMatrix();
    glColor3f(LARANJA);
    glRotatef (1.7 * year, 0.0, 1.1, 0.0);
    glTranslatef(0.3, 0, 0);
    glutWireSphere(0.05, 16, 16);
    glPopMatrix();

    //lua 2
    glPushMatrix();
    glColor3f(CYAN);
    glRotatef (2.1 * year, 1.1, 1.1, 0.0);
    glTranslatef(0.3, 0, 0);
    glutWireSphere(0.03, 16, 16);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(AZUL);
    glRotatef (0.2 * year, 0.0, 1.3, 0.0);
    glTranslatef(3.45, 0, 0);
    glutWireSphere(0.3, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glColor3f(VERDE);
    glRotatef (2 * year, 0.0, 1.4, 0.0);
    glTranslatef(1.2, 0, 0);
    glutWireSphere(0.1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glColor3f(ROSEO);
    glRotatef (3 * year, 0.0, 1.5, 0.0);
    glTranslatef(3.1, 0, 0);
    glutWireSphere(0.24, 16, 16);
    glPopMatrix();


}

void display(void){
    glClear (GL_COLOR_BUFFER_BIT);

    displaySpheres();

    glutSwapBuffers(); //pois estamos adotando o GLUT_DOUBLE
}

void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
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
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Sistema Solar");

    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}