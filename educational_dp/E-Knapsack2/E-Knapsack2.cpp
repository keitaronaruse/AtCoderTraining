/**
* @file E-Knapsack2.cpp
* @brief E - Knapsack 2
* @author Keitaro Naruse
* @date 2022-01-21
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_e
*/

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false; 
const long long Inf = 1000000000000000000LL;

int main()
{
    //  Read N = [ 1, 10^2 ] and W = [ 1, 10^9 ]
    int N = 0, W = 0;
    std::cin >> N >> W;
    if( Debug ) {
        std::cerr << N << " " << W << std::endl;
    }

    //  Read Wi = [ 1, W ] and Vi = [ 1, 10^3 ]
    int V = 0;
    std::vector< int > w( N, 0 ), v( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> w.at( i ) >> v.at( i );
        V += v.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << w.at( i ) << " " << v.at( i ) << std::endl;
        }
    }

    //  Main
    //  DP principle: maximize the sum of weights undet the sum of values
    //  DP table: 
    //  - size: N * V = 10^2 * ( 10^2 * 10^3 ) = 10^7
    //  - value: N * W = 10^2 * 10^9 = 10^11 -> long long

    //  Main::Initialize
    //  DP table: 
    std::vector< std::vector< long long > >  
        dp_weight( N + 1, std::vector< long long >( V + 1, Inf ) ); 
    //  DP Initial condition
    dp_weight.at( 0 ).at( 0 ) = 0;

    //  Main::Loop
    for( int i = 1; i <= N; i ++ ) {
        for( int k = 0; k <= V; k ++ ) {
            //  If we do not take the item i
            dp_weight.at( i ).at( k ) = dp_weight.at( i - 1 ).at( k );
            //  If we take the item i
            if( k - v.at( i - 1 ) >= 0 ) {
                dp_weight.at( i ).at( k ) = std::min(
                    dp_weight.at( i ).at( k ), 
                    dp_weight.at( i - 1 ).at( k - v.at( i - 1 ) ) 
                        + ( long long ) w.at( i - 1 )
                );
            }
        }
    }
    if( Debug ) {
        for( int i = 0; i <= N; i ++ ) {
            for( int k = 0; k <= V; k ++ ) {
                if( dp_weight.at( i ).at( k ) == Inf ) {
                    std::cerr << "*" << " ";
                }
                else {
                    std::cerr << dp_weight.at( i ).at( k ) << " ";
                }
            }
            std::cerr << std::endl;
        }
    }
    //  Main::Finalize
    int max_value = 0;
    for( int k = 0; k <= V; k ++ ) {
        if( dp_weight.at( N ).at( k ) != -1 
            && dp_weight.at( N ).at( k ) <= W ) {
            max_value = k;
        }
    }
    //  Display the result
    std::cout << max_value << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
