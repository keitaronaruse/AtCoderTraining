/*
    make-test-cases.cpp
    038 - Large LCM
        https://atcoder.jp/contests/typical90/tasks/typical90_al
        Author: Keitaro Naruse
        Date:   2021-12-10, 2022-01-01
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
        const int N = 1;
        std::cout << N << std::endl;
        const int A = 1;
        std::cout << A << std::endl;
        const int M = 0;
        std::cout << M << std::endl;        
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 10;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            for( int j = 0; j < N; j ++ ) {
                const int A = 1000;
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }
        const int M = N * ( N - 1 ) / 2;
        std::cout << M << std::endl;        
        for( int i = 0; i < N; i ++ ) {
            for( int j = i + 1; j < N; j ++ ) {
                std::cout << i + 1 << " " << j + 1 << std::endl;
            }
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 1, 10 );
        const int N = dist( engine );
        std::cout << N << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 1000 );
        for( int i = 0; i < N; i ++ ) {
            for( int j = 0; j < N; j ++ ) {
                const int A = dist( engine );
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }

        dist = std::uniform_int_distribution< int >( 0, N * ( N - 1 ) / 2 );
        const int M = dist( engine );
        dist = std::uniform_int_distribution< int >( 1, N );
        std::cout << M << std::endl;        
        for( int i = 0; i < M; i ++ ) {
            std::cout << dist( engine ) << " " << dist( engine ) << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
