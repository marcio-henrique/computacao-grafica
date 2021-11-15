#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

struct QUAD {
    /*cores*/
    float red;
    float green;
    float blue;
    /*coordenadas*/
    float x0;
    float x1;
    float y0;
    float y1;
    /*controle da 'flutuação' do quadrado*/
    bool isFloating;
};

/*quadrado da posição atual*/
static int squareSelected = 0;

static QUAD quads[8] = {
    {1, 0, 0, -10, -8, -1, 1, false},
    {0, 1, 0, -7.5, -5.5, -1, 1, false},
    {0, 0, 1, -5, -3, -1, 1, false},
    {1, 1, 0, -2.5, -0.5, -1, 1, false},
    {1, 0, 1, 0, 2, -1, 1, false},
    {0.8, 0.6, 0.1, 2.5, 4.5, -1, 1, false},
    {0.7, 0.1, 0.6, 5, 7, -1, 1, false},
    {0.6, 0.6, 0.6, 7.5, 9.5, -1, 1, false}
};

static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 1, -1);
}

static void * display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(auto & quad : quads) {
        //se o quadrado está flutuando, a posição vertical dele é acrescida de 1
        float y0 = quad.isFloating ? quad.y0 + 1 : quad.y0;
        float y1 = quad.isFloating ? quad.y1 + 1 : quad.y1;

        glBegin(GL_QUADS);
        glColor3f(quad.red, quad.green, quad.blue);
        glVertex2f(quad.x0, y0);
        glVertex2f(quad.x1, y0);
        glVertex2f(quad.x1, y1);
        glVertex2f(quad.x0, y1);
        glEnd();
    }
    glutSwapBuffers();
}


static void key(unsigned char key)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        /*Caso a tecla 'd' seja pressionada, o quadrado atual
         * ficará flutuando e o anterior deixará de flutuar.
         * A posição do quadrado é atualizada*/
        case 'd':
            quads[squareSelected].isFloating = true;

            if (squareSelected == 0)
                quads[7].isFloating = false;
            else
                quads[squareSelected - 1].isFloating = false;

            squareSelected = (squareSelected + 1) % 8;
            break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);

    glutCreateWindow("Ola");

    glutReshapeFunc(resize);

    glutDisplayFunc(reinterpret_cast<void (*)(void)>(display));
    glutKeyboardFunc(reinterpret_cast<void (*)(unsigned char, int, int)>(key));
    glutIdleFunc(idle);

    glClearColor(0,0,0,0);

    glutMainLoop();

    return EXIT_SUCCESS;
}