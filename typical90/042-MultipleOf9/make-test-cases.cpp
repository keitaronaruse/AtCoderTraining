/*
    make-test-cases.cpp
    042 - Multiple of 9（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ap
        Author: Keitaro Naruse
        Date:   2022-01-11, 2022-01-12
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
        const int K = 1;
        std::cout << K << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int K = 100000;
        std::cout << K << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int K = dist( engine );
        std::cout << K << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
