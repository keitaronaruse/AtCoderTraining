/*
    make-test-cases.cpp
    079 - Two by Two（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ca
        Author: Keitaro Naruse
        Date:   2021-12-24, 2022-01-03
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
        const int H = 2, W = 2;
        std::cout << H << " " << W << std::endl;
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                const int A = 0;
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                const int B = 0;
                std::cout << B << " ";
            }
            std::cout << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int H = 100, W = 100;
        std::cout << H << " " << W << std::endl;
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                const int A = 100000;
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                const int B = 0;
                std::cout << B << " ";
            }
            std::cout << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist( 2, 100 ); 
        const int H = dist( engine ), W = dist( engine );
        std::cout << H << " " << W << std::endl;

        dist = std::uniform_int_distribution< int > ( 0, 100000 ); 
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                const int A = dist( engine );
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }

        dist = std::uniform_int_distribution< int > ( 0, 100000 ); 
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                const int B = dist( engine );
                std::cout << B << " ";
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
