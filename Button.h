//
// Created by William  Soccorsi on 12/22/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_BUTTON_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_BUTTON_H

#include "AbstractSpaceObject.h"
#include "graphics.h"
#include <iostream>

using namespace std;

class Button : public AbstractSpaceObject {

public:

   Button();

   Button(int width, int height);

   bool isOverlapping(int x, int y);

   void draw() override;

   void setColor(double r,double g,double b);

   Color getColor();

   void setMessage(string s);

   string getMessage() const;

private:
    Color fill;
    int width;
    int height;
    string message;

};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_BUTTON_H
