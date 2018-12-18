//
// Created by William  Soccorsi on 12/17/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_ABSTRACTSPACEOBJECT_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_ABSTRACTSPACEOBJECT_H

#include "Position.h"

class AbstractSpaceObject {

public:

    AbstractSpaceObject();

    AbstractSpaceObject(Position p);

    virtual void draw();

    virtual void move(int x, int y);

    virtual int getHealth() const;

    virtual void setHealth(int h);

    virtual Position getPosition() const;

    virtual void setPosition(Position pos);

    virtual bool getIsDrawn() const;

    virtual void setIsDrawn(bool b);

private:

    int health;

    Position p;

    bool isDrawn;


};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_ABSTRACTSPACEOBJECT_H
