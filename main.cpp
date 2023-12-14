#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>
#include <iostream>
// This code was written in MACOS operating system so it is possible that it can not work in Windows if you re using freeglut
// Change the inclue part and the windows.h accordingly to your operating system


float rabbitX = 50.0; // Initial position of the rabbit
float turtleX = 50.0; // Initial position of the turtle
bool rabbitWins = false;

void init()
{
    glClearColor(0.1, 0.8, 0.1, 1.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0, 640, 0, 480);
}



// Function to reset the positions of the rabbit and turtle
void resetGame()
{
    rabbitX = 50.0;
    turtleX = 50.0;
    rabbitWins = false;
}

void update(int value)
{
    // Update the positions of the rabbit and the turtle
    rabbitX += 1.0;
    turtleX += 0.5;

    // Check if the rabbit has passed the window
    if (rabbitX > 640 && !rabbitWins)
    {
        rabbitWins = true;
        std::cout << "Rabbit Wins!" << std::endl;
    }

    // Redraw the scene
    glutPostRedisplay();

    // Set up the next timer
    glutTimerFunc(16, update, 0); // 16 milliseconds (60 frames per second)
}

// Keyboard function to handle key presses
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r': // Press 'r' to restart the game
    case 'R':
        resetGame();
        break;
 
    }
    glutPostRedisplay();
}

void drawWinningMessage()
{
    if (rabbitWins)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(300, 240);
        std::string message = "Rabbit Wins!";
        for (char c : message)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
}

void drawRabbit()
{
    float x, y, t;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 210 + 40);
    glVertex2i(60, 210 + 40);
    glVertex2i(70, 220 + 40);
    glVertex2i(70, 230 + 40);
    glVertex2i(60, 240 + 40);
    glVertex2i(50, 240 + 40);
    glVertex2i(40, 230 + 40);
    glVertex2i(40, 220 + 40);
    glEnd();
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 78 + 9 * cos(t);
        y = 273 + 9 * sin(t);
        glVertex2f(70, 260);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2i(78, 273);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);

    // La queue
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 78 + 9 * cos(t);
        y = 273 + 9 * sin(t);
        glVertex2f(70, 260);
        glVertex2f(x, y);
    }
    glEnd();

    // Les yeux
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2i(78, 273);
    glEnd();

    // Le nez
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 74 + 4 * cos(t);
        y = 295 + 4 * sin(t);
        glVertex2f(70, 270);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawTortue()
{
    float x, y, t;
    int tortuepatte[] = {-2, 6, 22, 30};
    int i;

    // La tortue cercle
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 50 + 22 * cos(t);
        y = 180 + 22 * sin(t);
        glVertex2f(50, 180);
        glVertex2f(x, y);
    }
    glEnd();

    // La tortue la cercle desous
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(28, 180);
    glVertex2i(72, 180);
    glVertex2i(72, 158);
    glVertex2i(28, 158);
    glEnd();

    // Tortue les yeux
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++)
    {
        x = 82 + 7 * cos(t);
        y = 184 + 7 * sin(t);
        glVertex2f(72, 182);
        glVertex2f(x, y);
    }
    glEnd();

    // Tortue les jambes
    for (i = 0; i < 4; i++)
    {
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_POLYGON);
        glVertex2i(32 + tortuepatte[i], 170);
        glVertex2i(38 + tortuepatte[i], 170);
        glVertex2i(37 + tortuepatte[i], 180);
        glVertex2i(33 + tortuepatte[i], 180);
        glEnd();
    }
}

void drawRoad()
{
    glColor3f(1.0, 0.5, 0.0); // Orange pour la route
    glBegin(GL_QUADS);
    glVertex2i(0, 420);
    glVertex2i(640, 420);
    glVertex2i(640, 80);
    glVertex2i(0, 80);
    glEnd();
}

void drawLine()
{
    glBegin(GL_LINES);
    glVertex2f(100, 80);  // Le début
    glVertex2f(100, 420); // La fin de de la ligne
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the road
    drawRoad();

    // Draw the line
    glColor3f(1.0, 1.0, 1.0);
    drawLine();

    // Draw the rabbit at its updated position
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(rabbitX, 0.0, 0.0);
    drawRabbit();
    glPopMatrix();

    // Draw the turtle at its updated position
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(turtleX, 0.0, 0.0);
    drawTortue();
    glPopMatrix();

    // Draw the winning message
    drawWinningMessage();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutCreateWindow("Lapin et Tortue");
    glutPositionWindow(60, 75);
    init();

    // Set up the timer for animation
    glutTimerFunc(0, update, 0);

    // Set up the display function
    glutDisplayFunc(display);

    // Set up the keyboard function
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

