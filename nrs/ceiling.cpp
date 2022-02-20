/**
* @file ceiling.cpp
* @brief ceiling function
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
*/

// # Solution

#include <iostream>

const bool Debug = true;

namespace nrs {
    template < class T >
    T ceiling( T a, T b )
    {
        return( ( a + b - 1 ) / b );
    }
}

int main()
{
    //  int
    int a = 20, b = 10;
    std::cout << "a = " << a << ", b = " << b 
        << ", ceiling( a / b ) = " << nrs::ceiling( a, b ) << std::endl;
    a = 21;
    std::cout << "a = " << a << ", b = " << b 
        << ", ceiling( a / b ) = " << nrs::ceiling( a, b ) << std::endl;
    a = 29;
    std::cout << "a = " << a << ", b = " << b 
        << ", ceiling( a / b ) = " << nrs::ceiling( a, b ) << std::endl;
    a = 30;
    std::cout << "a = " << a << ", b = " << b 
        << ", ceiling( a / b ) = " << nrs::ceiling( a, b ) << std::endl;
    a = 31;
    std::cout << "a = " << a << ", b = " << b 
        << ", ceiling( a / b ) = " << nrs::ceiling( a, b ) << std::endl;

    //  long long
    long long aLL = 21LL, bLL = 10LL;
    std::cout << "a = " << aLL << ", b = " << bLL 
        << ", ceiling( a / b ) = " << nrs::ceiling( aLL, bLL ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
