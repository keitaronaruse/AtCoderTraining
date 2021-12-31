/*
    make-test-cases.cpp
    078 - Easy Graph Problem（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_bz
        Author: Keitaro Naruse
        Date:   2021-12-02, 2021-12-31
        MIT License
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
        const int M = 1;
        std::cout << N << " " << M << std::endl;
        
        const int a = 1, b = 2;
        std::cout << a << " " << b << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        const int M = 100000;
        std::cout << N << " " << M << std::endl;
        
        for( int i = 0; i < M; i ++ ) {
            const int a = i % N + 1, b = ( i + 1 ) % N + 1;
            std::cout << a << " " << b << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int N = dist( engine );

        const long long edges = ( long long ) N * ( long long )( N - 1 ) / 2LL;
        //  Small graph, full connection
        if( edges < 100000LL ) {
            const int M = ( int ) edges;
            std::cout << N << " " << M << std::endl;
            
            for( int i = 0; i < N; i ++ ) {
                for( int j = i + 1; j < N; j ++ ) {
                    std::cout << i + 1 << " " << j + 1 << std::endl;
                }
            }
        }
        //  Larage graph, random connection
        else {
            const int M = 100000;
            std::cout << N << " " << M << std::endl;

            dist = std::uniform_int_distribution< int >( 1, N );
            for( int i = 0; i < M; i ++ ) {
                int b = dist( engine );
                int e = dist( engine );
                std::cout << b << " " << e << std::endl;
            }
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
