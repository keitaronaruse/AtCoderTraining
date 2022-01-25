/*    
* @file make-test-cases.cpp
* @brief make test cases for ABC236 Problem C - Route Map
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_c
*/

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist; 
    dist = std::uniform_int_distribution< int >( 2, 100000 );
    const int N  = dist( engine );
    
    std::vector< std::string > S( N );
    for( int i = 0; i < N; i ++ ) {
        dist = std::uniform_int_distribution< int >( 1, 10 );
        const int M = dist( engine );
        S.at( i ) = std::string( M, ' ' );
        dist = std::uniform_int_distribution< int >( 'a', 'z' );
        for( int j = 0; j < M; j ++ ) {
            S.at( i ).at( j ) = dist( engine );
        }
    }

    dist = std::uniform_int_distribution< int >( 2, N );
    const int K = dist( engine );

    std::vector< bool > express( N, true );
    dist = std::uniform_int_distribution< int >( 1, N - 2 );
    for( int k = 0; k < K; k ++ ) {
        express.at( dist( engine ) ) = false;
    }
    
    int M = 0;
    for( int i = 0; i < N; i ++ ) {
        if( express.at( i ) ) {
            M ++;
        }
    }

    std::cout << N << " " << M << std::endl;
    for( int i = 0; i < N; i ++ ) {
        std::cout << S.at( i ) << " ";
    }
    std::cout << std::endl;
    
    for( int i = 0; i < N; i ++ ) {
        if( express.at( i ) ) {
            std::cout << S.at( i ) << " ";
        }
    }
    std::cout << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
