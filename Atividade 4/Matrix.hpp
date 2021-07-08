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
        
        double** m;

};
     