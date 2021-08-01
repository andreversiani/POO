#include "ponto3D.hpp"

class Box {

  public:
    Box(Ponto3D p1, Ponto3D p2, Ponto3D p3, Ponto3D p4, Ponto3D p5, Ponto3D p6, Ponto3D p7, Ponto3D p8);
    ~Box();
    double get_width();
    double get_height();
    double get_depth();
    double volume();
    double area();

  private:
    double width;
    double height;
    double depth;
};