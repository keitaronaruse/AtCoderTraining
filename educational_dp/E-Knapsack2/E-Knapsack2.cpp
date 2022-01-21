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

const bool Debug = true; 

int main()
{
    //  Constant: V = [1, 10^3]
    const int V = 1000;

    //  Read N = [ 1, 10^2 ] and W = [ 1, 10^9 ]
    int N = 0, W = 0;
    std::cin >> N >> W;
    if( Debug ) {
        std::cerr << N << " " << W << std::endl;
    }

    //  Read Wi = [ 1, W ] and Vi = [ 1, 10^3 ]
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
    //  DP principle
    //  - minimize the weight for each of the summed value
    //  DP table: 
    //  - size: N * (N * V ) = 10^2 * ( 10^2 * 10^3 ) = 10^7
    //  - value: N * W = 10^2 * 10^9 = 10^11 -> long long
    const int K = N * ( N * V ); 
    std::vector< std::vector< long long > >  
        dp_weight( N, std::vector< long long >( K + 1, 0LL ) ); 

    //  Initial boundary condition
    for( int k = 0; k <= K; k ++ ) {
        int i = 0;
        if( k - v.at( i ) >= 0 ) {
            dp_weight.at( i ).at( k ) = ( long long ) v.at( i );
        }
    }
    
    //  Main::Loop

    //  Main::Finalize
    //  Display the result
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
