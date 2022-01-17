/*
    make-test-cases.cpp
        ABC235 Problem D - Multiply and Rotate
        https://atcoder.jp/contests/abc235/tasks/abc235_d
        Author: Keitaro Naruse
        Date:   2022-01-15, 2022-01-17
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
        const int a = 2;
        const int N = 2;
        std::cout << a << " " << N << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int a = 999999;
        const int N = 999999;
        std::cout << a << " " << N << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 2, 999999 );
        const int a = dist( engine );
        const int N = dist( engine );
        std::cout << a << " " << N << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
