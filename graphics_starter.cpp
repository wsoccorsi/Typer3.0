#include "graphics.h"
#include "Asteroid.h"
#include "Sentence.h"
#include "Player.h"
#include "PlayerInterface.h"
#include "string"
#include "Shape.h"
#include "Button.h"
#include "Screen.h"
#include "Laser.h"
#include "Debris.h"
GLdouble width, height;
int wd;
enum screen {endo, game, starto}; screen selectedScreen;

/**
 * Intializing objects
 */
Asteroid asteroidOne;
Asteroid asteroidTwo;
Asteroid asteroidThree;
Asteroid targetedAsteroid;
Player p;
PlayerInterface PI;
vector<Circle> star(100);
vector<Circle> flames(100);
vector<Debris> debrisField(10); int debrisIndex = 0;
/**
 * Buttons
 */
Button buttonTest(400, 75);
Button retryButton(400, 75);

/**
 * Asteroid Belt (or drawn asteroids)
 */
vector<Asteroid> asteroidBelt;
vector<AbstractSpaceObject> drawVec;

void drawStars() {

    for (int i = 0; i < flames.size(); ++i) {
        flames[i].draw();
    }

    // draw the stars
    for (int i = 0; i < star.size(); ++i) {
        star[i].draw();
    }
}

void startScreen() {


    // draw the stars
    for (int i = 0; i < star.size(); ++i) {
        star[i].draw();
    }

    Screen startLogo(Position(width/2, height/2)); startLogo.draw();

    buttonTest.setPosition(Position(width/2 - 200, height/2 - 200));
    buttonTest.setMessage("Start New Game");
    buttonTest.draw();
    glRasterPos2i(width/2 - 100, height/2);
    glColor3f(1,1,1);


}

void gamePlayScreen() {

    if (selectedScreen == game) {
        drawStars();

        p.draw();

        /**
         * Drawling asteroid belt
         */
        for (int i = 0; i < asteroidBelt.size(); i++) {
            asteroidBelt[i].draw();
            asteroidBelt[i].setIsDrawn(true);
            asteroidBelt[i].playerInteraction(p);
        }

        /**
         * Drawling Debris Field
         */

        for (int i = 0; i < debrisField.size(); i++){
            if (debrisField[i].getIsDrawn() == true){
                debrisField[i].draw();
            }
        }


        /**
         * Draw what user types
         */
        PI.draw(width, height);
    }
}

void endScreen() {


    // draw the stars
    for (int i = 0; i < star.size(); ++i) {
        star[i].draw();
    }

    retryButton.setPosition(Position(width/2 - 200, height/2 - 200));
    retryButton.setMessage("Play Again");
    retryButton.draw();

    /**
     * Extremely strange bug, where the button somehow
     * deletes the first text written and only displays
     * those after. Therefore this text is never displayed
     */
    glRasterPos2i(width/2 - 100, height/2 + 150);
    glColor3f(1,1,1);
    string endScreen = "You DIED! Try Again?";
    for (int i = 0; i < endScreen.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, endScreen[i]);
    }

    /**
     * This text is displayed
     */
    glRasterPos2i(width/2 - 100, height/2);
    string score = "You Scored: ";
    score += to_string(p.getScore());
    for (int i = 0; i < score.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);
    }

}
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

        /**
         * work around for debris
         */
        debrisField[debrisIndex] = Debris(Position(targetedAsteroid.getPosition().getX(), targetedAsteroid.getPosition().getY() + 65), targetedAsteroid.getSentence().getString());
        debrisField[debrisIndex].setIsDrawn(true);
        debrisIndex++;
        if (debrisIndex >= 10){
            debrisIndex = 0;
        }

        //destory this asteroid, and generate a new one
        Sentence s; s.setString(s.generateString());
        for (int i = 0; i < asteroidBelt.size(); i++){
            //but only if its the targeted asteroid
            if (asteroidBelt[i].getTargeted() == true){
                p.setScore(p.getScore() + asteroidBelt[i].getSize() * 2); // setting the users score
                PI.getPlayerScore(p.getScore());
                asteroidBelt[i].setSentence(s);
                asteroidBelt[i].setPosition(Position(asteroidBelt[i].getPosition().getX(), -100)); //reset the height
            }

        }
        targetedAsteroid = PI.tabAsteroidTarget(asteroidBelt);
        p.setPosition(Position(targetedAsteroid.getPosition().getX() - 60, p.getPosition().getY()));

    }
}



void init() {
    selectedScreen = starto;
    /**
     * Initializing all objects positions
     * and board width/height, as well as
     * the asteroid vector
     */
    width = 1350;
    height = 850;
    asteroidOne = Asteroid(Position(width/2 - 300, 150), 1);
    asteroidTwo = Asteroid(Position(width/2, 150), 2);
    asteroidThree = Asteroid(Position(width/2 + 300, 150), 3);



    /**
     * Belt
     */
    asteroidBelt.push_back(asteroidOne); asteroidBelt.push_back(asteroidTwo); asteroidBelt.push_back(asteroidThree);
    p.sizeOfBelt(asteroidBelt.size());
    asteroidBelt[0].setTargeted(true); targetedAsteroid = asteroidOne; PI.setTargetedAsteroid(targetedAsteroid);
    p = Player(Position(targetedAsteroid.getPosition().getX() - 60, height/2 + 370));
    drawVec.push_back(asteroidOne); drawVec.push_back(asteroidTwo);
    drawVec.push_back(asteroidThree); drawVec.push_back(p);


    /**
     * Creating stars
     */
    for (int i = 0; i < star.size(); ++i) {
        star[i] = Circle(rand() % 3 + 1,
                         {1, 1, 1},
                         {rand() % (int) width, rand() % (int) height});
    }
    /**
     * Creating flames
     */
    for (int i = 0; i < flames.size(); ++i) {
        flames[i] = Circle(rand() % 7 + 4,
                           {1, 0, 0},
                           {rand() % (int) width, rand() % (int) height});
    }
    for (int i = 0; i < flames.size(); ++i) {
        int randX = rand()%(110-90 + 1) + 90;
        int randY = rand()%(25-20 + 1) + 20;
        flames[i].set_position(p.getPosition().getX() + randX, p.getPosition().getY() + randY);
    }
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
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

    switch(selectedScreen) {
        case starto:
            startScreen();
            break;
        case game:
            gamePlayScreen();
            break;
        case endo:
            endScreen();
            break;
    }

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
            p.setPosition(Position(targetedAsteroid.getPosition().getX() - 60, p.getPosition().getY()));
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

    if (buttonTest.isOverlapping(x,y)){
        buttonTest.setColor(.5,.1,.1);
        glutPostRedisplay();
    } else {
        buttonTest.setColor(1,1,1);
    }

    if (retryButton.isOverlapping(x,y)){
        retryButton.setColor(.5,.1,.1);
        /**
         * Resetting the whole game
         */
        for (int i = 0; i < asteroidBelt.size(); ++i){
        asteroidBelt[i].setPosition(Position(asteroidBelt[i].getPosition().getX(), 0));
        }




        glutPostRedisplay();
    } else {
        retryButton.setColor(1,1,1);
    }

    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && buttonTest.isOverlapping(x,y)){
       selectedScreen = game;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && retryButton.isOverlapping(x,y)){
        selectedScreen = game;
        p.setScore(0);
        PI.getPlayerScore(p.getScore());
    }
    glutPostRedisplay();
}

void timer(int extra) {
    if (selectedScreen == game) {
        for (int i = 0; i < asteroidBelt.size(); i++) {
            if (asteroidBelt[i].getSize() == 1) {
                asteroidBelt[i].move(0, 1);
            } else {
                asteroidBelt[i].move(0, 2);
            }

            glColor3f(1, 1, 1);

            if (asteroidBelt[i].getPosition().getY() - 100 > height) {
                selectedScreen = endo;
            }
        }
    }

    for (int i = 0; i < star.size(); ++i) {
        star[i].move(0, star[i].get_radius());
        if (star[i].get_y() > height) {
            star[i].set_position(rand() % (int) width, 0);
        }
    }

    for (int i = 0; i < flames.size(); ++i) {
        flames[i].move(0, flames[i].get_radius() / 2);
        // if the star went off the left side of the screen
        // move it to the right side at a random y location
        if (flames[i].get_y() > height -20) {
            int randX = rand()%(110-90 + 1) + 90;
            int randY = rand()%(25-20 + 1) + 20;

            flames[i].set_position(p.getPosition().getX() + randX, p.getPosition().getY() - randY);
        }
    }

    for (int i = 0; i < debrisField.size(); i++){
        if(debrisField[i].getIsDrawn() == true){
            debrisField[i].move(0,2);
            if (debrisField[i].getPosition().getY() > height){
                debrisField[i].setIsDrawn(false);
            }
        }
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

