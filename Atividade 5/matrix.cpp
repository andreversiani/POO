// matrix.cpp
#include "Matrix.hpp"
#include <iostream>
#include <string>

using namespace std;
// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
  this->nRows = 0;
  this->nCols = 0;
}
    
// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)

Matrix::Matrix(int rows, int cols, double elem)
{
	this->nRows = rows;
	this->nCols = cols;

	this->m = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		this->m[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			this->m[i][j] = elem;
	}
}

Matrix::Matrix(int rows, int cols)
{
	this->nRows = rows;
	this->nCols = cols;

	this->m = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		this->m[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			this->m[i][j] = 0.0;
	}
}

// destrutor
Matrix::~Matrix() {
  
}

// obtem o numero de linhas
int Matrix::getRows() const {
    return this->nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
  return this->nCols;
}

// retorna uma matriz transposta
Matrix Matrix::transpose() {
  Matrix matrix = Matrix(this->nCols, this->nRows, 0.0);

  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      matrix.m[j][i] = this->m[i][j];
    }
  }
  return matrix;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for (int i = 0; i < this->nRows; i++) {
      for (int j = 0; j < this->nCols; j++) {
        cout << this->m[i][j] << " ";
    } 
    cout << endl;
  } 
}

void change(double num, Matrix m) {
  for (int i = 0; i < m.getRows(); i++) {
      for (int j = 0; j < m.getCols(); j++) {
        m.m[i][j] = num;
    }
  } 
}

void Matrix::unit() {
  if (this->getCols() == this->getRows()) {
    change(0.0, *this);
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
          if (i == j) {
            this->m[i][j] = 1.0;
          }
        }
      } 
    }
    else {
      cout << "A matrix precisa ser quadrada para ser transformada em identidade" << endl;
    }
}

void Matrix::ones() {
  change(1.0, *this);
}

void Matrix::zeros() {
  change(0.0, *this);
}

double Matrix::get(int row, int col) const {
  if (row >= 1 && col >= 1) {
    return this->m[row - 1][col - 1];
  }
  else {
    cout << "Essa linha nao existe";
    return 0.0;
  }
}

Matrix Matrix::operator- (const Matrix& m) {
  Matrix m1 = Matrix(this->getRows(), this->getCols());

  for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getCols(); j++) {
        m1.m[i][j] = this->m[i][j];
    } 
  }
  for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getCols(); j++) {
        m1.m[i][j] -= m.m[i][j];
    } 
  }
  return m1;
}

Matrix Matrix::operator-= (const Matrix& m) {
  *this = *this - m;
  return *this;
}

Matrix Matrix::operator+ (const Matrix& m) {
  Matrix m1 = Matrix(this->getRows(), this->getCols());

  for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getCols(); j++) {
        m1.m[i][j] = this->m[i][j];
    } 
  }

  for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getCols(); j++) {
        m1.m[i][j] += m.m[i][j];
    } 
  }
  return m1;
}

Matrix Matrix::operator+= (const Matrix& m) {
  *this = *this + m;
  return *this;
}

Matrix Matrix::operator* (const Matrix& m) {
  Matrix m1 = Matrix(this->getRows(), this->getCols());
  Matrix result = Matrix(this->getRows(), m.getCols());
  
  for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getCols(); j++) {
        m1.m[i][j] = this->m[i][j];
    } 
  }
  
  for(int i = 0; i < this->getRows(); ++i)
    for(int j = 0; j < m.getCols(); ++j)
      for(int k = 0; k < this->getCols(); ++k) {
        result.m[i][j] += this->m[i][k] * m.m[k][j];
    }

  return result;
}

Matrix Matrix::operator* (const int& num) {
  Matrix m = Matrix(this->getRows(), this->getCols());
  for (int i = 0; i < m.getRows(); i++) {
      for (int j = 0; j < m.getCols(); j++) {
        m.m[i][j] = this->m[i][j] * num;
    } 
  }
  return m;
}


Matrix Matrix::operator*= (const Matrix& m) {
  *this = *this * m;
  return *this;
}

Matrix Matrix::operator*= (const int& num) {
  *this = *this * num;
  return *this;
}

bool Matrix::operator== (const Matrix& m) { 
  if (this->getCols() == m.getCols() && this->getRows() == m.getRows()) {
    for (int i = 0; i < this->getRows(); i++) {
      for (int j = 0; j < this->getCols(); j++) {
        if (this->m[i][j] != m.m[i][j]) return false;
    } 
  }
  return true;
  } else {
    return false;
  }

}

bool Matrix::operator!= (const Matrix& m) {
  return !(*this == m);
}

std::ostream& operator<< (std::ostream& out, const Matrix& m) {
  m.print();
  return out;
}

std::istream& operator>> (std::istream& in, const Matrix& m) {
  for (int i = 0; i < m.getRows(); i++) {
    for (int j = 0; j < m.getCols(); j++) {
      in >> m.m[i][j];
    }
  }
  return in;
}

Matrix Matrix::operator~ () {
  Matrix m = Matrix(this->getRows(), this->getCols());
  for (int i = 0; i < this->getRows(); i++) {
      for (int j = 0; j < this->getCols(); j++) {
        m.m[i][j] = this->m[i][j];
    } 
  }
  return m.transpose();
}

double& Matrix::operator() (const int row, const int col) {
  return this->m[row][col];
}

int main()
{
    Matrix Y, W;
    Matrix X(3,1), A(3,3), C(3,3);
    Matrix Z(3,2,7.0);
    
    // operadores a serem implementados em sua classe:
    
    A(2,1) = 10;                               // altera o valor de uma posição de A
    C = A + A;                                  // Soma
    C -= A;                                     // Subtração       
    A = C - A;                                  // Subtração
    A += A;                                   // Soma
    A = ~C;                                  // A é igual a transposta de C
    X *= 2;                                   // multiplicação por uma constante
    C = A*X;                                         // multiplicação de matrizes
    C *= X;                                          // multiplicação de matrizes
    cout << (A == C) << endl;                              // verifica a igualdade entre A e C
    cout << (X != Y) << endl;                           // verifica a desigualdade entre A e C
    cout << Z << endl;
    cin >> Y;                         // impressão de matrizes

    return 0;
}