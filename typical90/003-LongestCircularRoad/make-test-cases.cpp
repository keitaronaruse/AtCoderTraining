/*
    make-test-cases.cpp
    003 - Longest Circular Road（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_c
        Author: Keitaro Naruse
        Date:   2022-01-02, 2021-01-03
        MIT License
*/

#include <iostream>
#include <set>
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
        const int N = 3;
        std::cout << N << std::endl;
        
        for( int i = 0; i < N - 1; i ++ ) {
            const int A = i + 1;
            const int B = i + 2;
            std::cout << A << " " << B << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        std::cout << N << std::endl;
        
        for( int i = 0; i < N - 1; i ++ ) {
            const int A = i + 1;
            const int B = i + 2;
            std::cout << A << " " << B << std::endl;
        }        
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int N = dist( engine );
        std::cout << N << std::endl;
        
        for( int i = 0; i < N - 1; i ++ ) {
            dist = std::uniform_int_distribution< int >( 1, i + 1 );
            const int A = dist( engine );
            const int B = i + 2; 
            std::cout << A << " " << B << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
