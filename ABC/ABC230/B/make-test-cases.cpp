/*
    make-test-cases.cpp
    ABC230 Problem B - Triple Metre
        https://atcoder.jp/contests/abc230/tasks/abc230_b
        Author: Keitaro Naruse
        Date:   2021-12-03, 2022-01-09
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
        std::cerr << "make-test-cases [1-5]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const std::string S = "o";
        std::cout << S << std::endl;
    }
    //  Minimum case
    else if( argv[1][0] == '2' ) {
        const std::string S = "x";
        std::cout << S << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '3' ) {
        const std::string S = "oxxoxxoxxo";
        std::cout << S << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '4' ) {
        const std::string S = "xooxooxoox";
        std::cout << S << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '5' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 10 );
        const int N = dist( engine );

        std::string S;
        dist = std::uniform_int_distribution< int >( 0, 1 );
        for( int i = 0; i < N; i ++ ) {
            if( dist( engine ) == 0 ) {
                S += "o";
            }
            else {
                S += "x";
            }
        }
        std::cout << S << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
