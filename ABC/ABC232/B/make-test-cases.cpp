/*
    make-test-cases.cpp
    ABC232 Problem B - Caesar Cipher
        https://atcoder.jp/contests/abc232/tasks/abc232_b
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
        const std::string S = "a";
        const std::string T = "a";
        std::cout << S << std::endl;
        std::cout << T << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const std::string S( 100000, 'a' );
        const std::string T( 100000, 'z' );
        std::cout << S << std::endl;
        std::cout << T << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int N = dist( engine );

        std::string S( N, '.' );
        std::string T( N, '.' );
        dist = std::uniform_int_distribution< int >( 0, 25 );
        for( int i = 0; i < N; i ++ ) {
            S.at( i ) = dist( engine ) + 'a';
            T.at( i ) = dist( engine ) + 'a';
        }
        std::cout << S << std::endl;
        std::cout << T << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
