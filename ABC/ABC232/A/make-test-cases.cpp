/*
    make-test-cases.cpp
    ABC232 Problem A - QQ solver
        https://atcoder.jp/contests/abc232/tasks/abc232_a
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-10
        MIT License
*/

#include <iostream>
#include <string>
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
        const std::string S = "1x1";
        std::cout << S << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const std::string S = "9x9";
        std::cout << S << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 9 );
        const int A = dist( engine );
        const int B = dist( engine );
        const std::string S = std::to_string( A ) + std::string( "x" ) + std::to_string( B ); 
        std::cout << S << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
