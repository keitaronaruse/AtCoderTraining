/*
    make-test-cases.cpp
    ABC233 Problem D
        https://atcoder.jp/contests/abc233
        Author: Keitaro Naruse
        Date:   2021-12-25, 2022-01-11
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
        const long long  K = 0LL;
        std::cout << N << " " << K << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 0;
            std::cout << A << " ";
        }
        std::cout << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 200000;
        const long long K = 1000000000000000LL;
        std::cout << N << " " << K << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 1000000000;
            std::cout << A << " ";
        }
        std::cout << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 200000 );
        const int N = dist( engine );
        std::uniform_int_distribution< long long > dist_ll( 1, 1000000000000000LL ); 
        const long long K = dist_ll( engine );
        std::cout << N << " " << K << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
            const int A = dist( engine );
            std::cout << A << " ";
        }
        std::cout << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
