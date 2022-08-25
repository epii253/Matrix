#ifndef ACTIONS_H
#define ACTIONS_H

#include <matrix.h>

namespace actions_matrix {

    Matrix add_matrix( Matrix& A , Matrix& B );
    Matrix multiply_matrix( Matrix& A , Matrix& B );
    Matrix sub_matrix( Matrix& A , Matrix& B );
    int calculate_main_axis( Matrix A );
    int calculate_side_axis( Matrix A );
    int sum_of_products( std::vector<int>& row , Matrix B , int collumn );

    //hard, but (later)
    void push_row( std::vector<int>  row);
    void push_collumn( std::vector<int> collumn );

}

#endif // ACTIONS_H
