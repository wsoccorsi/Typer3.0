//
// Created by William  Soccorsi on 12/18/18.
//

#include "PlayerInterface.h"

PlayerInterface::PlayerInterface() {
    userTyped = "";

}



void PlayerInterface::draw(int width, int height) {

    //Creates the section box
    glColor3f(.5, .4, .4);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(300, height);
    glTexCoord2f(1, 0); glVertex2i(width - 300, height);
    glTexCoord2f(1, 1); glVertex2i(width - 200, height /2 + 375);
    glTexCoord2f(0, 1); glVertex2i(200, height /2 + 375);
    glEnd();

    //Creates the input box
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(width/2 - 100, height-100);
    glTexCoord2f(1, 0); glVertex2i(width/2 +100, height-100);
    glTexCoord2f(1, 1); glVertex2i(width/2 + 100, height /2 + 450);
    glTexCoord2f(0, 1); glVertex2i(width/2- 100, height /2 + 450);
    glEnd();

    glColor3f(0,0,0);
    glRasterPos2i(width/2 - 50, height-70);

    for (int i = 0; i < getUserTyped().size(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getUserTyped()[i]);
    }

}

string PlayerInterface::getUserTyped() const{
    return userTyped;
}

void PlayerInterface::setUserTyped(string u) {
    userTyped = u;
}

void PlayerInterface::resetUserTyped() {
    for (int i = 0; i < userTyped.size(); i++){
        userTyped[i] = '\0';
    }
    userTyped.clear();
}

/**
 * an exquiste tab targeting system.. wow
 * @param a
 */
Asteroid PlayerInterface::tabAsteroidTarget(vector<Asteroid> &a) {

        for (int i = 0; i < a.size(); ++i) {

            if (a[i].getTargeted()) {
                if (i != a.size() -1) {
                    a[i].setTargeted(false);
                    a[i + 1].setTargeted(true);
                    targetedAsteroid = a[i+1];
                    return a[i +1];
                } else {
                    a[i].setTargeted(false);
                    a[0].setTargeted(true);
                    targetedAsteroid = a[0];
                    return a[0];
                }
            }
        }
    }


void PlayerInterface::setTargetedAsteroid(Asteroid &a) {
    targetedAsteroid = a;
}

string PlayerInterface::keyStrokeListener(int key, int wd) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }


    switch (key) {


        case 127:

            userTyped = userTyped.substr(0, userTyped.size() - 1);

    }

    if (userTyped.size() <= targetedAsteroid.getSentence().getString().size()) {
        switch (key) {

            case 'a':
                //cout << "a" << endl;
                userTyped += 'a';

                break;

            case 'A':
                //cout << "A" << endl;
                userTyped += 'A';

                break;
            case 'b':
                //cout << "b" << endl;
                userTyped += 'b';

                break;
            case 'B':
                //cout << "B" << endl;
                userTyped += 'B';

                break;
            case 'c':
                //cout << "c" << endl;
                userTyped += 'c';

                break;
            case 'C':
                //cout << "C" << endl;
                userTyped += 'C';

                break;
            case 'd':
                //cout << "d" << endl;
                userTyped += 'd';

                break;
            case 'D':
                //cout << "D" << endl;
                userTyped += 'D';

                break;
            case 'e':
                //cout << "e" << endl;
                userTyped += 'e';

                break;
            case 'E':
                //cout << "E" << endl;
                userTyped += 'E';

                break;
            case 'f':
                //cout << "f" << endl;
                userTyped += 'f';

                break;
            case 'F':
                //cout << "F" << endl;
                userTyped += 'F';

                break;
            case 'g':
                //cout << "g" << endl;
                userTyped += 'g';

                break;
            case 'G':
                //cout << "G" << endl;
                userTyped += 'G';

                break;
            case 'h':
                //cout << "h" << endl;
                userTyped += 'h';

                break;
            case 'H':
                //cout << "H" << endl;
                userTyped += 'H';

                break;
            case 'i':
                //cout << "i" << endl;
                userTyped += 'i';


                break;
            case 'I':
                //cout << "I" << endl;
                userTyped += 'I';


                break;
            case 'j':
                //cout << "j" << endl;
                userTyped += 'j';

                break;
            case 'J':
                // cout << "J" << endl;
                userTyped += 'J';

                break;
            case 'k':
                //cout << "k" << endl;
                userTyped += 'k';

                break;
            case 'K':
                //cout << "K" << endl;
                userTyped += 'K';

                break;
            case 'l':
                //cout << "l" << endl;
                userTyped += 'l';

                break;
            case 'L':
                //cout << "L" << endl;
                userTyped += 'L';

                break;
            case 'm':
                //cout << "m" << endl;
                userTyped += 'm';

                break;
            case 'M':
                //cout << "M" << endl;
                userTyped += 'M';

                break;
            case 'n':
                //cout << "n" << endl;
                userTyped += 'n';

                break;
            case 'N':
                //cout << "N" << endl;
                userTyped += 'N';

                break;
            case 'o':
                //cout << "o" << endl;
                userTyped += 'o';

                break;
            case 'O':
                //cout << "O" << endl;
                userTyped += 'O';

                break;
            case 'p':
                //cout << "p" << endl;
                userTyped += 'p';

                break;
            case 'P':
                //cout << "P" << endl;
                userTyped += 'P';

                break;
            case 'q':
                //cout << "q" << endl;
                userTyped += 'q';

                break;
            case 'Q':
                //cout << "Q" << endl;
                userTyped += 'Q';

                break;
            case 'r':
                //cout << "r" << endl;
                userTyped += 'r';

                break;
            case 'R':
                //cout << "R" << endl;
                userTyped += 'R';

                break;
            case 's':
                //cout << "s" << endl;
                userTyped += 's';

                break;
            case 'S':
                //cout << "S" << endl;
                userTyped += 'S';

                break;
            case 't':
                //cout << "t" << endl;
                userTyped += 't';

                break;
            case 'T':
                //cout << "T" << endl;
                userTyped += 'T';

                break;
            case 'u':
                //cout << "u" << endl;
                userTyped += 'u';

                break;
            case 'U':
                //cout << "U" << endl;
                userTyped += 'U';

                break;
            case 'v':
                //cout << "v" << endl;
                userTyped += 'v';

                break;
            case 'V':
                //cout << "V" << endl;
                userTyped += 'V';

                break;
            case 'w':
                //cout << "w" << endl;
                userTyped += 'w';

                break;
            case 'W':
                //cout << "W" << endl;
                userTyped += 'W';

                break;
            case 'x':
                //cout << "x" << endl;
                userTyped += 'x';

                break;
            case 'X':
                //cout << "X" << endl;
                userTyped += 'X';

                break;
            case 'y':
                //cout << "y" << endl;
                userTyped += 'y';

                break;
            case 'Y':
                //cout << "Y" << endl;
                userTyped += 'Y';

                break;
            case 'z':
                //cout << "z" << endl;
                userTyped += 'z';

                break;
            case 'Z':
                //cout << "Z" << endl;
                userTyped += 'Z';

                break;

                //punctuation!
            case '.':
                userTyped += '.';

                break;
            case 39:
                userTyped += "'";

                break;
            case ',':
                userTyped += ",";

                break;
            case '!':
                userTyped += '!';

                break;
        }


    }
    return userTyped;

}