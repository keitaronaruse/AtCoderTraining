/*
    make-test-cases.cpp
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d
        Author: Keitaro Naruse
        Date:   2021-12-11, 2021-12-14, 2022-01-10
        MIT License1
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
        const int N = 2;
        const int M = 0;
        std::cout << N << " " << M << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        const int M = 100000;
        std::cout << N << " " << M << std::endl;
        for( int i = 0; i < M; i ++ ) {
            const int A = (i + 1) % N + 1;
            const int B = (i + 2) % N + 1;
            std::cout << A << " " << B << std::endl; 
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 2, 100000 );
        const int N = dist( engine );
        dist = std::uniform_int_distribution< int >( 0, 100000 );
        const int M = dist( engine );
        std::cout << N << " " << M << std::endl;

        for( int i = 0; i < M; i ++ ) {
            dist = std::uniform_int_distribution< int >( 1, N );
            const int A = dist( engine );
            const int B = dist( engine );
            std::cout << std::min( A, B ) << " " << std::max( A, B ) << std::endl; 
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
