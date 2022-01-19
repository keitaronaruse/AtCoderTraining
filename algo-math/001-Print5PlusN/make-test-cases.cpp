/**
* @file make-test-cases.cpp
* @brief Test case generator for 001 - Print 5+N
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
    
    //  Make N = [ 1, 100 ]
    std::uniform_int_distribution< > dist( 1, 100 );
    int N = dist( engine ); 
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Display the result
    std::cout << N << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
