//
// Created by William  Soccorsi on 12/17/18.
//

#include "Asteroid.h"
#include "graphics.h"
using namespace std;
#include <iostream>
#include <string>

Asteroid::Asteroid() {

}

Asteroid::Asteroid(Position p, int i) : AbstractSpaceObject(p) {

    //Create a sentence everytime an asteroid is made
    Sentence s; s.setString(s.generateString());
    sentence = s;
    pid = i;
}

void Asteroid::move(int x, int y) {
    AbstractSpaceObject::move(x,y);
}

void Asteroid::draw() {



    if (getTargeted()) {
        glColor3f(1,1,0);
        glRasterPos2i(getPosition().getX(), getPosition().getY());

        for (int i = 0; i < getSentence().getString().size(); ++i) {

            if (userTyped[i] == getSentence().getString()[i] && getTargeted()
                //edge case for correct linear inputs
                && userTyped.substr(0,i) == getSentence().getString().substr(0,i))
              {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getSentence().getString()[i]);
            } else {

                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, getSentence().getString()[i]);
            }
        }
    } else {
        glColor3f(1,1,1);
        glRasterPos2i(getPosition().getX(), getPosition().getY());
        for (int i = 0; i < getSentence().getString().size(); ++i) {
            if (userTyped[i] == getSentence().getString()[i] && getTargeted()
                //edge case for correct linear inputs
                && userTyped.substr(0,i) == getSentence().getString().substr(0,i)) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getSentence().getString()[i]);
            } else {

                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, getSentence().getString()[i]);
            }
        }
    }
}




Sentence Asteroid::getSentence() {

    return sentence;
}

void Asteroid::setSentence(Sentence s) {
    sentence = s;
}

void Asteroid::playerInteraction(Player &p) {
    userTyped = p.getUserTyped();

}

bool Asteroid::getTargeted() const {
    return targeted;
}

void Asteroid::setTargeted(bool b) {
    targeted = b;
}





