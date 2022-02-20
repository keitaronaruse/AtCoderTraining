/**
* @file abc239-b.cpp
* @brief ABC239 Problem B - Integer Division
* @author Keitaro Naruse
* @date 2022-02-19, 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc239/tasks/abc239_b
*/

// # Solution

#include <iostream>

const bool Debug = false;

namespace nrs {
    template < class T >
    T ceiling( T a, T b )
    {
        return( ( a + b - 1 ) / b );
    }
}

int main()
{
    //  Read X = [ -10^18, 10^18 ]
    long long X = 0LL;
    std::cin >> X;
    if( Debug ) {
        std::cerr << X <<  std::endl;
    }

    //  Main
    long long floor_x = 0LL;
    if( X >= 0LL ) {
        floor_x = X / 10LL;
    }
    else {
        floor_x = -nrs::ceiling( -X, 10LL );
    }
    //  Output the result
    std::cout << floor_x << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
