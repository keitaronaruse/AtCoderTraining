/**
* @file make-test-cases.cpp
* @brief make test cases for 009 - Brute Force 2
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    
    //  Make N = [ 1, 60 ]
    std::uniform_int_distribution<> dist( 1, 60 );
    const int N = dist( engine );
    //  Make S = [ 1, 10000 ]
    dist = std::uniform_int_distribution<>( 1, 10000 );
    const int S = dist( engine );
    std::cout << N << " " << S << std::endl;

    //  Make Ai = [ 1, 10000 ]
    dist = std::uniform_int_distribution<>( 1, 10000 );
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
