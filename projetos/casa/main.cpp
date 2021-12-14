#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape (int w, int h);

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6

static GLfloat vertices[42]={
        0.0,  30.0, 30.0, /* 0 */
        30.0, 30.0, 30.0, /* 1 */
        30.0,  0.0, 30.0, /* 2 */
        0.0,   0.0, 30.0, /* 3 */
        0.0,  30.0,  0.0, /* 4 */
        30.0, 30.0,  0.0, /* 5 */
        30.0,  0.0,  0.0, /* 6 */
        0.0,   0.0,  0.0, /* 7 */
        15.0, 45.0, 15.0, /* 8 */
};

static GLubyte cuboFrenteIndices[]    = {0,3,2,1};
static GLubyte cuboTrasIndices[]      = {4,5,6,7};
static GLubyte cuboEsquerdaIndices[]  = {0,4,7,3};
static GLubyte cuboDireitaIndices[]   = {1,2,6,5};
static GLubyte cuboFundoIndices[]     = {2,3,7,6};

static GLubyte piramideFrenteIndices[] = {0,1,8};
static GLubyte piramideEsquerdaIndices[] = {4,0,8};
static GLubyte piramideDireitaIndices[] = {1,5,8};
static GLubyte piramideTrasIndices[] = {5,4,8};

static int eixoy, eixox;
int largura, altura;

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho (-50, 50, -50, 50, -50 , 50);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    largura=w;
    altura=h;
}

void drawHouse() {
    glColor3f (AZUL); /* frente */
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, cuboFrenteIndices);

    glColor3f (AMARELO); /* esquerda */
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, cuboEsquerdaIndices);

    glColor3f (VERMELHO); /* tras */
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, cuboTrasIndices);

    glColor3f (VERDE); /* direita */
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, cuboDireitaIndices);

    glColor3f (LARANJA); /* fundo */
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, cuboFundoIndices);

    glColor3f (CINZA); /* piramide frente */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, piramideFrenteIndices);

    glColor3f (ROSEO); /* piramide tras */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, piramideTrasIndices);

    glColor3f (CYAN); /* piramide esquerda */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, piramideEsquerdaIndices);

    glColor3f (LARANJA); /* piramide direita */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, piramideDireitaIndices);
}

void display(void){
    glPushMatrix();
    glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) eixox, 1.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    drawHouse();

    glDisableClientState (GL_VERTEX_ARRAY);

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'r':
            eixoy = (eixoy + 5) % 360;
            glutPostRedisplay();
            break;
        case 'R':
            eixox = (eixox + 5) % 360;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (256, 256);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Casa");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}