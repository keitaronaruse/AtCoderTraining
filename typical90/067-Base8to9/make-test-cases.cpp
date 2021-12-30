/*
    make-test-cases.cpp
    067 - Base 8 to 9（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bo
        Author: Keitaro Naruse
        Date:   2021-12-01, 2021-12-30
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
        const std::string N = "0";
        const int K = 1;
        std::cout << N << " " << K << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const std::string N = "77777777777777777777";
        const int K = 100;
        std::cout << N << " " << K << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 20 );
        const int L = dist( engine );
        std::string N( L, '0' );

        dist = std::uniform_int_distribution< int >( 1, 7 );
        N.at( 0 ) = dist( engine ) + '0';

        dist = std::uniform_int_distribution< int >( 0, 7 );
        for( int i = 1; i < L; i ++ ) {
            N.at( i ) = dist( engine ) + '0';
        }

        dist = std::uniform_int_distribution< int >( 1, 100 );
        const int K = dist( engine );

        std::cout << N << " " << K << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
