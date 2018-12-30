//
// Created by William  Soccorsi on 12/21/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SCREEN_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SCREEN_H

#include "graphics.h"
#include "AbstractSpaceObject.h"
#include "Position.h"

class Screen : AbstractSpaceObject{

public:

    Screen();

    Screen(Position p);

    void draw();



private:
    int width;
    int height;
    Position p;


};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SCREEN_H
