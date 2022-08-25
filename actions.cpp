#include <actions.h>

int actions_matrix::sum_of_products( std::vector<int>& row , Matrix& B , int collumn)
{
    int sum = 0;
    for( int i = 0; i < row.size() ;i++ )
    { sum += row.at(i) * B.get_matix()->at(i).at(collumn); }

    return sum;
}

Matrix actions_matrix::add_matrix( Matrix& A, Matrix& B )
{ if( A.get_collumns() != B.get_collumns() || A.get_rows() != B.get_rows() ){ throw std::logic_error(" Matrixes doesn't have same sizes. (Addition)"); } //error matrix
    Matrix answ( A.get_rows() , A.get_collumns() , 0 );

    for( int i = 0; i < A.get_rows() ;i++ )//TODO: вынестив отдельную переменную размеры
    {
        for( int j = 0; j < A.get_collumns() ;j++ )
        {
            answ.get_matix()->at(i).at(j) = A.get_matix()->at(i).at(j) + B.get_matix()->at(i).at(j);
        }
    }

    answ.set_rows( A.get_rows() );
    answ.set_collumns( A.get_collumns() );
 return answ;
}

Matrix actions_matrix::sub_matrix( Matrix& A, Matrix& B )
{ if( A.get_collumns() != B.get_collumns() || A.get_rows() != B.get_rows() ){ throw std::logic_error(" Matrixes doesn't have same sizes. (Addition)"); } //error matrix
    Matrix answ( A.get_rows() , A.get_collumns() , 0 );

    for( int i = 0; i < A.get_rows() ;i++ )//TODO: вынестив отдельную переменную размеры
    {
        for( int j = 0; j < A.get_collumns() ;j++ )
        {
            answ.get_matix()->at(i).at(j) = A.get_matix()->at(i).at(j) - B.get_matix()->at(i).at(j);
        }
    }

    answ.set_rows( A.get_rows() );
    answ.set_collumns( A.get_collumns() );
 return answ;
}

Matrix actions_matrix::multiply_matrix( Matrix& A, Matrix& B )
{if( A.get_collumns() != B.get_rows() || A.get_rows() != B.get_collumns() ){ throw std::logic_error(" Matrixes doesn't have same sizes. (Multiplying)"); } //error matrix
    Matrix answ( A.get_rows() , B.get_collumns() , 0 );

    for( int i = 0; i < A.get_rows(); i++ ) //TODO: вынестив отдельную .. переменную размеры
    {
        for( int j = 0; j < B.get_collumns(); j++ ){ answ.get_matix()->at(i).at(j) = sum_of_products( A.get_matix()->at(i) , B , j ); }
    }

    return answ;
}

int actions_matrix::calculate_main_axis( Matrix& A )
{   int sum = 0;
    for( int i = 0; i < std::min( A.get_rows() , A.get_collumns() ) ;i++ )
    {
        sum += A.get_matix()->at(i).at(i);
    }

    return sum;
}

int actions_matrix::calculate_side_axis( Matrix& A )
{
    int sum = 0;
    for( int i = 0; i < std::min(A.get_collumns() , A.get_rows()) ;i++ )
    { sum += A.get_matix()->at(i).at( A.get_collumns() - 1-i ); }

    return sum;
}
