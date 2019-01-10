//
// Created by William  Soccorsi on 12/17/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_LASER_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_LASER_H


#include "AbstractSpaceObject.h"
#include "graphics.h"

class Laser : public AbstractSpaceObject{

public:

    Laser();

    Laser (Position p);


    void draw();




private:

    int swap = 0;

};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_LASER_H
