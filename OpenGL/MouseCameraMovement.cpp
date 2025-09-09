#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Στόχος κάμερας (παίκτης)
float targetX = 0.0f, targetY = 1.0f, targetZ = 0.0f;
float distanceFromTarget = 5.0f;

// Γωνίες κάμερας
float yaw = 3.14f;
float pitch = 0.3f;

float moveSpeed = 0.2f;
int lastMouseX = 0, lastMouseY = 0;
bool firstMouse = true;

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

    glutSetCursor(GLUT_CURSOR_NONE);  // Απόκρυψη κέρσορα
}

void drawGroundPlane() {
    glDisable(GL_LIGHTING);
    glColor3f(0.2f, 0.6f, 0.2f); // πράσινο χρώμα

    glBegin(GL_QUADS);
    glVertex3f(-50.0f, -0.8f, -50.0f);
    glVertex3f(50.0f, -0.8f, -50.0f);
    glVertex3f(50.0f, -0.8f, 50.0f);
    glVertex3f(-50.0f, -0.8f, 50.0f);
    glEnd();

    glEnable(GL_LIGHTING);
}

void drawScene() {
    drawGroundPlane();

    // Αντικείμενα
    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glColor3f(0.8f, 0.2f, 0.2f);
    glutSolidTeapot(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 0.0f);
    glColor3f(0.2f, 0.5f, 1.0f);
    glutSolidCube(1.5);
    glPopMatrix();

    // Παίκτης
    glPushMatrix();
    glTranslatef(targetX, targetY - 1.0f, targetZ);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(0.3, 16, 16);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Θέση κάμερας σε σχέση με παίκτη
    float camX = targetX + distanceFromTarget * cos(pitch) * sin(yaw);
    float camY = targetY + distanceFromTarget * sin(pitch);
    float camZ = targetZ + distanceFromTarget * cos(pitch) * cos(yaw);

    gluLookAt(
        camX, camY, camZ,
        targetX, targetY, targetZ,
        0.0f, 1.0f, 0.0f
    );

    drawScene();
    glutSwapBuffers();
}

void mouseMotion(int x, int y) {
    if (firstMouse) {
        lastMouseX = x;
        lastMouseY = y;
        firstMouse = false;
        return;
    }

    int dx = x - lastMouseX;
    int dy = y - lastMouseY;

    float sensitivity = 0.005f;
    yaw += dx * sensitivity;
    pitch -= dy * sensitivity;

    // Περιορισμός pitch
    if (pitch > 1.5f) pitch = 1.5f;
    if (pitch < -1.5f) pitch = -1.5f;

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    float forwardX = sin(yaw);
    float forwardZ = cos(yaw);
    float rightX = cos(yaw);
    float rightZ = -sin(yaw);

    switch (key) {
    case 'w': // Πίσω (αντιστροφή)
        targetX -= forwardX * moveSpeed;
        targetZ -= forwardZ * moveSpeed;
        break;
    case 's': // Μπροστά (αντιστροφή)
        targetX += forwardX * moveSpeed;
        targetZ += forwardZ * moveSpeed;
        break;
    case 'a':
        targetX -= rightX * moveSpeed;
        targetZ -= rightZ * moveSpeed;
        break;
    case 'd':
        targetX += rightX * moveSpeed;
        targetZ += rightZ * moveSpeed;
        break;
    case 27:
        exit(0);
    }

    glutPostRedisplay();
}

void passiveMouse(int x, int y) {
    mouseMotion(x, y);
    glutWarpPointer(320, 240);
    lastMouseX = 320;
    lastMouseY = 240;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Third-Person Shooter Camera + Ground");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(passiveMouse);

    glutMainLoop();
    return 0;
}
