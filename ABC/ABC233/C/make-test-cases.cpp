/*
    make-test-cases.cpp
    ABC233 Problem C - Product
        https://atcoder.jp/contests/abc233/tasks/abc233_c
        Author: Keitaro Naruse
        Date:   2021-12-25, 2022-01-11
        MIT License
*/

#include <iostream>
#include <string>
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
        const int N = 2;
        const int X = 1;
        std::cout << N << " " << X << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int L = 2;
            std::cout << L << " ";
            for( int j = 0; j < L; j ++ ) {
                const int A = 1;
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 5;
        const long long X = 1000000000000000000LL;
        std::cout << N << " " << X << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int L = 10;
            std::cout << L << " ";
            for( int j = 0; j < L; j ++ ) {
                const int A = 1000000000;
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 2, 10 );

        const int N = dist( engine );
        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        const int X = dist( engine );
        std::cout << N << " " << X << std::endl;
        for( int i = 0; i < N; i ++ ) {
            dist = std::uniform_int_distribution< int >( 2, 10 );
            const int L = dist( engine );
            std::cout << L << " ";
            for( int j = 0; j < L; j ++ ) {
                dist = std::uniform_int_distribution< int >( 1, 1000000000 );
                const int A = dist( engine );
                std::cout << A << " ";
            }
            std::cout << std::endl;
        }
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
