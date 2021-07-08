// matrix.cpp
#include "Matrix.hpp"
#include <iostream>

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
