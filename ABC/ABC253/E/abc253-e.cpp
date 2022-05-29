/**
 * @file abc253-e.cpp
 * @brief ABC253 Problem E - Distance Sequence
 * @author Keitaro Naruse
 * @date 2022-05-28
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc253/tasks/abc253_e
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

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

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os,
                          const std::vector< std::vector< T > >& vv ) {
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return ( os );
}

int main( ) {
    //  Constant
    const int P = 998244353;
    //  Read N = [ 2, 10^3 ], M = [ 1, 5*10^3 ], K = [ 0, M - 1 ]
    int N, M, K;
    std::cin >> N >> M >> K;

    //  Main
    //  DP table
    std::vector< std::vector< int > > dp( N + 1, std::vector< int >( M + 1, 0 ) );
    //  DP initial boundary
    for( int j = 1; j <= M; j ++ ) {
        dp.at( 1 ).at( j ) = 1;
    }
    //  DP loop
    for( int i = 2; i <= N; i ++ ) {
        int sum = 0;
        for( int j = 1; j <= M; j ++ ) {
            sum += dp.at( i - 1 ).at( j );
            if( sum >= P ) {
                sum -= P;
            }
        }
        for( int j = 1; j <= M; j ++ ) {
            for( int k = 1; k <= M; k ++ ) {
                dp.at( i ).at( j ) = sum;
                if( nrs::abs( k - j ) < K ) {
                    std::cout << j << " " << k << std::endl;
                    dp.at( i ).at( j ) -= dp.at( i - 1 ).at( k );
                    if( sum < 0 ) {
                        dp.at( i ).at( j ) += P;
                    }
                }
                // if( nrs::abs( k - j ) >= K ) {
                //     dp.at( i ).at( j ) += dp.at( i - 1 ).at( k );
                //     if( dp.at( i ).at( j ) > P ) {
                //         dp.at( i ).at( j ) %= P;
                //     }
                // }
            }
        }
    }
    //  DP find solution
    int answer = 0;
    for( int j = 1; j <= M; j ++ ) {
        answer += dp.at( N ).at( j );
        if( answer > P ) {
            answer %= P;
        }
    }
    std::cout << answer << std::endl;

    std::cerr << dp << std::endl;
    //  Finalize
    return ( 0 );
}
