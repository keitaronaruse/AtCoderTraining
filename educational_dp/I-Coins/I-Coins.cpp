/**
* @file I-Coins.cpp
* @brief I - Coins
* @author Keitaro Naruse
* @date 2022-02-05
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read N = [ 1, 2999 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read pi = [ 0, 1.0 ]
    std::vector< double > p( N, 0.0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> p.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << p.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    std::vector< std::vector< double > > dp_prob( N + 1, std::vector< double >( N + 1, 0.0 ) );
    dp_prob.at( 0 ).at( 0 ) = 1.0;
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            dp_prob.at( i + 1 ).at( j ) += dp_prob.at( i ).at( j ) * ( 1.0 - p.at( i ) );
            dp_prob.at( i + 1 ).at( j + 1 ) += dp_prob.at( i ).at( j ) * p.at( i );
        }
    }
    if( Debug ) {
        for( int i = 0; i <= N; i ++ ) {
            for( int j = 0; j <= N; j ++ ) {
                std::cerr << dp_prob.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }
    //  Find the solution
    double prob = 0.0;
    for( int j = N / 2 + 1; j <= N; j ++ ) {
        prob += dp_prob.at( N ).at( j );
    }
    //  Display the result
    std::cout << std::fixed << std::setprecision(10) << prob << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
