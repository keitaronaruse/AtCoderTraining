/*
    make-test-cases.cpp
    ABC232 Problem D - Weak Takahashi
        https://atcoder.jp/contests/abc232/tasks/abc232_d
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-11
        MIT License
*/

#include <iostream>
#include <algorithm>
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
        const int H = 1;
        const int W = 1;
        std::cout << H << " " << W << std::endl;
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                std::cout << '.';
            }
            std::cout << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int H = 100;
        const int W = 100;
        std::cout << H << " " << W << std::endl;
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                std::cout << '.';
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
        const int H = dist( engine );
        const int W = dist( engine );
        std::cout << H << " " << W << std::endl;

        dist = std::uniform_int_distribution< int >( 0, 1 );
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                char c = '#';
                if( h == 0 && w == 0 ) {
                    c = '.';
                }
                else  {
                    if( dist(engine) == 0 ) {
                        c = '.';
                    }
                    else {
                        c = '#';
                    }
                }
                std::cout << c;
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
