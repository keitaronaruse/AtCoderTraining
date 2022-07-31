/**
 * @file arc145-b.cpp
 * @brief ARC145 Problem B - AB Game
 * @author Keitaro Naruse
 * @date 2022-07-30
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc145/tasks/arc145_b
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

namespace nrs {
    template < class T >
    T gcd( T a, T b ) {
        T dividend = ( a > b ) ? a : b;
        T divisor = ( a > b ) ? b : a;
        T residue = dividend % divisor;

        while( residue != 0 ) {
            dividend = divisor;
            divisor = residue;
            residue = dividend % divisor;
        }

        return ( divisor );
    }

    template < class T >
    T lcm( T a, T b ) {
        long long g = nrs::gcd( a, b );
        return ( std::max( a, b ) / g * std::min( a, b ) );
    }
}  // namespace nrs

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p ) {
    os << "( " << p.first << ", " << p.second << " )";
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 10^18 ]
    long long N, A, B;
    std::cin >> N >> A >> B;

    //  Main
    long long A_wins = 0L;
    if( A <= B ) {
        A_wins = N - B;
    } else {
        if( N < A ) {
            A_wins = 0L;
        } else {
            long long k = N / A;
            A_wins = k  * B;
            if( N % A - B > 0L ) {
                A_wins += (N % A - B);
            }
        }
    }
    std::cout << A_wins << std::endl;

    //  Finalize
    return ( 0 );
}
