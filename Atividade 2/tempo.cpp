#include <iostream>
#include "tempo.hpp"

using namespace std;

Tempo::Tempo(int dia) {
  this->dia = dia;
  this->checkConsistency();
}
Tempo::Tempo(int dia, int horas) {
  this->dia = dia;
  this->hora = horas;
  this->checkConsistency();
}
Tempo::Tempo(int dia, int horas, int min) {
  this->dia = dia;
  this->hora = horas;
  this->min = min;
  this->checkConsistency();
}
Tempo::Tempo(int dia, int horas, int min, int segs) {
  this->dia = dia;
  this->hora = horas;
  this->min = min;
  this->seg = segs;
  this->checkConsistency();
}

void Tempo::checkConsistency() {

  if (this->seg > 59) {
    
    this->min += this->seg / 60;
    this->seg = this->seg % 60;
  }
   
  if (this->min > 59 ) {
    this->hora += this->min / 60;
    this->min = this->min % 60;
  }
  
  if (this->hora > 23) {
    this->dia += this->hora / 24;
    this->hora = this->hora % 24;
  }
}

void Tempo::print() {
  cout << " Dia: " << this->dia << endl 
  << " Hora: " << this->hora << endl 
  << " minutos: " << this->min << endl 
  << " segundos: " << this->seg << endl;
}

void Tempo::tempoSum(Tempo t) {
  this->dia = this->dia + t.dia;
  this->hora = this->hora + t.hora;
  this->min = this->min + t.min;
  this->seg = this->seg + t.seg;
  this->checkConsistency();
}

void Tempo::addSec() {
  this->seg +=1;
}

void Tempo::subSec() {
  this->seg -= 1;
}