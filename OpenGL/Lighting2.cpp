#include <GL/glut.h>
#include <iostream>

double posx = 0.0;
double posy = 0.0;
double posz = -10.0; // Cube's initial z position
double angle = 0.0; // Rotation angle

void pointlight() {
    // Ενεργοποίηση του φωτισμού και της πρώτης φωτεινής πηγής
    glEnable(GL_LIGHTING); // Ενεργοποιούμε το σύστημα φωτισμού
    glEnable(GL_LIGHT0); // Ενεργοποιούμε την πηγή φωτός 0 (σημειακή πηγή)

    // Θέση της σημειακής πηγής φωτός (position)
    GLfloat lightPos[] = { 2.0f, 5.0f, 2.0f, 1.0f }; // 1.0f για σημειακή πηγή (w = 1)
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // Διαχυτοί φωτισμοί (Diffuse)
    GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Λευκό φως
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);

    // Περιβαλλοντικός φωτισμός (Ambient)
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Απαλό φως
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);

    // Κατοπτρικός φωτισμός (Specular)
    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Λευκό φως
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    // Ρύθμιση μείωσης φωτεινότητας με την απόσταση (attenuation)
    GLfloat attenuation[] = { 1.0f, 0.1f, 0.01f }; // Διατήρηση του φωτός με την απόσταση
    glLightfv(GL_LIGHT0, GL_CONSTANT_ATTENUATION, &attenuation[0]);
    glLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, &attenuation[1]);
    glLightfv(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, &attenuation[2]);

}

void spotlight() {
    // Set the position of the second light (spotlight)
    GLfloat lightPos1[] = { 2.0f, 5.0f, 2.0f, 1.0f }; // Spotlight position
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    // Set the spotlight direction (pointing down)
    GLfloat spotDir1[] = { 0.0f, -1.0f, 0.0f }; // Spotlight direction
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir1);

    // Set the cutoff angle (narrow spotlight)
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0f);

    // Set the spotlight exponent (focused spotlight)
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0f);

    // Set the diffuse color for the second light (white)
    GLfloat diffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
}


void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);       // Enable depth testing to handle occlusion in 3D
    glMatrixMode(GL_PROJECTION);   // Set the projection matrix mode
    glLoadIdentity();

    // Set up a perspective projection
    gluPerspective(45.0, 640.0 / 480.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW); // Set the modelview matrix for object transformations

    glEnable(GL_LIGHTING); // Enable lighting
    glEnable(GL_LIGHT0); // Enable light #0

    // Set light position and color
    GLfloat lightPos[] = { -15.0f, 1.0f, 2.0f, 1.0f }; // Positional light
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glEnable(GL_COLOR_MATERIAL); // Allow glColor to set material
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    //GLfloat matAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Χαμηλή ambient ένταση
    //GLfloat matDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // Υψηλή diffuse ένταση
    //GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Ισχυρός specular φωτισμός για γυαλάδα
    //GLfloat matShininess[] = { 128.0f }; // Υψηλή γυαλάδα (shininess) για μετάλλινη εμφάνιση

    //// Ρύθμιση των παραμέτρων του υλικού
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShininess);
}

void keySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
        posy += 0.1;
        break;
        case GLUT_KEY_DOWN:
        posy -= 0.1;
        break;
        case GLUT_KEY_LEFT:
        posx -= 0.1;
        break;
        case GLUT_KEY_RIGHT:
        posx += 0.1;
        break;
    }
    glutPostRedisplay();
}

void drawCube() {
    glBegin(GL_QUADS);

    // Front face
    glNormal3f(0.0, 0.0, 1.0); // Normal facing viewer
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Back face
    glNormal3f(0.0, 0.0, -1.0);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // Top face
    glNormal3f(0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Bottom face
    glNormal3f(0.0, -1.0, 0.0);
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    // Right face
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Left face
    glNormal3f(-1.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear both color and depth buffers
    glLoadIdentity(); // Reset the current modelview matrix

    // Move the camera to look at the cube
    glTranslatef(posx, posy, posz); // Move the cube based on user input

    // Rotate the cube around its axis
    glRotatef(angle, 1.0, 1.0, 0.0); // Rotate around the x and y axes

    glColor3f(0.5, 0.5, 0.5);

    //drawCube(); // Draw the cube
    //glutSolidCube(2.0);
    glutSolidDodecahedron();

    glFlush();
    glutSwapBuffers(); // Swap the front and back buffers
}

// Our custom update function for animation
void update(int value) {
    angle += 1.5; // Increase the angle to rotate the cube
    if (angle > 360.0) angle -= 360.0; // Keep the angle within 0-360 range

    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(16, update, 0); // Call update every 16 ms (around 60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Use double buffering and depth buffer

    glutInitWindowSize(640, 480); // Set window size
    glutInitWindowPosition(100, 100); // Set window position

    glutCreateWindow("3D Cube Rotation"); // Create the window

    init(); // Initialize OpenGL

    glutDisplayFunc(display);
    glutSpecialFunc(keySpecial);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}