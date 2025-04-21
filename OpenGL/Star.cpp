
#include <GL/glut.h>

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
    // Begins to draw a triangle
    // Finally draws three vertexes with 2 integers each defining coordinates (X,Y)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2i(350,300);
    glVertex2i(300,450);
    glVertex2i(250,300);
    glVertex2i(100,250);
    glVertex2i(250,200);
    glVertex2i(300,50);
    glVertex2i(350,200);
    glVertex2i(500,250);

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