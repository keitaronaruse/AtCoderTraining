/*    
* @file make-test-cases.cpp
* @brief make test cases for ABC236 Problem B - Who is missing?
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_b
*/

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist; 
    dist = std::uniform_int_distribution< int >( 1, 100000 );
    const int N  = dist( engine );
    std::cout << N << std::endl;
    
    std::vector< int > A( 4 * N, 0 );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < 4; j ++ ) {
            A.at( 4 * i + j ) = i;
        }
    }

    dist = std::uniform_int_distribution< int >( 0, 4 * N - 1 );
    for( int i = 0; i < N; i ++ ) {
        const int a = dist( engine );
        const int b = dist( engine );
        std::swap( A.at( a ), A.at( b ) );
    }

    for( int i = 0; i < 4 * N - 1; i ++ ) {
        std::cout << A.at( i ) << " ";
    }
    std::cout << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
