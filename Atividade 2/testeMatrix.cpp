#include "matrix.hpp"
#include <iostream>

using namespace std;

int main() {
    
    Matrix Y = Matrix(3,2,6.0);
    Matrix X = Matrix(3,3,4.0);
    std::cout << "Y:: " << std::endl;
    Y.print();
    std::cout << "Numero de linhas de Y: " << Y.getRows() << endl;
    std::cout << "Numero de colunas de Y: " << Y.getCols() << endl;
    std::cout << "Z é transposta de Y: " << std::endl;
    Matrix Z = Y.transpose();
    Z.print();
    std::cout << "Numero de linhas de Z: " << Z.getRows() << endl;
    std::cout << "Numero de colunas de Z: " << Z.getCols() << endl;
    std::cout << "X: " << std::endl;
    X.print();
    std::cout << "Numero de linhas de X: " << X.getRows() << endl;
    std::cout << "Numero de colunas de X: " << X.getCols() << endl;
   
    return 0;
}