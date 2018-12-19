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

    /** Following texture code from:
    * arekkusu. (2007, April 3). Simple textures with GLUT? [Blog post]. Retrieved
    ** from iDevGames website: http://www.idevgames.com/forums/thread-3374.html
    */
    // hardcoded RGBA values

    //4-bit per component values (16 bits per pixel) for a few rgba colors
    #define TEX_INTERNAL GL_RGBA4
    #define TEX_FORMAT   GL_RGBA
    #define TEX_TYPE     GL_UNSIGNED_SHORT_4_4_4_4


    #define R 0xf30f
    #define W 0xffff
    #define X 0x0000
    #define G 0x5c6c
    #define B 0x111f


    unsigned short player_texture [(16 * 16)] = {
            //touches bottom screen
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,R,W,W,R,X,X,R,W,W,R,X,X,X,
            X,X,X,X,R,R,R,R,R,R,R,R,X,X,X,X,
            X,X,X,X,G,R,R,R,R,R,R,G,X,X,X,X,
            X,X,X,X,G,X,R,R,R,R,X,G,X,X,X,X,
            X,X,X,X,G,X,R,R,R,R,X,G,X,X,X,X,
            X,X,X,X,X,X,R,B,B,R,X,X,X,X,X,X,
            X,X,X,X,X,X,R,B,B,R,X,X,X,X,X,X,
            X,X,X,X,X,X,X,R,R,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,R,R,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,W,W,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,W,W,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,W,W,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,B,B,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,B,B,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,B,B,X,X,X,X,X,X,X,

            //points towards aseroids (gun point)
    };




    glTexImage2D(GL_TEXTURE_2D, 0, TEX_INTERNAL, 16, 16, 0, TEX_FORMAT, TEX_TYPE, player_texture);

//disabling mipmaps for this texture to be "complete"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

//drwaing a quad with the texture

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(getPosition().getX(), getPosition().getY());//glVertex2f(16,  16);
    glTexCoord2f(1, 0); glVertex2i(getPosition().getX() + 200, getPosition().getY());//glVertex2f(0, 16);
    glTexCoord2f(1, 1); glVertex2i(getPosition().getX() + 200, getPosition().getY() -100);//glVertex2f(0,0);
    glTexCoord2f(0, 1); glVertex2i(getPosition().getX(), getPosition().getY() -100);//glVertex2f(16, 0);

    glEnd();

    glDisable(GL_TEXTURE_2D);


    glEnd();


}
