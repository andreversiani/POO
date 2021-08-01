#include <vector>
using namespace std;

class Ponto {
  
  public:
    Ponto();
    Ponto(double x, double y);
    Ponto(const Ponto& p);
    ~Ponto();
    void print();
    double distToOrig();
    double distTo(Ponto p1);
    double getX();
    double getY();
    int getID();

  private:
    double x;
    double y;
    int getNextId();
    int id;
    static vector<int> ids;
};