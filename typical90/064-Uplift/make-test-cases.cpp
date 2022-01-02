/*
    make-test-cases.cpp
    064 - Uplift（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bl
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-02 
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
            const int L = 1, R = 1, V = 0;
            std::cout << L << " " << R << " " << V << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        const int Q = 100000;
        std::cout << N << " " << Q << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 1000000000;
            std::cout << A << " ";
        }
        std::cout << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            const int L = 1, R = 100000, V = 0;
            std::cout << L << " " << R << " " << V << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int N = dist( engine );
        const int Q = dist( engine );
        std::cout << N << " " << Q << std::endl;

        dist = std::uniform_int_distribution< int >( -1000000000, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
            const int A = dist( engine );
            std::cout << A << " ";
        }
        std::cout << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            dist = std::uniform_int_distribution< int >( 1, N );
            const int a = dist( engine ), b = dist( engine ); 
            const int L = std::min( a, b ), R = std::max( a, b ); 
            dist = std::uniform_int_distribution< int >( -1000000000, 1000000000 );
            const int V = dist( engine );
            std::cout << L << " " << R << " " << V << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
