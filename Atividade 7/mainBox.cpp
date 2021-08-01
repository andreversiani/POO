#include "ponto3D.hpp"
#include "box.hpp"
#include "ponto2D.hpp"


int main() {
  Ponto3D p1(0,0,0);
  Ponto3D p2(0,0,1);
  Ponto3D p3(0,1,1);
  Ponto3D p4(0,1,0);
  Ponto3D p5(1,0,1);
  Ponto3D p6(1,0,0);
  Ponto3D p7(1,1,0);
  Ponto3D p8(1,1,1);
  Box box(p1, p2, p3, p4, p5, p6, p7, p8);
  cout << box.get_width() << endl;
  cout << box.get_height() << endl;
  cout << box.get_depth() << endl;
  cout << box.volume() << endl;
  cout << box.area() << endl;
}