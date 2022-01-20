/**
* @file make-test-cases.cpp
* @brief 006 - Print 2N+3
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
    
    //  Make N = [ 1, 50 ]
    std::uniform_int_distribution<> dist( 1, 100 );
    const int N = dist( engine );
    std::cout << N << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
