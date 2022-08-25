#include <matrix.h>

Matrix::Matrix()
{
    matrix = std::make_unique< std::vector<std::vector<int>> >();
    rows = 0;
    collumns = 0;
}

Matrix::Matrix( Matrix& A ) : rows{A.rows} , collumns{ A.collumns }
{
    matrix = std::make_unique< std::vector<std::vector<int>> >( *A.matrix.get() );
}

Matrix::Matrix( std::vector<std::vector<int>> m)
{
    matrix = std::make_unique<std::vector<std::vector<int>>>(m);
    rows = m.size();
    collumns = m.at(0).size();
}

Matrix::Matrix( int n , int m , int item )
{   if( n >= 0 ){ rows = n; } else { rows = 0; }
    if( m >= 0 ){ collumns = m;} else { collumns = 0; }

    std::vector<int> row( collumns , item ); //TODO: upgrade
    std::vector<std::vector<int>> t_matrix({row});
    for( int i = 1; i < n  ;i++ ){ t_matrix.push_back(row); }

    matrix = std::make_unique< std::vector<std::vector<int>> >(t_matrix);
}

Matrix::~Matrix()
{
    this->matrix->clear();
    //std::cout << "PING" << std::endl;
}


Matrix& operator*( int k , Matrix& A )
{
    for( auto& it : *A.get_matix() )
    {
            for( auto& num : it ){ num *= k; }
    }

    A.set_rows( A.get_matix()->size() );
    A.set_collumns(A.get_matix()->at(0).size());

    return A;
}

Matrix& operator*( Matrix& A , int k )
{
    for( auto& it : *A.get_matix() )
    {
            for( auto& num : it ){ num *= k; }
    }

    A.set_rows( A.get_matix()->size() );
    A.set_collumns(A.get_matix()->at(0).size());

    return A;
}

Matrix& Matrix::operator=( Matrix X )
{
    this->matrix = std::make_unique<std::vector<std::vector<int>>>(*X.matrix.get());
    this->collumns = X.collumns;
    this->rows = X.rows;

    return *this;
}

std::vector<std::vector<int>>*  Matrix::get_matix()
{
    return this->matrix.get();
}

