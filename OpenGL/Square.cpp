
#include <GL/glut.h>
#include <cmath>

void init(void)
{
    // Background Colour
    glClearColor(1.0, 1.0, 1.0, 0.0);
    // Renders Display Mode in 2D
    glMatrixMode(GL_PROJECTION);
    // Loads Matrix
    glLoadIdentity();
    // Defines an Orthogone
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



void display()
{
    // Clears the Color Buffer and makes it into the glClearColor
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0);

    // Makes the shape that is going to be drawn red
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);

    glVertex2i(200, 200);
    glVertex2i(400, 200);
    glVertex2i(400, 400);
    glVertex2i(200, 400);

    glEnd();

    // Renders the Triangle
    glFlush();
}


int main(int argc, char** argv)
{
    // Initializing OpenGL Libraries
    glutInit(&argc, argv);

    // Creating the Panel
    glutInitWindowSize(640, 480);
    glutCreateWindow("Exercise");

    // Initializing Display Function
    init();
    glutDisplayFunc(display);

    // Basic Loop, keeps it running
    glutMainLoop();
    return 0;
}