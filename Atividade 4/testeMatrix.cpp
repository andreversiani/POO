#include "matrix.hpp"
#include <iostream>

using namespace std;

int main() {
    Matrix X(3,1);
    Matrix Z(3,3,7.0);
    Matrix K(Z);

    cout << "<------------------X------------------> " << endl;
    X.print();
    cout << "<------------------Z------------------> " << endl;
    Z.print();
    cout << "<------------------K------------------> " << endl;
    K.print();
    cout << "<-----Transformacao em identidade-----> " << endl;
    Z.unit();
    Z.print();
    cout << "<-Pegando elemento em (1,1), que na verdade e [0,0]-> " << endl;
    cout << Z.get(1,1);
}