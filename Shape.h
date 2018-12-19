//
// Created by Lisa Dion on 10/10/17.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SHAPE_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SHAPE_H


#include <iostream>
#include <cmath>
using namespace std;

struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

// Abstract parent class
class Shape {
public:
    // Constructors
    Shape();
//    Shape(color f);
//    Shape(point p);
    Shape(color f, point p);

    // getters
    virtual int get_x() const;

    virtual int get_y() const;

    // call set_position
    // delta_x and delta_y can be any value
    virtual void move(int delta_x, int delta_y);

    // setters
    virtual void set_position(int x_pos, int y_pos);

    // method to draw shape
    // pure virtual
    virtual void draw() const = 0;

protected:
    color fill;
    point position;
    double area;
    double perimeter;
};

class Circle : public Shape {
    // position is the center of the circle
private:
    double radius;

public:
    // Constructors
    Circle();

    Circle(double r, color f, point p);

    virtual color getFill() const;

    // getter
    virtual double get_radius() const;

    // setter
    virtual void set_radius(double r);

    virtual void setFill(double r, double g, double b);

    virtual void draw() const override;


    /*
     * R: Shape Circle
     * M: Setfill of circle
     * E: Creates red or orange color depending on what it was before
     */
    virtual color orange2Red();
};






#endif //A_BLAST_FROM_THE_PAST_SHAPE_H