// matrix.cpp
#include "Matrix.hpp"
#include <iostream>
#include <string>

using namespace std;

template class Matrix<int>;
template class Matrix<double>;

template<class Template>
Matrix<Template>::Matrix(){
  this->nRows = 0;
  this->nCols = 0;
}
    
// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)

template<class Template>
Matrix<Template>::Matrix(int rows, int cols, Template elem)
{
	this->nRows = rows;
	this->nCols = cols;

	this->m = new Template *[rows];
	for (int i = 0; i < rows; i++)
	{
		this->m[i] = new Template[cols];
		for (int j = 0; j < cols; j++)
			this->m[i][j] = elem;
	}
}

template<class Template>
Matrix<Template>::Matrix(int rows, int cols) {
	this->nRows = rows;
	this->nCols = cols;
	this->m = new Template*[rows];
  for (int i = 0; i < rows; i++) {
    this->m[i] = new Template[cols];
  }
}

// obtem o numero de linhas
template<class Template>
int Matrix<Template>::getRows() const {
  return this->nRows;
}

// obtem o numero de colunas
template<class Template>
int Matrix<Template>::getCols() const {
  return this->nCols;
}

// retorna uma matriz transposta
template<class Template>
Matrix<Template> Matrix<Template>::transpose() {
  Matrix<Template> matrix = *this;

  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      matrix.m[j][i] = this->m[i][j];
    }
  }
  return matrix;
}

// imprime o conteudo da matriz
template<class Template>
void Matrix<Template>::print() const {
    for (int i = 0; i < this->nRows; i++) {
      for (int j = 0; j < this->nCols; j++) {
        cout << this->m[i][j] << " ";
    } 
    cout << endl;
  } 
}

template<class Template>
void change(double num, Matrix<Template> m) {
  for (int i = 0; i < m.getRows(); i++) {
      for (int j = 0; j < m.getCols(); j++) {
        m.m[i][j] = num;
    }
  } 
}

template<>
void Matrix<double>::unit() {
  if (this->getCols() == this->getRows()) {
    change(0.0, *this);
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
          if (i == j) this->m[i][j] = 1.0;
        }
      } 
    }
    else cout << "A matrix precisa ser quadrada para ser transformada em identidade" << endl;
}

template<>
void Matrix<double>::ones() {
  change(1.0, *this);
}

template<>
void Matrix<double>::zeros() {
  change(0.0, *this);
}

template<>
void Matrix<int>::unit() {
  if (this->getCols() == this->getRows()) {
    change(0.0, *this);
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
          if (i == j) this->m[i][j] = 1;
        }
      } 
    }
    else cout << "A matrix precisa ser quadrada para ser transformada em identidade" << endl;
}

template<>
void Matrix<int>::ones() {
  change(1.0, *this);
}

template<>
void Matrix<int>::zeros() {
  change(0.0, *this);
}

template<class Template>
void Matrix<Template>::unit() {
  cout << "A matrix deve ser composta por números" << endl;
}

template<class Template>
void Matrix<Template>::ones() {
  cout << "A matrix deve ser composta por números" << endl;
}

template<class Template>
void Matrix<Template>::zeros() {
  cout << "A matrix deve ser composta por números" << endl;
}

template<class Template>
Template Matrix<Template>::get(int row, int col) const {
  if (row >= 1 && col >= 1) return this->m[row - 1][col - 1];
  else {
    cout << "Essa linha nao existe";
    return Template();
  }
}

template<class Template>
Matrix<Template> Matrix<Template>::operator- (const Matrix<Template>& m) {
  Matrix<Template> m1 = copy(*this);
  for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getCols(); j++) {
        m1.m[i][j] -= m.m[i][j];
    } 
  }
  return m1;
}

template<class Template>
Matrix<Template> Matrix<Template>::operator-= (const Matrix<Template>& m) {
  return *this - m;
}

template<class Template>
Matrix<Template> Matrix<Template>::operator+ (const Matrix<Template>& m) {
  Matrix m1 = copy(*this);
  for (int i = 0; i < m1.getRows(); i++) {
      for (int j = 0; j < m1.getCols(); j++) {
        m1.m[i][j] += m.m[i][j];
    } 
  }
  return m1;
}

template<class Template>
Matrix<Template> Matrix<Template>::operator+= (const Matrix<Template>& m) {
  return *this + m;
}

template<class Template>
Matrix<Template> Matrix<Template>::operator* (const Matrix<Template>& m) {
  Matrix m1 = copy(*this);
  Matrix<Template> result = Matrix(this->getRows(), m.getCols());
  
  for(int i = 0; i < m1.getRows(); ++i)
    for(int j = 0; j < m.getCols(); ++j)
      for(int k = 0; k < m1.getCols(); ++k) {
        result.m[i][j] += m1.m[i][k] * m.m[k][j];
    }

  return result;
}

template<class Template>
Matrix<Template> Matrix<Template>::operator* (const int& num) {
  Matrix m = Matrix(this->getRows(), this->getCols());
  for (int i = 0; i < m.getRows(); i++) {
      for (int j = 0; j < m.getCols(); j++) {
        m.m[i][j] = this->m[i][j] * num;
    } 
  }
  return m;
}

template<class Template>
Matrix<Template> Matrix<Template>::operator*= (const Matrix<Template>& m) {
  return *this * m;
}


template<class Template>
Matrix<Template> Matrix<Template>::operator*= (const int& num) {
  return *this * num;
}


template<class Template>
bool Matrix<Template>::operator== (const Matrix<Template>& m) { 
  if (this->getCols() == m.getCols() && this->getRows() == m.getRows()) {
    for (int i = 0; i < this->getRows(); i++) {
      for (int j = 0; j < this->getCols(); j++) {
        if (this->m[i][j] != m.m[i][j]) return false;
    } 
  }
  return true;
  } else return false;
}

template<class Template>
bool Matrix<Template>::operator!= (const Matrix<Template>& m) {
  return !(*this == m);
}

template<class Template>
std::ostream& operator<< (std::ostream& out, const Matrix<Template>& m) {
  m.print();
  return out;
}

template<class Template>
std::istream& operator>> (std::istream& in, const Matrix<Template>& m) {
  for (int i = 0; i < m.getRows(); i++) {
    for (int j = 0; j < m.getCols(); j++) {
      in >> m.m[i][j];
    }
  }
  return in;
}

template<class Template>
Matrix<Template> Matrix<Template>::operator~ () {
  Matrix<Template> m = copy(*this);
  return m.transpose();
}

template<class Template>
Template& Matrix<Template>::operator() (const int row, const int col) {
  return this->m[row][col];
}

template<class Template>
Matrix<Template> copy(Matrix<Template> m) {
  Matrix<Template> m1(m.getRows(), m.getCols());
  for (int i = 0; i < m1.getRows(); i++) {
    for (int j = 0; j < m1.getCols(); j++) {
      m1.m[i][j] = m.m[i][j];
    }
  }
  return m1;
}
