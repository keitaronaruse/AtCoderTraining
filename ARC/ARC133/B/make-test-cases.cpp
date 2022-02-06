/*    
* @file make-test-cases.cpp
* @brief make test cases for ARC133 Problem B - Dividing Subsequence
* @author Keitaro Naruse
* @date 2022-02-03
* @copyright MIT License
* @details https://atcoder.jp/contests/arc134/tasks/arc133_b
*/

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist; 
    dist = std::uniform_int_distribution< int >( 1, 200000 );
    const int N  = dist( engine );
    std::cout << N << std::endl;

    std::vector< int > P( N, 0 ), Q( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        P.at( i ) = Q.at( i ) = i + 1;
    }
    dist = std::uniform_int_distribution< int >( 0, N - 1 );
    for( int i = 0; i < N; i ++ ) {
        const int a = dist( engine );
        const int b = dist( engine );
        std::swap( P.at( a ), P.at( b ) ); 
        const int c = dist( engine );
        const int d = dist( engine );
        std::swap( Q.at( c ), Q.at( d ) ); 
    }
    for( int i = 0; i < N; i ++ ) {
        std::cout << P.at( i ) << " ";
    }
    std::cout << std::endl;
    for( int i = 0; i < N; i ++ ) {
        std::cout << Q.at( i ) << " ";
    }
    std::cout << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
