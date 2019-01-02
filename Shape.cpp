//
// Created by Lisa Dion on 10/10/17.
//

#include "graphics.h"
#include "Shape.h"
#include <thread>
#include <chrono>

using namespace std;



Shape::Shape() : area(0), perimeter(0) {
    // default color: black
    fill = {0, 0, 0};
    // default position: (0, 0)
    position = {0, 0};
}

Shape::Shape(color f, point p) : fill(f),
                                 position(p),
                                 area(0),
                                 perimeter(0) {
}


int Shape::get_x() const {
    return position.x;
}

int Shape::get_y() const {
    return position.y;
}


void Shape::move(int delta_x, int delta_y) {
    // if delta_x and/or delta_y are negative,
    // will subtract from position
    set_position(position.x + delta_x, position.y + delta_y);
}


void Shape::set_position(int x_pos, int y_pos) {
    position = {x_pos, y_pos};
}


Circle::Circle() : Shape(), radius(0) {
}


Circle::Circle(double r, color f, point p) : Shape(f, p) {
    set_radius(r);
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r < 0) {
        radius = 0;
    } else {
        radius = r;
    }
}

color Circle::getFill() const {
    return fill;
}



void Circle::setFill(double r, double g, double b) {
  fill.red = r;
    fill.green = g;
    fill.blue = b;
}


color Circle::orange2Red() {
    for (int i = 1; i < 6; i++) {
          if (getFill().green == 0.5) {
              setFill(1, 0, 0);
          } else {
              setFill(1,0.5,0);
    }
        }
    }



void Circle::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    // set the color to the color saved in the Circle object
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    for (int i = 0; i <= 365; ++i) {
        double radian = i * M_PI / 180.0;
        glVertex2i(position.x+radius*cos(radian),
                   position.y+radius*sin(radian));
    }
    glEnd();

}





