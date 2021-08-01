#include <iostream>
#include "box.hpp"
#include <vector>
#include <string>

bool pontos_validator(vector<double> vec) {
  for (auto item1 : vec) {
    int count = 0;
    for (auto item2 : vec) {
      if (item1 == item2) count++;
    }
    if (count++ != 4) {
      cerr << "Os pontos não são válidos" << endl;
      return false;
    }
  }
  return true;
};

vector<Ponto3D> create_plane(vector<Ponto3D> pontos, string coordenada) {
  vector<Ponto3D> plane;
  Ponto3D p1  = pontos[0];
  if (coordenada == "x") {
    for (auto ponto: pontos) {
      if (ponto.get_x() == p1.get_x()) {
        plane.push_back(ponto);
      }
    }
  } if (coordenada == "y") {
    for (auto ponto: pontos) {
      if (ponto.get_y() == p1.get_y()) {
        plane.push_back(ponto);
      }
    }
  }
  return plane;
}

Box::Box(Ponto3D p1, Ponto3D p2, Ponto3D p3, Ponto3D p4, Ponto3D p5, Ponto3D p6, Ponto3D p7, Ponto3D p8) {
  vector<Ponto3D> pontos = {p1, p2, p3, p4, p5, p6, p7, p8};
  vector<double> coordenadasX = {p1.get_x(), p2.get_x(), p3.get_x(), p4.get_x(), p5.get_x(), p6.get_x(), p7.get_x(), p8.get_x()};
  vector<double> coordenadasY = {p1.get_y(), p2.get_y(), p3.get_y(), p4.get_y(), p5.get_y(), p6.get_y(), p7.get_y(), p8.get_y()};
  vector<double> coordenadasZ = {p1.get_z(), p2.get_z(), p3.get_z(), p4.get_z(), p5.get_z(), p6.get_z(), p7.get_z(), p8.get_z()};
  if (pontos_validator(coordenadasX) == false) this->~Box();
  if (pontos_validator(coordenadasY) == false) this->~Box(); 
  if (pontos_validator(coordenadasZ) == false) this->~Box();
  vector<Ponto3D> planeX = create_plane(pontos, "x");
  vector<Ponto3D> planeY = create_plane(pontos, "y");
  //determina a width
  for (auto ponto: planeY) {
    if (ponto.get_z() == planeX[0].get_z() && ponto.get_y() == planeX[0].get_y() && ponto.get_x() != planeX[0].get_x()) {
      this->width = ponto.dist(planeX[0]);
    }
  }
  //determina o height
  for (auto ponto: planeX) {
    if (ponto.get_z() != planeX[0].get_z() && ponto.get_y() == planeX[0].get_y() && ponto.get_x() == planeX[0].get_x()) {
      this->height = ponto.dist(planeX[0]);
    }
  }
  //determina a profundidade
  for (auto ponto: planeX) {
    if (ponto.get_z() == planeX[0].get_z() && ponto.get_y() != planeX[0].get_y() && ponto.get_x() == planeX[0].get_x()) {
      this->depth = ponto.dist(planeX[0]);
    }
  }
};

Box::~Box() {
};

double Box::get_width() {
  return this->width;
};

double Box::get_height() {
  return this->height;
};

double Box::get_depth() {
  return this->depth;
};

double Box::volume() {
  return this->width * this->height * this->depth;
};

double Box::area() {
  return 4*this->width * this->height + 2*this->depth * this->height;
};
