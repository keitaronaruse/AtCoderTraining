/**
* @file B-Frog2.cpp
* @brief B - Frog 2
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_b
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
    //  Read N = [ 2, 100,000 ] and K = [ 1, 100 ]
    int N = 0, K = 0;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }

    //  Read hi = [ 1, 10,000 ]
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
    //    - dp_cost.at( i - 2 ) + cost( i, i - 2 ), or
    //    - ...
    //    - dp_cost.at( i - K ) + cost( i, i - K )
    std::vector< int > dp_cost( N + 1, -1 );
    
    //  Initail boundary condition
    //  The frog is at the stone 1 with 0 cost
    dp_cost.at( 1 ) = 0;
    //  Main::Loop
    for( int i = 2; i <= N; i ++ ) {
        dp_cost.at( i ) = dp_cost.at( i - 1 ) + nrs::abs( h.at( i - 1 ) - h.at( i - 2 ) );
        for( int j = 2; j <= K; j ++ ) {
            if( i - j - 1 >= 0 ) {
                dp_cost.at( i ) = std::min(
                    dp_cost.at( i ),
                    dp_cost.at( i - j ) + nrs::abs( h.at( i - 1 ) - h.at( i - j - 1 ) )
                );
            }
        }
    }
    if( Debug ) {
        for( int i = 0; i <= N; i ++ ) {
            std::cerr << dp_cost.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    //  Main::Finalize
    //  Display the result
    std::cout << dp_cost.at( N ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
