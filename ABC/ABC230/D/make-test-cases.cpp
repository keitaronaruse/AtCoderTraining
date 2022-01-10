/*
    make-test-cases.cpp
    ABC230 Problem D - Destroyer Takahashi
        https://atcoder.jp/contests/abc230/tasks/abc230_d
        Author: Keitaro Naruse
        Date:   2022-01-10
        MIT License
*/

#include <iostream>
#include <random>
#include <algorithm>

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
        const int N = 1;
        const int D = 1;
        std::cout << N << " " << D << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int L = 1, R = 1;
            std::cout << L << " " << R << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 200000;
        const int D = 1000000000;
        std::cout << N << " " << D << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int L = 1, R = 1000000000;
            std::cout << L << " " << R << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 200000 );
        const int N = dist( engine );

        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        const int D = dist( engine );

        std::cout << N << " " << D << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
            const int L = dist( engine ), R = dist( engine );
            std::cout << std::min( L, R ) << " " << std::max( L, R ) << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
