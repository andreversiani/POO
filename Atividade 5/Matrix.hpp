#include <iostream>


class Matrix {
    private:
        // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas


    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, double elem);
        Matrix(int rows, int cols);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        double get(int row, int col) const;
        
        // other methods
        Matrix transpose();
        void print() const;
        void unit();
        void zeros();
        void ones();

        //os testes estão na matrix.cpp

        Matrix operator+ (const Matrix& m);
        Matrix operator- (const Matrix& m);
        Matrix operator-= (const Matrix& m);
        Matrix operator+= (const Matrix& m);
        Matrix operator* (const Matrix& m);
        Matrix operator* (const int& num);
        Matrix operator*= (const Matrix& m);
        Matrix operator*= (const int& num);
        double& operator() (const int row, const int col);
        Matrix operator~ ();
        bool operator== (const Matrix& m);
        bool operator!= (const Matrix& m);
        friend std::ostream& operator<< (std::ostream& out, const Matrix& m);
        friend std::istream& operator>> (std::ostream& in, const Matrix& m);
        
        double** m;

};
     