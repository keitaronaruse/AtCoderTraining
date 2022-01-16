/*
    make-test-cases.cpp
    ABC235 Problem B - Climbing Takahashi
        https://atcoder.jp/contests/abc235/tasks/abc235_b
        Author: Keitaro Naruse
        Date:   2022-01-15
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
        const int N = 2;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int H = 1;
            std::cout << H << " ";
        }
        std::cout << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int H = 1000000000;
            std::cout << H << " ";
        }
        std::cout << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 2, 100000 );
        const int N = dist( engine );
        std::cout << N << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
            const int H = dist( engine );
            std::cout << H << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
