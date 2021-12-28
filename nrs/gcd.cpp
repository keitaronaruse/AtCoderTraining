/*
    nrs::gcd()
        returns the greatest common divisor (GCD) of the arugument, implmented by template
    nrs::lcm()
        returns the least common multiple
        Author: Keitaro Naruse
        Date:   2021-12-28
        MIT License
*/

#include <iostream>
#include <algorithm>

namespace nrs {
    template < class T >
    T gcd( T a, T b )
    {
        T dividend = ( a > b )? a : b;
        T divisor  = ( a > b )? b : a;
        T residue = dividend % divisor;

        while( residue != 0 ) {
            dividend = divisor;
            divisor = residue;
            residue = dividend % divisor;
        }

        return( divisor );
    }

    template < class T >
    T lcm( T a, T b )
    {
        long long g = nrs::gcd( a, b );
        return( std::max( a, b ) / g * std::min( a, b ) );  
    }
}

//  Test driver
int main()
{
    long long a_ll, b_ll;
    a_ll = 1000000000000000000LL; 
    b_ll =  999999999999999999LL; 
    std::cout << "a: "<< a_ll << ", b: " << b_ll << ", nrs::gcd: " << nrs::gcd( a_ll, b_ll ) << std::endl;
    
    a_ll =  999999999999999999LL; 
    b_ll = 1000000000000000000LL; 
    std::cout << "a: "<< a_ll << ", b: " << b_ll << ", nrs::gcd: " << nrs::gcd( a_ll, b_ll ) << std::endl;

    a_ll = 1000000000000000000LL; 
    b_ll =  100000000000000000LL; 
    std::cout << "a: "<< a_ll << ", b: " << b_ll << ", nrs::gcd: " << nrs::gcd( a_ll, b_ll ) << std::endl;
    
    a_ll =  100000000000000000LL; 
    b_ll = 1000000000000000000LL; 
    std::cout << "a: "<< a_ll << ", b: " << b_ll << ", nrs::gcd: " << nrs::gcd( a_ll, b_ll ) << std::endl;
    
    a_ll = 1000000000LL;
    b_ll =  999999999LL;
    std::cout << "a: "<< a_ll << ", b: " << b_ll << ", nrs::lcm: " << nrs::lcm( a_ll, b_ll ) << std::endl;

    long a_l, b_l;
    a_l = 1000000000;
    b_l =  999999999;
    std::cout << "a: "<< a_l << ", b: " << b_l << ", nrs::gcd: " << nrs::gcd( a_l, b_l ) << std::endl;
    
    a_l =  999999999;
    b_l = 1000000000;
    std::cout << "a: "<< a_l << ", b: " << b_l << ", nrs::gcd: " << nrs::gcd( a_l, b_l ) << std::endl;

    a_l = 1000000000;
    b_l =  100000000;
    std::cout << "a: "<< a_l << ", b: " << b_l << ", nrs::gcd: " << nrs::gcd( a_l, b_l ) << std::endl;
    
    a_l =  100000000;
    b_l = 1000000000;
    std::cout << "a: "<< a_l << ", b: " << b_l << ", nrs::gcd: " << nrs::gcd( a_l, b_l ) << std::endl;
    
    a_l = 10000;
    b_l =  9999;
    std::cout << "a: "<< a_l << ", b: " << b_l << ", nrs::lcm: " << nrs::lcm( a_l, b_l ) << std::endl;

    return( 0 ); 
}
