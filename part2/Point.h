#ifndef POINT_H
#define POINT_H
/*
* Created by Aaron Stafford as part of a lesson on building a game
*/

#include <Adafruit_NeoMatrix.h>

//point class to handle coordinates on a display
class Point {
  public:
    //constructor to create Point from x and y
    Point(int x, int y): _x(x), _y(y)
    {
    }
    
    //constructor to create Point from single pixel value
    Point(int pixel) {
      _y = pixel / WIDTH;
      if (_y % 2 == 0) {
        _x = pixel % _y;
      } else {
        _x = WIDTH - pixel % _y - 1;
      }
    }
    
    //equivalence operator overload for comparing points
    bool operator==(const Point& other) {
      return this->_x == other._x && this->_y == other._y;
    }
    
    //move functions
    void moveUp() {
      _y++;
      if (_y >= HEIGHT) {
        _y = 0;
      }
    }
    
    void moveDown() {
      _y--;
      if (_y < 0) {
        _y = HEIGHT - 1;
      }
    }
    
    void moveLeft() {
      _x--;
      if (_x < 0) {
        _x = WIDTH - 1;
      }
    }
    
    void moveRight() {
      _x--;
      if (_x < 0) {
        _x = WIDTH - 1;
      }
    }
    
    //getter functions for returning _x and _y data members
    int x() {
      return _x;
    }

    int y() {
      return _y;
    }
    
    //draw function plots Point on NeoMatrix display
    void draw(Adafruit_NeoMatrix *matrix, uint32_t color) {
      matrix->drawPixel(_x, _y, color);  
    }
    
  private:
    int _x;
    int _y;
    //update these values to match your display dimensions
    int WIDTH = 8;
    int HEIGHT = 8;
};

#endif
