//
// Created by William  Soccorsi on 12/17/18.
//

#include "AbstractSpaceObject.h"

AbstractSpaceObject::AbstractSpaceObject() {

}


AbstractSpaceObject::AbstractSpaceObject(Position p) {
    setPosition(p);
}

void AbstractSpaceObject::draw(){
    //Nothing
}

int AbstractSpaceObject::getHealth() const{
    return health;
}

void AbstractSpaceObject::setHealth(int h){
    health = h;
}

Position AbstractSpaceObject::getPosition() const{
    return p;
}

void AbstractSpaceObject::setPosition(Position pos){
    p = pos;
}

void AbstractSpaceObject::move(int x, int y) {
    Position tempPos;
    tempPos.setX(getPosition().getX() + x);
    tempPos.setY(getPosition().getY() + y);
    setPosition(tempPos);
}

bool AbstractSpaceObject::getIsDrawn() const {
    return isDrawn;
}
void AbstractSpaceObject::setIsDrawn(bool b) {
    isDrawn = b;
}

