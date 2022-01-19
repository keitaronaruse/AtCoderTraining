/**
* @file make-test-cases.cpp
* @brief make test cases for 005 - Modulo 100 
* @author Keitaro Naruse
* @date 2022-01-19
* @copyright MIT License
*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    
    //  Make N = [ 1, 50 ]
    std::uniform_int_distribution<> dist( 1, 50 );
    const int N = dist( engine );
    std::cout << N << std::endl;

    //  Make Ai = [ 1, 100 ]
    dist = std::uniform_int_distribution<>( 1, 100 );
    for( int i = 0; i < N; i ++ ) {
        const int A = dist( engine );
        std::cout << A << " ";
    }
    std::cout << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
