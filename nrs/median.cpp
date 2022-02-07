/*
* @file median.cpp
* @brief nrs::median()
* @author Keitaro Naruse
* @date 2022-02-07
* @copyright MIT License
*/

#include <vector>
namespace nrs {
    template < class T >
    T median( const std::vector< T >& v )
    {
        size_t n = v.size();
        if( n % 2 == 1 ) {
            return( v.at( n / 2 ) );
        }
        else {
            return( ( v.at( n / 2 - 1 ) + v.at( n / 2 ) ) / 2 );
        }
    }
}

//  Test driver
#include <iostream>

int main()
{
    std::vector< int > v1 = { 1 }, v2 = { 1, 2 }, v3 = { 1, 2, 3 }, v4 = { 1, 2, 3, 4 };
    std::cout << "{ 1 }: " << nrs::median( v1 ) << std::endl;
    std::cout << "{ 1, 2 }: " << nrs::median( v2 ) << std::endl;
    std::cout << "{ 1, 2, 3 }: " << nrs::median( v3 ) << std::endl;
    std::cout << "{ 1, 2, 3, 4 }: " << nrs::median( v4 ) << std::endl;

    return( 0 ); 
}
