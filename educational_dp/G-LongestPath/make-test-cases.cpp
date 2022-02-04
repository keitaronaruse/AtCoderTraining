/**
* @file make-test-cases.cpp
* @brief make test cases for G - Longest Path
* @author Keitaro Naruse
* @date 2022-01-23, 2022-02-05
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_g

*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist;
    
    //  Make N = [ 2, 100000 ]
    dist = std::uniform_int_distribution< int >( 2, 100000 );
    const int N = dist( engine ); 
    //  Make M = [ 1, 100000 ]
    dist = std::uniform_int_distribution< int >( 1, N );
    const int M = dist( engine ); 
    std::cout << N << " " << M << std::endl;

    for( int i = 1; i <= M; i ++ ) {
        dist = std::uniform_int_distribution< int >( i + 1, N );
        std::cout << i << " " << dist( engine ) << std::endl;;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
