#include <iostream>

using namespace std;

class Tempo {

  public:
    
    int dia, hora, min, seg;
    void checkConsistency();
    void tempoSum(Tempo t);
    void print();
    void addSec();
    void subSec();

    Tempo(int dia);
    Tempo(int dia, int horas);
    Tempo(int dia, int horas, int min);
    Tempo(int dia, int horas, int min, int segs);

};