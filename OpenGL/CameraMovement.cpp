#include <GL/glut.h>
#include <cmath>

// Camera parameters
float camX = 0.0f, camY = 1.0f, camZ = 5.0f;
float camYaw = 0.0f; // angle in radians
float camSpeed = 0.1f;

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat lightPos[] = { 0.0f, 5.0f, 5.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 640.0 / 480.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    }

void drawScene() {
    // Object 1: Teapot
    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glColor3f(0.8f, 0.2f, 0.2f);
    glutSolidTeapot(1.0);
    glPopMatrix();

    // Object 2: Cube
    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 0.0f);
    glColor3f(0.2f, 0.5f, 1.0f);
    glutSolidCube(1.5);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Compute look direction from yaw angle
    float dirX = sin(camYaw);
    float dirZ = -cos(camYaw);

    gluLookAt(
    camX, camY, camZ, // Eye position
    camX + dirX, camY, camZ + dirZ, // Look-at target
    0.0f, 1.0f, 0.0f // Up vector
    );

    drawScene();

    glutSwapBuffers();
}

// WASD key control
void keyboard(unsigned char key, int x, int y) {
    float dirX = sin(camYaw);
    float dirZ = -cos(camYaw);

    switch (key) {
        case 'w': // Forward
        camX += dirX * camSpeed;
        camZ += dirZ * camSpeed;
        break;
        case 's': // Backward
        camX -= dirX * camSpeed;
        camZ -= dirZ * camSpeed;
        break;
        case 'a': // Turn left
        camYaw -= 0.05f;
        break;
        case 'd': // Turn right
        camYaw += 0.05f;
        break;
        case 27: // ESC
        exit(0);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Camera Movement with gluLookAt");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display); // Enable continuous rendering
    glutKeyboardFunc(keyboard);

    glutMainLoop();
return 0;
}