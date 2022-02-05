/**
* @file I-Coins.cpp
* @brief I - Coins
* @author Keitaro Naruse
* @date 2022-02-05
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = true;

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

    //  Display the result
    std::cout << dp_prob.at( N ).at( N ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
