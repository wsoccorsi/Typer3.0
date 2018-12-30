//
// Created by William  Soccorsi on 12/22/18.
//

#include "Button.h"
#include <iostream>

Button::Button() {

}

Button::Button(int w, int h) {
    width = w;
    height = h;
    fill = {1,1,1};
    message = "";
}

void Button::draw(){
    glColor3f(fill.red,fill.green,fill.blue);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(getPosition().getX(), getPosition().getY() + height);
    glTexCoord2f(1, 0); glVertex2i(getPosition().getX()  + width, getPosition().getY() + height);
    glTexCoord2f(1, 1); glVertex2i(getPosition().getX()  + width, getPosition().getY());
    glTexCoord2f(0, 1); glVertex2i(getPosition().getX(), getPosition().getY());

    glEnd();

    glColor3f(0,0,0);
    glRasterPos2i(getPosition().getX() + 130, getPosition().getY() + height/2  + 10);

    for (int i = 0; i < getMessage().size(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getMessage()[i]);
    }

    glEnd();
}

void Button::setColor(double r, double g, double b) {
    fill = {r,g,b};
}
Color Button::getColor(){
    return fill;
}

void Button::setMessage(string s){
    message = s;
}

string Button::getMessage() const {
    return message;
}

bool Button::isOverlapping(int x, int y){
    if (x > getPosition().getX() + width) {
        // this is to the right of r
        return false;
    }
    if (x < getPosition().getX()) {
        // r is to the right of this
        return false;
    }
    if (y > getPosition().getY() + height) {
        // this is under r
        return false;
    }
    if (y < getPosition().getY()) {
        // r is under this
        return false;
    }
    return true;
}