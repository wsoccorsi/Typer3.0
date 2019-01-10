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

Color Asteroid::getFill() const {
    return fill;
}

void Asteroid::setFill(double r, double g, double b) {
    fill = {r,g,b};
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
#define B 0x111f
#define G 0xffd5
#define L 0xffd7
#define D 0xffd3


    unsigned short asteroidSmall[(16 * 16)] = {
            //touches bottom screen
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,D,D,X,X,X,X,X,
            X,X,X,D,D,D,D,D,D,G,G,D,D,D,X,X,
            X,X,D,D,G,G,G,G,G,G,G,G,G,G,D,X,
            X,D,D,G,G,D,G,G,G,G,G,G,G,G,G,D,
            D,G,G,G,D,L,G,G,G,D,D,G,G,G,G,D,
            D,G,G,D,L,G,G,G,G,G,D,L,G,G,G,D,
            D,G,G,G,G,G,G,G,G,G,L,G,D,D,D,X,
            D,G,G,G,G,G,G,G,D,G,G,D,X,X,X,X,
            D,G,D,G,G,G,G,G,G,G,G,D,X,X,X,X,
            D,G,G,D,D,D,G,G,G,D,D,X,X,X,X,X,
            X,D,D,D,X,X,D,D,D,D,X,X,X,X,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,


            //points to top
    };

    unsigned short asteroidLarge[(16 * 16)] = {
            //touches bottom screen
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
            X,X,X,X,D,D,D,D,D,D,X,X,X,X,X,X,
            X,X,X,D,G,G,G,G,G,G,D,D,D,X,X,X,
            X,X,D,G,G,G,G,G,G,G,G,G,D,X,X,X,
            X,D,G,G,G,G,G,G,G,L,G,G,G,D,X,X,
            D,G,G,L,G,G,G,G,D,D,L,G,G,D,X,X,
            D,G,G,D,L,G,G,G,G,D,G,G,G,G,D,X,
            X,D,G,D,L,G,G,G,G,G,G,G,G,G,G,D,
            X,D,G,G,G,G,G,G,G,G,G,G,L,G,G,D,
            D,D,G,G,G,G,G,G,D,D,D,G,D,G,G,D,
            X,D,D,G,G,G,G,D,X,X,D,G,G,G,D,X,
            X,X,D,D,D,D,D,D,X,X,X,D,D,D,X,X,
            X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,


            //points to top
    };




    if (getSentence().getString().size() <= 4) {
        s = SMALL;
        setSize(2);
        glTexImage2D(GL_TEXTURE_2D, 0, TEX_INTERNAL, 16, 16, 0, TEX_FORMAT, TEX_TYPE, asteroidSmall);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2i(getPosition().getX() - 50, getPosition().getY()+50);//glVertex2f(16,  16);
        glTexCoord2f(1, 0); glVertex2i(getPosition().getX() + 50, getPosition().getY()+50);//glVertex2f(0, 16);
        glTexCoord2f(1, 1); glVertex2i(getPosition().getX() + 50, getPosition().getY() -50);//glVertex2f(0,0);
        glTexCoord2f(0, 1); glVertex2i(getPosition().getX() - 50, getPosition().getY() -50);//glVertex2f(16, 0);
    } else {
        s = LARGE;
        setSize(1);
        glTexImage2D(GL_TEXTURE_2D, 0, TEX_INTERNAL, 16, 16, 0, TEX_FORMAT, TEX_TYPE, asteroidLarge);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2i(getPosition().getX() - 75, getPosition().getY()+75);//glVertex2f(16,  16);
        glTexCoord2f(1, 0); glVertex2i(getPosition().getX() + 75, getPosition().getY()+75);//glVertex2f(0, 16);
        glTexCoord2f(1, 1); glVertex2i(getPosition().getX() + 75, getPosition().getY() -75);//glVertex2f(0,0);
        glTexCoord2f(0, 1); glVertex2i(getPosition().getX() - 75, getPosition().getY() -75);//glVertex2f(16, 0);

    }
    //disabling mipmaps for this texture to be "complete"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //drawing a quad with the texture



    glEnd();

    glDisable(GL_TEXTURE_2D);





    /**
     * Line of each asteroid string
     */
    int line1 = 0;
    int line2 = 0;

    for(int i = 0; i < getSentence().getString().size(); ++i){
        if (getSentence().getString()[i] == ' ') {
            line1 = i;
            line2 = getSentence().getString().size();
            //setSize(1);
            break;
        } else {
            line1 = getSentence().getString().size();
            //setSize(2);
        }
    }

    if (getTargeted()) {
        fill = {1,1,0};
        glColor3f(fill.red,fill.green,fill.blue);
        if (s == SMALL) {
            glRasterPos2i(getPosition().getX() - 15, getPosition().getY() + 5);
        } else {
            glRasterPos2i(getPosition().getX() - 20, getPosition().getY() + 15);
        }

        for (int i = 0; i < line1; ++i) {
            if (userTyped[i] == getSentence().getString()[i] && getTargeted()
                //edge case for correct linear inputs
                && userTyped.substr(0,i) == getSentence().getString().substr(0,i))
              {
                  fill = {0,0,0};
                  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, getSentence().getString()[i]);
            } else {
                    fill = {1,1,1};
                  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, getSentence().getString()[i]);
            }

        }
    } else {
        if (s == SMALL) {
            glRasterPos2i(getPosition().getX() - 15, getPosition().getY() + 5);
        } else {
            glRasterPos2i(getPosition().getX() - 20, getPosition().getY() + 15);
        }
        fill = {1,1,1};
        glColor3f(fill.red,fill.green,fill.blue);
        for (int i = 0; i < line1; ++i) {
            if (userTyped[i] == getSentence().getString()[i] && getTargeted()
                //edge case for correct linear inputs
                && userTyped.substr(0,i) == getSentence().getString().substr(0,i)) {
                fill = {0,0,0};
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
        if (s == SMALL) {
            glRasterPos2i(getPosition().getX() - 15, getPosition().getY() + 5);
        } else {
            glRasterPos2i(getPosition().getX() - 20, getPosition().getY() + 15);
        }
        fill = {1,1,0};
        glColor3f(fill.red,fill.green,fill.blue);

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
        if (s == SMALL) {
            glRasterPos2i(getPosition().getX() - 15, getPosition().getY() + 5);
        } else {
            glRasterPos2i(getPosition().getX() - 20, getPosition().getY() + 15);
        }
        fill = {1,1,1};
        glColor3f(fill.red,fill.green,fill.blue);
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





