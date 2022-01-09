/*
    make-test-cases.cpp
    ABC234 Problem C - Happy New Year!
        https://atcoder.jp/contests/abc234/tasks/abc234_c
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
        std::cerr << "make-test-cases [1-3]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const long long K = 1LL;
        std::cout << K << std::endl;        
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const long long K = 1000000000000000000LL;
        std::cout << K << std::endl;        
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< long long > dist; 
        dist = std::uniform_int_distribution< long long >( 1, 1000000000000000000LL );
        const long long K = dist( engine );
        std::cout << K << std::endl;        
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
