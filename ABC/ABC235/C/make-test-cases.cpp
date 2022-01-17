/*
    make-test-cases.cpp
    ABC235 Problem C - The Kth Time Query
        https://atcoder.jp/contests/abc235/tasks/abc235_c
        Author: Keitaro Naruse
        Date:   2022-01-15, 2022-01-17
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
        const int Q = 1;
        std::cout << N << " " << Q << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 0;
            std::cout << A << " ";
        }
        std::cout << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            const int X = 0;
            const int K = j + 1;
            std::cout << X << " " << K << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 200000;
        const int Q = 200000;
        std::cout << N << " " << Q << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 1000000000;
            std::cout << A << " ";
        }
        std::cout << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            const int X = 1000000000;
            const int K = j + 1;
            std::cout << X << " " << K << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 200000 );
        const int N = dist( engine );
        const int Q = dist( engine );
        std::cout << N << " " << Q << std::endl;

        dist = std::uniform_int_distribution< int >( 0, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
            const int A = dist( engine );
            std::cout << A << " ";
        }
        std::cout << std::endl;

        for( int j = 0; j < Q; j ++ ) {
            dist = std::uniform_int_distribution< int >( 0, 1000000000 );
            const int X = dist( engine );
            dist = std::uniform_int_distribution< int >( 1, N );
            const int K = dist( engine );
            std::cout << X << " " << K << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cout << "Normally terminated." << std::endl;
    }
    return( 0 );
}
