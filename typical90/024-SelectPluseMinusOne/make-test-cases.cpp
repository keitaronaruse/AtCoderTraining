/*
    make-test-cases.cpp
    024 - Select +／- One（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_x
        Author: Keitaro Naruse
        Date:   2021-11-27, 2021-12-28
        MIT License
*/

#include <iostream>
#include <vector>
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

    int N = 0, K = 0;

    //  Minimum case
    if( argv[1][0] == '1' ) {
        N = 1; 
        K = 1; 
        std::cout << N << " " << K << std::endl;
        std::cout << "1" << std::endl;
        std::cout << "1" << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        N = 1000; 
        K = 1000000000; 
        std::cout << N << " " << K << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 1;
            std::cout << A << " ";
        }
        std::cout << std::endl;

        for( int i = 0; i < N; i ++ ) {
            const int B = 1000000;
            std::cout << B << " ";
        }
        std::cout << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 1000 );
        N = dist( engine ); 
        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        K = dist( engine ); 
        std::cout << N << " " << K << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 1000000 );
        for( int i = 0; i < N; i ++ ) {
            int A = dist( engine );
            std::cout << A << " ";
        }
        std::cout << std::endl;

        for( int i = 0; i < N; i ++ ) {
            int B = dist( engine );
            std::cout << B << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
