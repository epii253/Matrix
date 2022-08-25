#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <cmath>
#include <exception>
#include <memory>

class Matrix{

    std::unique_ptr< std::vector<std::vector<int>> >matrix;
    size_t rows = 0 ;
    size_t collumns = 0;

public:
    Matrix();
    Matrix( Matrix& A );
    Matrix( std::vector<std::vector<int>> m );
    Matrix( int n , int m , int item );
    ~Matrix();

    std::vector<std::vector<int>>* get_matix();
    inline size_t get_rows(){ return this->rows; }
    inline size_t get_collumns(){ return this->collumns; }

    inline void set_rows( int row ){ this->rows = row; }
    inline void set_collumns( int collumn ){ this->collumns = collumn; }

    //virtual Matrix& operator*( int k , Matrix& A);
    virtual Matrix& operator=( Matrix n );
};

#endif // MATRIX_H
