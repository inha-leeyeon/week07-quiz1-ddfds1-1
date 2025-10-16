#pragma once
#include <vector>
#include "Point.h"
#include <string>
using namespace std;

class Square : public Point {
public:
    Square(const string, int, int, unsigned int = 0);
    int getSide() const;
    unsigned int getArea() const;
    string getName() const;
    void setSide(unsigned int);
    void setArea(unsigned int);
    void setName(string);
private:
    int side;
    unsigned int area{ 0 };
    string name;
};

