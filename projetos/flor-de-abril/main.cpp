#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#include <iostream>
using namespace std;


float speed_angle = M_PI / 4;
float angle = 10;

struct TRIANGUE {
    float r, g, b;
    float x[3], y[3];
};

TRIANGUE triangues[4] = {
        {1, 1, 1, 250, 230, 270, 250, 200, 200},
        {1, 0, 0, 250, 300, 300, 250, 230, 270},
        {0, 1, 0, 250, 230, 270, 250, 300, 300},
        {0, 0, 1, 250, 200, 200, 250, 270, 230},
};

void init (void)
{
    /* selecionar cor de fundo (preto) */
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode (GL_PROJECTION); //Projecao 2D

    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)
}

void displayStick() {
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)
    glColor3f (1.0, 1.0, .0);
    glBegin(GL_POLYGON);
    glVertex3f (249.0f, 250.0f, -1.0f);
    glVertex3f (251.0f, 250.0f, -1.0f);
    glVertex3f (249.0f, 100.0f, -1.0f);
    glVertex3f (251.0f, 100.0f, -1.0f);
    glEnd();
    glPopMatrix();
}

void displayTriangles(void) {
    for (auto & triangle : triangues) {
        glColor3f(triangle.r, triangle.g, triangle.b);
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 3; ++i) {
            glVertex2f(triangle.x[i], triangle.y[i]);
        }
        glEnd();
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    displayStick();
    displayTriangles();

    glFlush();
}

void spin(int direction) {
    glTranslatef(250, 250, 0);
    glRotatef(angle * speed_angle * direction, 0.0, 0.0, 1.0);
    glTranslatef(-250, -250, 0);
}
static void key(unsigned char key)
{
    switch (key)
    {
        case 'r':
            spin(1);
            break;
        case 'e':
            spin(-1);
            break;
        case 'f':
            speed_angle += (1.0f * M_PI/16);
            break;
        case 'd':
            speed_angle -= (1.0f * M_PI/16);
            if (speed_angle < 0) {
                speed_angle = 0.1;
            }
            break;
        case 27 :
        case 'q':
            exit(0);
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flor de Abril");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(reinterpret_cast<void (*)(unsigned char, int, int)>(key));

    glutMainLoop();

    return 0;
}