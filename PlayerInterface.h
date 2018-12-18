//
// Created by William  Soccorsi on 12/18/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_PLAYERINTERFACE_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_PLAYERINTERFACE_H


#include "Player.h"
#include "Asteroid.h"
#include <vector>

class PlayerInterface : public Player {
public:
    PlayerInterface();

    string keyStrokeListener(int key, int wd);

    //included width and height so no longer overridden
    void draw(int width, int height);

    string getUserTyped() const;

    void setUserTyped(string u);

    void resetUserTyped();

    Asteroid tabAsteroidTarget(vector<Asteroid> &a);

    void setTargetedAsteroid(Asteroid &a);

private:
    string userTyped;

    Asteroid targetedAsteroid;

};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_PLAYERINTERFACE_H
