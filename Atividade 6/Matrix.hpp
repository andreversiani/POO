#include <iostream>

template<class Template>
class Matrix {
    private:
        // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        Template** m;
        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, Template elem);
        Matrix(int rows, int cols);
        // destrutor
        ~Matrix();
        Matrix<Template> operator~ ();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        Template get(int row, int col) const;
        
        // other methods
        Matrix<Template> transpose();
        void print() const;
        void unit();
        void zeros();
        void ones();

        //operators
        Matrix<Template> operator+ (const Matrix<Template>& m);
        Matrix<Template> operator- (const Matrix<Template>& m);
        Matrix<Template> operator-= (const Matrix<Template>& m);
        Matrix<Template> operator+= (const Matrix<Template>& m);
        Matrix<Template> operator* (const Matrix<Template>& m);
        Matrix<Template> operator* (const int& num);
        Matrix<Template> operator*= (const Matrix<Template>& m);
        Matrix<Template> operator*= (const int& num);
        Template& operator() (const int row, const int col);
        bool operator== (const Matrix<Template>& m);
        bool operator!= (const Matrix<Template>& m);
        friend std::ostream& operator<< (std::ostream& out, const Matrix<Template>& m);
        friend std::istream& operator>> (std::ostream& in, const Matrix<Template>& m);

};
     