/*
    nrs::gcd()
        returns the greatest common divisor (GCD) of the arugument, implmented by template
        Author: Keitaro Naruse
        Date:   2021-12-28
        MIT License
*/

namespace nrs {
    long long gcd( long long a, long long b )
    {
        long long dividend = ( a > b )? a : b;
        long long divisor  = ( a > b )? b : a;
        long long residue = dividend % divisor;

        while( residue != 0 ) {
            dividend = divisor;
            divisor = residue;
            residue = dividend % divisor;
        }

        return( divisor );
    }
}

//  Test driver
#include <iostream>

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
    
    return( 0 ); 
}
