#include <iostream>
#include "Point.h"
#include "Square.h"
#include <vector>
#include <algorithm>
using namespace std;

Point::Point(int px, int py){x = px; y = py;}
int Point::getX() const{return x;}
int Point::getY() const{return y;}
void Point::setX(int a){x = a;}
void Point::setY(int a){y = a;}

Square::Square(const string a, int b , int c, unsigned int d)
:Point(b,c){name = a; side = d;}
int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return side * side; }
string Square::getName() const { return name; }
void Square::setSide(unsigned int a){side = a;}
void Square::setArea(unsigned int a) { area = a; }
void Square::setName(string a){ name = a;}

bool compareArea(Square& a, Square& b) {
    return (a.getArea() < b.getArea());
}

bool compareX(Square& a, Square& b) {
    return (a.getX() + a.getSide() < b.getX() + b.getSide());
}

bool compareY(Square& a, Square& b) { 
    return (a.getY() + a.getSide() < b.getY() + b.getSide()); }

int main()
{
    int cnt;
    string name;
    int x, y, side;
    cin >> cnt;
    int calx;
    int caly;
    vector<Square> nemo;
    for (int i = 0; i < cnt; i++) {
        cin >> name >> x >> y >> side;
        Square s(name, x, y, side);
        nemo.push_back(s);
    }

   
    cout << "\nSquares in increaing order of area" << endl;
    sort(nemo.begin(), nemo.end(), compareArea);
    for (int i = 0; i < cnt; i++) {
        cout << nemo[i].getName();
        cout << "(" << nemo[i].getX() << "," << nemo[i].getY()<<")";
        cout << " side=" << nemo[i].getSide() << ", area=" << nemo[i].getArea() << endl;
    }

    cout << "\n\nSquares in increaing order of max x-coordinate" << endl;
    sort(nemo.begin(), nemo.end(), compareX);
    for (int i = 0; i < cnt; i++) {
        cout << nemo[i].getName();
        cout << "(" << nemo[i].getX() + nemo[i].getSide() << "," << nemo[i].getY() << ")";
        cout << " side=" << nemo[i].getSide() <<", area=" << nemo[i].getArea() << endl;
    }

    cout << "\n\nSquares in increaing order of max y-coordinate" << endl;
    sort(nemo.begin(), nemo.end(), compareY);
    for (int i = 0; i < cnt; i++) {
        cout << nemo[i].getName();
        cout << "(" << nemo[i].getX() << "," << nemo[i].getY()+nemo[i].getSide() << ")";
        cout << " side=" << nemo[i].getSide() << ", area=" << nemo[i].getArea() << endl;
    }
}
