/*
    make-test-cases.cpp
    ABC232 Problem C - Graph Isomorphism
        https://atcoder.jp/contests/abc232/tasks/abc232_c
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-10
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
        const int N = 1;
        const int M = 0;
        std::cout << N << " " << M << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 8;
        const int M = N * (N - 1) / 2;
        std::cout << N << " " << M << std::endl;
        for( int a = 1; a <= N; a ++ ) {
            for( int b = a + 1; b <= N; b ++ ) {
                std::cout << a  << " " << b << std::endl;
            }
        }
        for( int c = 1; c <= N; c ++ ) {
            for( int d = c + 1; d <= N; d ++ ) {
                std::cout << c  << " " << d << std::endl;
            }
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 8 );
        const int N = dist( engine );

        dist = std::uniform_int_distribution< int >( 1, N * ( N - 1 ) / 2 );
        const int M = dist( engine );
        std::cout << N << " " << M << std::endl;

        dist = std::uniform_int_distribution< int >( 1, N );
        for( int i = 0; i < M; i ++ ) {
            const int A = dist( engine );
            const int B = dist( engine );
            std::cout << std::min( A, B )  << " " << std::max( A, B ) << std::endl;
        }

        for( int i = 0; i < M; i ++ ) {
            const int C = dist( engine );
            const int D = dist( engine );
            std::cout << std::min( C, D )  << " " << std::max( C, D ) << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
