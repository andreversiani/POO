#include "tempo.hpp"
#include <iostream>

using namespace std;

int main() {
  Tempo t1 = Tempo(0, 20, 0, 0);
  Tempo t2 = Tempo(0, 120, 0, 0);
  t1.tempoSum(t2);
  t1.print();
  t1.addSec();
  t1.print();
}