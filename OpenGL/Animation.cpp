#include <GL/glut.h>
#include <random>

// For Movement
int x = 0;
int y = 0;
bool going_up = false;
bool going_right = false;

// For Colors
float current_r = 1.0f; // since the shape begins red
float current_g = 0.0f;
float current_b = 0.0f;

void keyboard(unsigned char key, int x, int y) {

    if (key == 'r' && current_r < 1.0) {
        current_r += 0.23;
    }

    if (key == 'g' && current_g < 1.0) {
        current_g += 0.23;
    }

    if (key == 'b' && current_b < 1.0) {
        current_b += 0.23;
    }

}

void keyboardSpecialCharacter(int key, int a, int b) {

    if (key == GLUT_KEY_RIGHT) {
        x += 5;
    }

    if (key == GLUT_KEY_LEFT) {
        x -= 5;
    }

    if (key == GLUT_KEY_UP) {
        y += 5;
    }

    if (key == GLUT_KEY_DOWN) {
        y -= 5;
    }

}

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
    glColor3f(current_r, current_g, current_b);
    glBegin(GL_POLYGON);

    glVertex2i(200+x, 200+y);
    glVertex2i(400+x, 200+y);
    glVertex2i(400+x, 400+y);
    glVertex2i(200+x, 400+y);

    glEnd();

    // Replaces glFlush in rendering shapes to prevent flickering
    glutPostRedisplay();
    glutSwapBuffers();
}

float randColor() {
    return  rand() / (RAND_MAX + 1.0f);
}

void update(int value) {

    // Check if it's going upwards or downwards
    if (going_up == false) {
        y--;
    } else {
        y++;
    }

    // Checks if it's going left or right
    if (going_right == false) {
        x--;
    } else {
        x++;
    }

    // Check Placements
    if (200+y == 0) {
        going_up = true;
        current_r = randColor();
        current_g = randColor();
        current_b = randColor();
    }

    if (400 + y == 480) {
        going_up = false;
        current_r = randColor();
        current_g = randColor();
        current_b = randColor();
    }

    if (200+x == 0) {
        going_right = true;
        current_r = randColor();
        current_g = randColor();
        current_b = randColor();
    }

    if (400+x == 640) {
        going_right = false;
        current_r = randColor();
        current_g = randColor();
        current_b = randColor();
    }

    // Reinitialize the Frames
    glutTimerFunc(5, update, 0);
}


int main(int argc, char** argv)
{
    srand(time(0));

    // Initializing OpenGL Libraries
    glutInit(&argc, argv);

    // Creating the Panel
    glutInitWindowSize(640, 480);
    glutCreateWindow("Exercise");

    // Implements Double Buffering to prevent Flickering
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Initializing Display Function
    init();
    glutDisplayFunc(display);

    // Initializing Keyboard
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecialCharacter);

    // Initializes Function that Renders Frames
    glutTimerFunc(0, update, 0);

    // Basic Loop, keeps it running
    glutMainLoop();
    return 0;
}