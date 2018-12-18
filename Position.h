//
// Created by William  Soccorsi on 12/17/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_POSITION_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_POSITION_H


class Position {

public:

    Position();

    Position(int x, int y);


    void setX(int x);

    void setY(int y);

    int getX() const;

    int getY() const;

protected:
    int x;
    int y;
};



#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_POSITION_H
