/*
    make-test-cases.cpp
    004 - Cross Sum（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_d
        Author: Keitaro Naruse
        Date:   2021-11-25, 2021-12-27
        MIT License
*/

#include <iostream>
#include <vector>
#include <random>

//  Debug flag
const bool Debug = false;

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        std::cerr << "make-test-cases [1-3]" << std::endl;
        return( -1 );
    }

    int H = 0, W = 0; 
    //  Minimum case
    if( argv[1][0] == '1' ) {
        H = 2; 
        W = 2;
        std::cout << H << " " << W << std::endl;
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                std::cout << "1 ";
            }
            std::cout << std::endl;
        }

    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        H = 2000; 
        W = 2000;
        std::cout << H << " " << W << std::endl;
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                std::cout << "99 ";
            }
            std::cout << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 2, 2000 );
        H = dist( engine ); 
        W = dist( engine );
        std::cout << H << " " << W << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 99 );
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
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
