//
// Created by William  Soccorsi on 12/21/18.
//

#include "Screen.h"


Screen::Screen() : AbstractSpaceObject() {


}

Screen::Screen(Position p) : AbstractSpaceObject(p){

}

void Screen::draw() {

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

            W,W,W,X,W,X,W,X,W,W,X,W,W,W,X,X,
            X,W,X,X,X,W,X,X,W,W,X,W,W,X,X,X,
            X,W,X,X,X,W,X,X,W,X,X,W,X,X,X,X,
            X,W,X,X,X,W,X,X,W,X,X,W,W,W,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,


            //points towards aseroids (gun point)
    };




    glTexImage2D(GL_TEXTURE_2D, 0, TEX_INTERNAL, 16, 16, 0, TEX_FORMAT, TEX_TYPE, player_texture);

//disabling mipmaps for this texture to be "complete"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

//drwaing a quad with the texture

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(getPosition().getX() - 400, getPosition().getY()- 300);//glVertex2f(16,  16);
    glTexCoord2f(1, 0); glVertex2i(getPosition().getX(), getPosition().getY()- 300);//glVertex2f(0, 16);
    glTexCoord2f(1, 1); glVertex2i(getPosition().getX(), getPosition().getY() - 100);//glVertex2f(0,0);
    glTexCoord2f(0, 1); glVertex2i(getPosition().getX() - 400, getPosition().getY() - 100);//glVertex2f(16, 0);

    glEnd();
    glDisable(GL_TEXTURE_2D);

    unsigned short player_texture2 [(16 * 16)] = {
            //touches bottom screen

            W,W,W,X,X,W,W,W,X,X,X,X,W,W,W,X,
            W,X,W,X,X,X,X,X,W,X,X,W,X,X,X,W,
            W,W,W,X,X,X,X,W,X,X,X,W,X,X,X,W,
            W,X,X,W,X,X,W,X,X,X,X,W,X,X,X,W,
            X,X,X,X,X,X,X,W,X,X,X,W,X,X,X,W,
            X,X,X,X,X,X,X,X,W,X,X,W,X,X,X,W,
            X,X,X,X,X,W,W,W,X,X,X,X,W,W,W,X,
            X,X,X,X,X,X,X,X,X,W,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,


            //points towards aseroids (gun point)
    };




    glTexImage2D(GL_TEXTURE_2D, 0, TEX_INTERNAL, 16, 16, 0, TEX_FORMAT, TEX_TYPE, player_texture2);

//disabling mipmaps for this texture to be "complete"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

//drwaing a quad with the texture

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(getPosition().getX() + -20, getPosition().getY()- 300);//glVertex2f(16,  16);
    glTexCoord2f(1, 0); glVertex2i(getPosition().getX() + 380, getPosition().getY()- 300);//glVertex2f(0, 16);
    glTexCoord2f(1, 1); glVertex2i(getPosition().getX() + 380, getPosition().getY() - 100);//glVertex2f(0,0);
    glTexCoord2f(0, 1); glVertex2i(getPosition().getX() + -20, getPosition().getY() - 100);//glVertex2f(16, 0);

    glEnd();
    glDisable(GL_TEXTURE_2D);

}

