/*
    038 - Large LCM
        https://atcoder.jp/contests/typical90/tasks/typical90_al
        Author: Keitaro Naruse
        Date:   2021-12-10, 2022-01-01
        MIT License
*/

// # Solution
//  - Find GCD by the Euclid algorithm
//  - Find LCM by the principle of A * B = GCD * LCM

#include <iostream>
#include <algorithm>

const bool Debug = false;

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

int main()
{
    //  Constant 1e18
    const long long M = 1000000000000000000LL;
    //  Read A and B
    long long A = 0LL, B = 0LL;
    std::cin >> A >> B;
    if( Debug ) {
        std::cerr << A << " " << B << std::endl;
    }
    
    //  Main
    //  Find LCM
    long long m_lcm = nrs::lcm( A, B );
    if( Debug ) {
        std::cerr << m_lcm << std::endl;
    }

    if( m_lcm > M ) {
        m_lcm = 0LL;
    }
    else if( m_lcm <= 0LL ) {
        m_lcm = 0LL;
    }
    else if( m_lcm < A ) {
        m_lcm = 0LL;
    }
    else if( m_lcm < B ) {
        m_lcm = 0LL;
    }
    
    //  Display result
    if( m_lcm == 0LL ) {
        std::cout << "Large" << std::endl;
    }
    else {
        std::cout << m_lcm << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
