/**
* @file abs.cpp
* @brief returns the absolute value of the arugument, implmented by template
* @author Keitaro Naruse
* @date 2021-12-26, 2022-03-20
* @copyright MIT License
*/

namespace nrs {
    /**
    * @brief absolute value
    * @param[in] an integer
    * @return T absolute value of a given integer
    */    
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 ) ? a : -a );
    }
}

//  Test driver
#include <iostream>

int main()
{
    int i = -1000000000;
    std::cout << "integer: "<< i << ", nrs::abs: " << nrs::abs( i ) << std::endl;

    long l = -1000000000;
    std::cout << "long: "<< l << ", nrs::abs: " << nrs::abs( l ) << std::endl;

    long long  ll = -1000000000000000000;
    std::cout << "long long: "<< ll << ", nrs::abs: " << nrs::abs( ll ) << std::endl;

    return( 0 ); 
}
