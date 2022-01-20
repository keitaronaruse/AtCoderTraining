/**
* @file make-test-cases.cpp
* @brief make test cases for C - Vacation
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist;
    
    //  Make N = [ 1, 10^5 ]
    dist = std::uniform_int_distribution< int >( 1, 100000 );
    const int N = dist( engine ); 
    std::cout << N << std::endl;

    //  Make Ai, Bi, Ci = [ 1, 10^4 ]
    dist = std::uniform_int_distribution< int >( 1, 10000 );
    for( int i = 0; i < N; i ++ ) {
        const int A = dist( engine ); 
        const int B = dist( engine ); 
        const int C = dist( engine ); 
        std::cout << A << " " << B << " "<< C << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
