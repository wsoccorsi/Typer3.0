//
// Created by William  Soccorsi on 12/17/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_PLAYER_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_PLAYER_H

#include <vector>
#include <iostream>
#include "graphics.h"
#include "AbstractSpaceObject.h"

using namespace std;
class Player : public AbstractSpaceObject{

public:

    Player();

    Player(Position p);

    string getName() const;

    void setName(string n);

    string keyStrokeListener(int key, int wd);

    string getUserTyped();

    void setUserTyped(string u);

    virtual void draw() override;

    int asteroidSelected();

    int sizeOfBelt(int size);

    void setSelected(int selected);

    int getSelected() const;

    int getBeltSize() const;

    void resetUserTyped();

    void setScore(int s);

    int getScore();

protected:

    string name;

    string userTyped = "";

    int selected = 0;

    int beltSize;

    int score;
};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_PLAYER_H
