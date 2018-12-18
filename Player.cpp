//
// Created by William  Soccorsi on 12/17/18.
//

#include "Player.h"
#include "Asteroid.h"

Player::Player() {

}

Player::Player(Position p) : AbstractSpaceObject(p) {
    name = "";
    //setHealth(0);
    userTyped = "";
}

string Player::getName() const {
    return name;
}

void Player::setName(string n) {
    name = n;
}

string Player::getUserTyped() {
    return userTyped;
}

void Player::setUserTyped(string u) {
    userTyped = u;
}

int Player::asteroidSelected() {
    return selected;
}

int Player::sizeOfBelt(int size){
    beltSize = size;
}

int Player::getBeltSize() const {
    return beltSize;
}

void Player::setSelected(int s) {
    selected = s;
}

int Player::getSelected() const {
    return selected;
}

void Player::resetUserTyped() {
    for (int i = 0; i < userTyped.size(); i++){
        userTyped[i] = '\0';
    }
    userTyped.clear();
}

void Player::draw() {





}
