/**
* @file D-Knapsack1.cpp
* @brief D - Knapsack 1
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 10^2 ] and W = [ 1, 10^5 ]
    int N = 0, W = 0;
    std::cin >> N >> W;
    if( Debug ) {
        std::cerr << N << " " << W << std::endl;
    }

    //  Read Wi = [ 1, W ] and Vi = [ 1, 10^9 ]
    std::vector< int > w( N, 0 ), v( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> w.at( i ) >> v.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << w.at( i ) << " " << v.at( i ) << std::endl;
        }
    }

    //  Main
    //  Main::Initialize
    //  dp table: 
    //  - size: N * W = 10^2 * 10^5 = 10^7
    //  - value: V * W = 10^9 * 10^5 = 10^14 -> long long
    std::vector< std::vector< long long > > dp_value( N + 1, std::vector< long long >( W + 1, 0LL ) ); 

    //  Initial boundary condition
    for( int k = 0; k <= W; k ++ ) {
        int i = 0;
        if( k - w.at( i ) >= 0 ) {
            dp_value.at( i ).at( k ) = ( long long ) v.at( i );
        }
    }
    
    //  Main::Loop
    for( int i = 1; i < N; i ++ ) {
        for( int k = 0; k <= W; k ++ ) {
            dp_value.at( i ).at( k ) = dp_value.at( i - 1 ).at( k );
            if( k - w.at( i ) >= 0 ) {
                dp_value.at( i ).at( k ) = std::max(
                    dp_value.at( i - 1 ).at( k ), 
                    dp_value.at( i - 1 ).at( k - w.at( i ) ) + ( long long ) v.at( i )
                );
            }
        }
    }

    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            for( int k = 0; k <= W; k ++ ) {
                std::cerr << dp_value.at( i ).at( k ) << " ";
            }
            std::cerr << std::endl;
        }
    }
    //  Main::Finalize
    //  Display the result
    std::cout << dp_value.at( N - 1 ).at( W ) <<  std::endl;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
