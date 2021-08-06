
#ifndef TRAVELER_H
#define TRAVELER_H
#include <string>

class Traveler {
  public:
    Traveler(std::string traveler){this->traveler = traveler;};
    Traveler(const Traveler &t) {this->traveler = t.traveler;};
    Traveler& operator= (const Traveler &t){traveler = t.traveler; return *this;};
  protected:
    std::string traveler;
}; 

#endif