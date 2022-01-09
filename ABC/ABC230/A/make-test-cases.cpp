/*
    make-test-cases.cpp
    ABC230 Problem A - AtCoder Quiz 3
        https://atcoder.jp/contests/abc230/tasks/abc230_a
        Author: Keitaro Naruse
        Date:   2022-01-09
        MIT License
*/

#include <iostream>
#include <random>

//  Debug flag
const bool Debug = false;

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        std::cerr << "make-test-cases [1-5]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const int N = 1;
        std::cout << N << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 54;
        std::cout << N << std::endl;
    }
    //  Small boundary case
    else if( argv[1][0] == '3' ) {
        const int N = 41;
        std::cout << N << std::endl;
    }
    //  Large boundary case
    else if( argv[1][0] == '4' ) {
        const int N = 42;
        std::cout << N << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '5' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 54 );
        const int N = dist( engine );
        std::cout << N << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
