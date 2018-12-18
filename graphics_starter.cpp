#include "graphics.h"
#include "Asteroid.h"
#include "Sentence.h"
#include "Player.h"
#include "PlayerInterface.h"
#include "string"
#include <unistd.h>
GLdouble width, height;
int wd;

void aseteroidDestroy();

/**
 * Intializing objects
 */
Asteroid asteroidOne;
Asteroid asteroidTwo;
Asteroid asteroidThree;
Asteroid targetedAsteroid;
Player p;
PlayerInterface PI;

/**
 * Asteroid Belt (or drawn asteroids)
 */
vector<Asteroid> asteroidBelt;
vector<AbstractSpaceObject> drawVec;


/**
 * This function is located here because of its middle
 * ground in relation to asteroids and players in the current
 * game state. Once the targeted asteroid is equal to the
 * users typed sentence it is destroyed and replaced.
 */
void asteroidDestroy(){

    //If what I type is equal to the targeted asteroids sentence
    if (p.getUserTyped() == targetedAsteroid.getSentence().getString()) {
        //then reset the sentence
        p.resetUserTyped();
        PI.resetUserTyped();

        //destory this asteroid, and generate a new one
        Sentence s; s.setString(s.generateString());
        for (int i = 0; i < asteroidBelt.size(); i++){
            //but only if its the targeted asteroid
            if (asteroidBelt[i].getTargeted() == true){
                asteroidBelt[i].setSentence(s);
                asteroidBelt[i].setPosition(Position(asteroidBelt[i].getPosition().getX(), 150)); //reset the height
            }
        }
        targetedAsteroid = PI.tabAsteroidTarget(asteroidBelt);
    }
}

void init() {
    /**
     * Initializing all objects positions
     * and board width/height, as well as
     * the asteroid vector
     */
    width = 1200;
    height = 1000;
    asteroidOne = Asteroid(Position(width/2 - 300, 150), 1);
    asteroidTwo = Asteroid(Position(width/2, 150), 2);
    asteroidThree = Asteroid(Position(width/2 + 300, 150), 3);
    p = Player(Position(width/2 - 300, height/2));


    /**
     * Belt
     */
    asteroidBelt.push_back(asteroidOne); asteroidBelt.push_back(asteroidTwo); asteroidBelt.push_back(asteroidThree);
    p.sizeOfBelt(asteroidBelt.size());
    asteroidBelt[0].setTargeted(true); targetedAsteroid = asteroidOne; PI.setTargetedAsteroid(targetedAsteroid);
    drawVec.push_back(asteroidOne); drawVec.push_back(asteroidTwo);
    drawVec.push_back(asteroidThree); drawVec.push_back(p);
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void gamePlayScreen() {

    /**
     * Drawling asteroid belt
     */
    for (int i = 0; i < asteroidBelt.size(); i++) {
        asteroidBelt[i].draw(); asteroidBelt[i].setIsDrawn(true);
        asteroidBelt[i].playerInteraction(p);
    }

    /**
     * Polymorphism, w/ draw functionality
     */
    for(int i = 0; i < drawVec.size(); i++){
        drawVec[i].draw();
    }

    /**
     * Draw what user types
     */
    PI.draw(width, height);
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    /*
     * Draw here
     */
    gamePlayScreen();


    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{

        PI.keyStrokeListener(key, wd);
        p.setUserTyped(PI.getUserTyped());

    /**
     * Tab Targeting
     */
    if(key == 9) {
            targetedAsteroid = PI.tabAsteroidTarget(asteroidBelt);
            p.resetUserTyped();
            PI.resetUserTyped();
        }

    asteroidDestroy();
    glFlush();
    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }
    
    glutPostRedisplay();
    
    return;
}

void cursor(int x, int y) {
    
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    
    
    glutPostRedisplay();
}

void timer(int extra) {
    for (int i = 0; i < asteroidBelt.size(); i++){
        asteroidBelt[i].move(0,1);
    }
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Typer 3.0" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();


    return 0;
}

