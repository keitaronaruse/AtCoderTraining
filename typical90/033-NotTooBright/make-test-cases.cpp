/*
    make-test-cases.cpp
    033 - Not Too Bright
        https://atcoder.jp/contests/typical90/tasks/typical90_ag
        Author: Keitaro Naruse
        Date:   2021-11-28, 2021-12-29
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

    //  Minimum-minimum case
    if( argv[1][0] == '1' ) {
        const int H = 1;
        const int W = 1;
        std::cout << H << " " << W << std::endl;        
    }
    //  Minimum-maximum case
    else if( argv[1][0] == '2' ) {
        const int H = 1;
        const int W = 100;
        std::cout << H << " " << W << std::endl;        
    }
    //  Maximum-minimum case
    else if( argv[1][0] == '3' ) {
        const int H = 100;
        const int W = 1;
        std::cout << H << " " << W << std::endl;        
    }
    //  Maximum-maximum case
    else if( argv[1][0] == '4' ) {
        const int H = 100;
        const int W = 100;
        std::cout << H << " " << W << std::endl;        
    }
    //  Random case
    else if( argv[1][0] == '5' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100 );
        const int H = dist( engine );
        const int W = dist( engine );
        std::cout << H << " " << W << std::endl;        
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
