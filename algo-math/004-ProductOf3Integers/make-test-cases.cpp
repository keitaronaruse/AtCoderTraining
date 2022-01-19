/**
* @file 004-ProductOf3Integers.cpp
* @brief 004 - Product of 3 Integers
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
    
    //  Make A1, A2, A3 = [ 1, 100 ]
    std::uniform_int_distribution< > dist( 1, 100 );
    const int A1 = dist( engine );
    const int A2 = dist( engine );
    const int A3 = dist( engine ); 

    //  Display the result
    std::cout << A1 << " " << A2 << " " <<  A3 << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
