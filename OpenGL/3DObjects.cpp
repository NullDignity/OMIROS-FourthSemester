#include <GL/glut.h>
#include <iostream>

double posx = 0.0;
double posy = 0.0;
double posz = -5.0; // Cube's initial z position
double angle = 0.0; // Rotation angle

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);       // Enable depth testing to handle occlusion in 3D
    glMatrixMode(GL_PROJECTION);   // Set the projection matrix mode
    glLoadIdentity();
    
    // Set up a perspective projection
    gluPerspective(45.0, 640.0 / 480.0, 0.1, 100.0);
    
    glMatrixMode(GL_MODELVIEW); // Set the modelview matrix for object transformations
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
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glVertex3f( 1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Back face
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f( 1.0, 1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);

    // Top face
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f( 1.0, 1.0, 1.0);
    glVertex3f( 1.0, 1.0, -1.0);

    // Bottom face
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    // Right face
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, 1.0, -1.0);
    glVertex3f( 1.0, 1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);

    // Left face
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

    glColor3f(0.2, 0.5, 0.5);

    // drawCube(); // Draw the cube
    // or glutSolidSphere   
    //glutWireSphere(1.5, 20, 50);
    //glutWireCube(2);
    //glutWireCone(2, 2, 10, 10);
    //glutWireTorus(0.5, 1, 50, 50);
    //glutWireIcosahedron(); //d20!!!!
    glutSolidTeapot(1);

    glFlush();
    glutSwapBuffers(); // Swap the front and back buffers
    }

    // Our custom update function for animation
void update(int value) {
    angle += 0.5; // Increase the angle to rotate the cube
    if (angle > 360.0) angle -= 360.0; // Keep the angle within 0-360 range
    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(16, update, 0); // Call update every 16 ms (around 60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Use double buffering and depth buffer
    
    glutInitWindowSize(640, 480); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    
    glutCreateWindow("3D Rotation"); // Create the window

    init(); // Initialize OpenGL

    glutDisplayFunc(display);
    glutSpecialFunc(keySpecial);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}