//
// Created by William  Soccorsi on 1/9/19.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_DEBRIS_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_DEBRIS_H


#include "AbstractSpaceObject.h"
#include "Position.h"
#include "graphics.h"
#include <iostream>



class Debris : public AbstractSpaceObject {


public:

    Debris();

    Debris(Position p, std::string sentence);


    virtual void draw() override;




protected:
    enum size s;
    int x;
    int y;
    std::string sentence;
};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_DEBRIS_H
