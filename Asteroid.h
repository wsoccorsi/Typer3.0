//
// Created by William  Soccorsi on 12/17/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_ASTEROID_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_ASTEROID_H

#include "AbstractSpaceObject.h"
#include "Position.h"
#include "Sentence.h"
#include "Player.h"


class Asteroid : public AbstractSpaceObject {


public:

    Asteroid();

    Asteroid(Position p, int i);

    virtual void move(int x, int y);

    virtual void draw() override;

    virtual void playerInteraction(Player &p);

    Sentence getSentence();

    void setSentence(Sentence s);

    bool getTargeted() const;

    void setTargeted(bool b);



protected:
    int x;
    int y;
    Sentence sentence;
    string userTyped;
    bool targeted = false;
    int pid;
};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_ASTEROID_H
