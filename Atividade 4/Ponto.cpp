#include "Ponto.hpp"
#include <iostream>
#include <math.h>
#include <time.h>


vector <int> Ponto::ids = {};

Ponto::Ponto() {
  this->x = 0.0;
  this->y = 0.0;
  this->id = this->getNextId();
};

Ponto::Ponto(double x, double y) {
  this->x = x;
  this->y = y;
  this->id = this->getNextId();
};

Ponto::Ponto(const Ponto& p) {
  *this = p;
  this->id = this->getNextId();
}

Ponto::~Ponto() {
  for (int i = 0; i < this->ids.size(); i++) {
   if (this->ids[i] = this->id) {
     this->ids.erase(this->ids.begin() + i);
   }
  }
  this->print();
};

int isIn(int num, vector<int> nums) {
  int k;
  for (auto i : nums) {
    if (num == i) {
      return true;
    }
  }
  return false;
}

int Ponto::getNextId() {
  int num;
  srand(time(0));
  do {
    num = rand() % 1000;
  } while (isIn(num, this->ids));
  this->ids.push_back(num);
  return num;
}

int Ponto::getID() {
  return this->id;
}

void Ponto::print() {
  cout << "(" << x << ", " << y << ")"<< endl;
};

double Ponto::distTo(Ponto p1) {
  return sqrt(pow(this->x - p1.getX(), 2) + pow(this->x - p1.getY(), 2));
};

double Ponto::getX() {
  return this->x;
};

double Ponto::getY() {
  return this->y;
};

double Ponto::distToOrig() {
  Ponto *p = new Ponto();
  return this->distTo(*p);
};
