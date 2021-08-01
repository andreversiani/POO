#include <iostream> 

class Ponto {
    int x,y;
    
    public:
        Ponto(int xx=0, int yy=0):x(xx),y(yy){ };
        Ponto& operator-- ();
        Ponto operator+ (const Ponto& p) const;
        ~Ponto(){};
        int getX() const;
        int getY() const;
};

Ponto& Ponto::operator--() {
  this->x--;
  this->y--;
  return *this;
}

Ponto Ponto::operator+ (const Ponto& p) const {
  Ponto p1 = Ponto();
  p1.x = this->x + p.x;
  p1.y = this->y + p.y;
  return p1;
}

int Ponto::getX() const{
  return this->x;
}
int Ponto::getY() const{
  return this->y;
}

int main() {

    Ponto a(1,4), b(3,2), c;
    c = a + b;              
    std::cout << "(" << c.getX() << ", " <<  c.getY() << ")" << std::endl;   // soma as coordenadas dos pontos a e b 
    --c;
    std::cout << "(" << c.getX() << ", " <<  c.getY() << ")" << std::endl;                    // decrementa em uma unidade as coordenadas de c
}