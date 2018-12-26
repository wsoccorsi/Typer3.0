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
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,B,B,B,B,X,X,X,X,X,X,
            X,X,X,X,X,B,B,B,B,B,B,X,X,X,X,X,
            X,X,X,X,B,B,B,B,B,B,B,B,X,X,X,X,
            X,X,X,X,B,B,B,B,B,B,B,B,X,X,X,X,
            X,X,X,X,B,B,B,B,B,B,B,B,X,X,X,X,
            X,X,X,X,X,B,B,B,B,B,B,X,X,X,X,X,
            X,X,X,X,X,X,B,B,B,B,X,X,X,X,X,X,
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
    glTexCoord2f(0, 0); glVertex2i(getPosition().getX() - 100, getPosition().getY()+100);//glVertex2f(16,  16);
    glTexCoord2f(1, 0); glVertex2i(getPosition().getX() + 150, getPosition().getY()+100);//glVertex2f(0, 16);
    glTexCoord2f(1, 1); glVertex2i(getPosition().getX() + 150, getPosition().getY() -150);//glVertex2f(0,0);
    glTexCoord2f(0, 1); glVertex2i(getPosition().getX() - 100, getPosition().getY() -150);//glVertex2f(16, 0);

    glEnd();

    glDisable(GL_TEXTURE_2D);


    glEnd();



    int line1 = 0;
    int line2 = 0;

    for(int i = 0; i < getSentence().getString().size(); ++i){
        if (getSentence().getString()[i] == ' ') {
            line1 = i;
            line2 = getSentence().getString().size();
            setSize(1);
            break;
        } else {
            line1 = getSentence().getString().size();
            setSize(2);
        }
    }

    if (getTargeted()) {
        glColor3f(1,1,0);
        glRasterPos2i(getPosition().getX(), getPosition().getY());

        for (int i = 0; i < line1; ++i) {

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
        for (int i = 0; i < line1; ++i) {
            if (userTyped[i] == getSentence().getString()[i] && getTargeted()
                //edge case for correct linear inputs
                && userTyped.substr(0,i) == getSentence().getString().substr(0,i)) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getSentence().getString()[i]);
            } else {

                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, getSentence().getString()[i]);
            }
        }
    }


    /**
     * Implementation of second line (probably not the best
     * way to do this)
     */
    if (getTargeted()) {
        glColor3f(1,1,0);
        glRasterPos2i(getPosition().getX() + 5, getPosition().getY() + 15);

        for (int i = line1; i < line2; ++i) {

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
        glRasterPos2i(getPosition().getX() + 5, getPosition().getY() + 15) ;
        for (int i = line1; i < line2; ++i) {
            if (userTyped[i] == getSentence().getString()[i] && getTargeted()
                //edge case for correct linear inputs
                && userTyped.substr(0,i) == getSentence().getString().substr(0,i)) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getSentence().getString()[i]);
            } else {

                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, getSentence().getString()[i]);
            }
        }
    }
    //setting the color back to default.
    glColor3f(1,1,1);

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





