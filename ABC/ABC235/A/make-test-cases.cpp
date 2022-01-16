/*
    make-test-cases.cpp
    ABC235 Problem A - Rotate
        https://atcoder.jp/contests/abc235/tasks/abc235_a
        Author: Keitaro Naruse
        Date:   2022-01-15
        MIT License
*/

#include <iostream>
#include <random>

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
        const int abc = 111;
        std::cout << abc << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int abc = 999;
        std::cout << abc << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 9 );
        const int abc  = 100 * dist( engine ) + 10 * dist( engine ) + 1 * dist( engine );
        std::cout << abc << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
