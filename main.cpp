#include <actions.cpp>
#include <matrix.cpp>
#include <cassert> //не получилось

using namespace actions_matrix;

int main()
{
//    Matrix A ({{1 , 2 , 3} ,
//               {4 , 5 , 6} });

//    Matrix B ({{7 , 10} ,
//               {8 , 11} ,
//               {9 , 12} });

    Matrix A ({{23 , 22 , 47} ,
               {32 , 3 , 79} ,
               {3  , 7 , 78},
               {45 , 7 , 2}});

    Matrix B ({{7 , 2 ,  7} ,
               {8 , 43 , 49} ,
               {9 , 7 ,  7},
               {8 , 7 ,  22}});

    try{
        A = actions_matrix::sub_matrix( A , B );

        drow_matrix( B );
        std::cout << "===================================" << std::endl;
        drow_matrix( transpose(B) );

        //решение задачи:
        //Условие: D = A^T*(C^T-B*A) //значения лень придумывать
    }
    catch( std::logic_error err ){ std::cout << "Error: " << err.what() << std::endl; }

    return 0;
}
