
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

    float cx = 320.0f; // Center X
    float cy = 240.0f; // Center Y
    float r = 100.0f; // Radius
    int num_segments = 100; // More segments = Smoother circle

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of the Circle
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Current Angle
        float x = r * cosf(theta); // Coordinate X
        float y = r * sinf(theta); // Coordinate Y
        glVertex2f(x + cx, y + cy);
    }

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