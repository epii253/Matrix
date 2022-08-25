#include <actions.cpp>
#include <matrix.cpp>
#include <cassert> // пока не используется

int main()
{
//    Matrix A ({{1 , 2 , 3} ,
//               {4 , 5 , 6} });

//    Matrix B ({{7 , 10} ,
//               {8 , 11} ,
//               {9 , 12} });

    Matrix A ({{ 7  , 89 },
               { 85 , 77},
               { 4  , 22 }});

    Matrix B ({{7 , 10} ,
               {8 , 11} ,
               {9 , 12} });

    try{
        A = actions_matrix::sub_matrix( A , B );

        for( auto& it : *A.get_matix() ){ for( auto& num : it ){ std::cout << num << " "; } std::cout << "" << std::endl; }
    }
    catch( std::logic_error err ){ std::cout << "Error: " << err.what() << std::endl; }

    return 0;
}
