#ifndef BUNISSESTRAVELER_H
#define BUNISSESTRAVELER_H

#include "traveler.hpp"
#include "pager.hpp"
#include <string>

class BunissesTraveler : public Traveler {
  public:
    BunissesTraveler() : Traveler("") {pager.pager = "";};
    BunissesTraveler(const BunissesTraveler &bTraveler) : Traveler(bTraveler.traveler) {pager = bTraveler.pager.pager;};
    BunissesTraveler(std::string s) : Traveler(s) {pager = s;};
    BunissesTraveler& operator= (const BunissesTraveler &bTraveler) {pager = bTraveler.pager; traveler = bTraveler.traveler; return *this;};
  private:
    Pager pager = Pager("");
}; 

#endif 