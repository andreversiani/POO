#include "traveler.hpp"
#include "pager.hpp"
#include <string>
#include "bunissesTraveler.hpp"
#include <iostream>


int main() {
  Pager p("pager");
  Traveler t("traveler");
  BunissesTraveler bTraveler1("bTravelar1");
  BunissesTraveler bTraveler2(bTraveler1);
  BunissesTraveler bTraveler3 = BunissesTraveler();
  bTraveler3 = bTraveler2;
};