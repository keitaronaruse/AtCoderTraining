/*
    make-test-cases.cpp
    044 - Shift and Swapping（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ar
        Author: Keitaro Naruse
        Date:   2021-12-11, 2022-01-01
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
        const int Q = 1;
        std::cout << N << " " << Q << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 1;
            std::cout << A << " ";
        }
        std::cout << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            const int T = 1;
            const int X = 1;
            const int Y = 2;
            std::cout << T << " " << X << " " << Y << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 200000;
        const int Q = 200000;
        std::cout << N << " " << Q << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = i + 1;
            std::cout << A << " ";
        }
        std::cout << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            const int T = j % 3 + 1;
            int X = 0, Y = 0;
            if( T == 1 ) {
                X = N - 1;
                Y = N;
            }
            else if( T == 2 ) {
                X = 0;
                Y = 0;
            }
            else if( T == 3 ) {
                X = N;
                Y = 0;
            }
            std::cout << T << " " << X << " " << Y << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 2, 200000 );
        const int N = dist( engine );
        dist = std::uniform_int_distribution< int >( 1, 200000 );
        const int Q = dist( engine );
        std::cout << N << " " << Q << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
            const int A = dist( engine );
            std::cout << A << " ";
        }
        std::cout << std::endl;

        for( int j = 0; j < Q; j ++ ) {
            dist = std::uniform_int_distribution< int >( 1, 3 );
            const int T = dist( engine );
            int X = 0, Y = 0;

            if( T == 1 ) {
                dist = std::uniform_int_distribution< int >( 1, N );
                X = dist( engine );
                do {
                    Y = dist( engine );
                } while( X == Y );
            }
            else if( T == 2 ) {
                X = 0;
                Y = 0;
            }
            else if( T == 3 ) {
                dist = std::uniform_int_distribution< int >( 1, N );
                X = dist( engine );
                Y = 0;
            }
            std::cout << T << " " << X << " " << Y << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
