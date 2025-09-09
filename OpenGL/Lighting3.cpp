
#include <GL/glut.h>
#include <iostream>

// Object position and rotation
double posx = 0.0;
double posy = 0.0;
double posz = -10.0;
double angle = 0.0;

// Light position
float lightX = 2.0f;
float lightY = 5.0f;
float lightZ = 2.0f;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 640.0 / 480.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Initial light properties
    GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    // Attenuation
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01f);
}

// Arrow key handler to move the light source
void keySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
        lightY += 0.2f;
        break;
        case GLUT_KEY_DOWN:
        lightY -= 0.2f;
        break;
        case GLUT_KEY_LEFT:
        lightX -= 0.2f;
        break;
        case GLUT_KEY_RIGHT:
        lightX += 0.2f;
        case GLUT_KEY_PAGE_UP:
        lightZ += 0.2f;
        case GLUT_KEY_PAGE_DOWN:
        lightZ -= 0.2f; 
        break;
    }
    glutPostRedisplay();
}

// Draw a small sphere to indicate the light position
void drawLightMarker() {
    glPushMatrix();
    glTranslatef(lightX, lightY, lightZ);
    glDisable(GL_LIGHTING); // Disable lighting for the marker
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glutSolidSphere(0.1, 10, 10);
    glEnable(GL_LIGHTING); // Re-enable lighting
    glPopMatrix();
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(posx, posy, posz);

    // Set dynamic light position
    GLfloat lightPos[] = { lightX, lightY, lightZ, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // Draw the object
    glPushMatrix();
    glRotatef(angle, 1.0, 1.0, 0.0);
    glColor3f(0.5, 0.5, 0.5);
    glutSolidDodecahedron();
    glPopMatrix();

    // Draw light marker
    drawLightMarker();

    glFlush();
    glutSwapBuffers();
}

// Timer for animation
void update(int value) {
    angle += 1.5;
    if (angle > 360.0) angle -= 360.0;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Movable Light Source with Arrow Keys");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(keySpecial);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
