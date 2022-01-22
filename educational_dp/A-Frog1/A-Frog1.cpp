/**
* @file A-Frog1.cpp
* @brief A - Frog 1
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_a
*/

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

const bool Debug = false; 

int main()
{
    //  Read N = [ 2, 100,000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read Hi = [ 1, 10,000 ]
    std::vector< int > h( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> h.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << h.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Main::Initialize
    //  dp table: 
    //  - size: N
    //  - value: N * h = 10^5 * 10^4 = 10^9 -> int 
    //  - dp_cost.at( i ) is the minimum of 
    //    - dp_cost.at( i - 1 ) + cost( i, i - 1 ), or
    //    - dp_cost.at( i - 2 ) + cost( i, i - 2 ) 
    std::vector< int > dp_cost( N + 1, 0 );
    
    //  DP Initialize
    dp_cost.at( 1 ) = 0;
    dp_cost.at( 2 ) = dp_cost.at( 1 ) + nrs::abs( h.at( 1 ) - h.at( 0 ) );
    //  DP Main
    for( int i = 3; i <= N; i ++ ) {
        dp_cost.at( i ) = std::min(
            dp_cost.at( i - 1 ) + nrs::abs( h.at( i - 1 ) - h.at( i - 2 ) ),
            dp_cost.at( i - 2 ) + nrs::abs( h.at( i - 1 ) - h.at( i - 3 ) )
        );
    }
    //  Main Finalize
    //  Display the result
    std::cout << dp_cost.at( N ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
