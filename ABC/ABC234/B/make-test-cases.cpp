/*
    make-test-cases.cpp
    ABC234 Problem B - Longest Segment
        https://atcoder.jp/contests/abc234/tasks/abc234_b
        Author: Keitaro Naruse
        Date:   2022-01-09
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
            const int x = 0, y = 0;
            std::cout << x << " " << y << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            int x = 0, y = 0;
            switch( i % 4 ) {
                case 0: x =  1000; y =  1000; break;
                case 1: x = -1000; y =  1000; break;
                case 2: x = -1000; y = -1000; break;
                case 3: x =  1000; y = -1000; break;
                default: break;
            } 
            std::cout << x << " " << y << std::endl;
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

        dist = std::uniform_int_distribution< int >( -1000, 1000 );
        for( int i = 0; i < N; i ++ ) {
            const int x = dist( engine ), y = dist( engine );
            std::cout << x << " " << y << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
