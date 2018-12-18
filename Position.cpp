//
// Created by William  Soccorsi on 12/17/18.
//

#include "Position.h"


Position::Position() {

}

Position::Position(int newx, int newy) {
    x = newx;
    y = newy;

}


int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int newx) {
    x = newx;
}

void Position::setY(int newy) {
    y = newy;
}
