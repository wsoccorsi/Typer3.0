
#include "Debris.h"


Debris::Debris() {


}

Debris::Debris(Position p, std::string s) : AbstractSpaceObject(p) {
sentence = s;
}


std::string Debris::getSentence() const {
    return sentence;
}
void Debris::draw() {

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


    unsigned short debrisSmall[(16 * 16)] = {
            //touches bottom screen
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, G, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, D, G, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, G, X, X, X, X, X, X, X, G, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, G, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, G, X, X, X, X, X, X, X, X, X,
            X, X, X, X, G, G, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, D, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,


            //points to top
    };

    unsigned short debrisLarge[(16 * 16)] = {
            //touches bottom screen
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, G, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, D, G, X, X, X, X, X, G, G, X, X, X,
            X, X, X, X, G, X, X, X, X, X, X, G, G, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, G, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, D, D, X, X, X, G, X, X, X, X, X, X, X, X,
            X, X, D, G, X, X, G, G, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, G, D, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
            X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,


            //points to top
    };


    if (sentence.size() <= 4) {
        s = SMALL;
        setSize(1);
        glTexImage2D(GL_TEXTURE_2D, 0, TEX_INTERNAL, 16, 16, 0, TEX_FORMAT, TEX_TYPE, debrisSmall);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex2i(getPosition().getX() - 50, getPosition().getY() + 50);//glVertex2f(16,  16);
        glTexCoord2f(1, 0);
        glVertex2i(getPosition().getX() + 50, getPosition().getY() + 50);//glVertex2f(0, 16);
        glTexCoord2f(1, 1);
        glVertex2i(getPosition().getX() + 50, getPosition().getY() - 50);//glVertex2f(0,0);
        glTexCoord2f(0, 1);
        glVertex2i(getPosition().getX() - 50, getPosition().getY() - 50);//glVertex2f(16, 0);
    } else {
        s = LARGE;
        setSize(2);
        glTexImage2D(GL_TEXTURE_2D, 0, TEX_INTERNAL, 16, 16, 0, TEX_FORMAT, TEX_TYPE, debrisLarge);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex2i(getPosition().getX() - 75, getPosition().getY() + 75);//glVertex2f(16,  16);
        glTexCoord2f(1, 0);
        glVertex2i(getPosition().getX() + 75, getPosition().getY() + 75);//glVertex2f(0, 16);
        glTexCoord2f(1, 1);
        glVertex2i(getPosition().getX() + 75, getPosition().getY() - 75);//glVertex2f(0,0);
        glTexCoord2f(0, 1);
        glVertex2i(getPosition().getX() - 75, getPosition().getY() - 75);//glVertex2f(16, 0);

    }
    //disabling mipmaps for this texture to be "complete"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //drawing a quad with the texture



    glEnd();

    glDisable(GL_TEXTURE_2D);

}