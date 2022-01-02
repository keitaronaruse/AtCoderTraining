/*
    make-test-cases.cpp
    052 - Dice Product（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_az
        Author: Keitaro Naruse
        Date:   2021-12-18, 2022-01-02
        MIT License
*/

#include <iostream>
#include <random>

//  Debug flag
const bool Debug = false;

int main( int argc, char* argv[] )
{
    const int M = 6;

    if( argc != 2 ) {
        std::cerr << "make-test-cases [1-3]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const int N = 1;
        std::cout << N << std::endl;
        for( int j = 0; j < M; j ++ ) {
            std::cout << j + 1 << " ";
        }
        std::cout << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            for( int j = 0; j < M; j ++ ) {
                std::cout << 95 + j << " ";
            }
            std::cout << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 1, 100 );
        const int N = dist( engine );
        std::cout << N << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 100 );
        for( int i = 0; i < N; i ++ ) {
            for( int j = 0; j < M; j ++ ) {
                std::cout << dist( engine ) << " ";
            }
            std::cout << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
