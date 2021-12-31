/*
    014 - We Used to Sing a Song Together（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_n
        Author: Keitaro Naruse
        Date:   2021-12-06, 2021-12-31
        MIT License
*/

// # Solution
// - Sort Ai, Sort Bi, i = 1,2,...,N
// - i = j

#include <iostream>
#include <vector>
#include <algorithm>

namespace nrs {
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 )? a : -a );
    }
}

const int Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Read Bi
    std::vector< int > B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
        if( Debug ) {
            std::cerr << B.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Main
    //  Sort A and B
    std::sort( A.begin(), A.end() );
    std::sort( B.begin(), B.end() );
    long long inconv = 0LL;
    for( int i = 0; i < N; i ++ ) {
        inconv += ( long long ) nrs::abs( A.at( i ) - B.at( i ) );
    }
    std::cout << inconv << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
