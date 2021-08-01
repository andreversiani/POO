#ifndef PONTO2D_H
#define PONTO2D_H

#include<iostream>

using namespace std;

class Ponto2D {
  public:
    Ponto2D(int xx = 0.0, int yy = 0.0):x(xx),y(yy){ };
    friend ostream& operator<< (ostream &op, const Ponto2D &p);
    Ponto2D& operator= (const Ponto2D &p);
    ~Ponto2D(){};
    double get_x(void) { return x; }
    double get_y(void) { return y; }
    void set (double nx, double ny) { x=nx; y=ny; }
    
  private:                
    double x;
    double y;
};

#endif