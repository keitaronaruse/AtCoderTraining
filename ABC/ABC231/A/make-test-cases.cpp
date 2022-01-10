/*
    make-test-cases.cpp
    ABC231 Problem A - Water Pressure
        https://atcoder.jp/contests/abc231/tasks/abc231_a        
        Author: Keitaro Naruse
        Date:   2022-01-10
        MIT License
*/

#include <iostream>
#include <random>
#include <algorithm>

//  Debug flag
const bool Debug = false;

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        std::cerr << "make-test-cases [1-3]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const int D = 1;
        std::cout << D << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int D = 10000;
        std::cout << D << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 10000 );
        const int D = dist( engine );
        std::cout << D << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
