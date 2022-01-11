/*
    make-test-cases.cpp
    ABC233 Problem B - A Reverse
        https://atcoder.jp/contests/abc233/tasks/abc233_b
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
        const int L = 1;
        const int R = 1;
        std::cout << L << " " << R << std::endl;

        const std::string S = "a";
        std::cout << S << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int M = 26;
        const int N = 100000;
        const int L = 1;
        const int R = N;
        std::cout << L << " " << R << std::endl;

        std::string S( N, ' ' );
        for( int i = 0; i < N; i ++ ) {
            S.at( i ) = i % M + 'a';
        } 
        std::cout << S << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );

        const int M = 26;
        const int N = dist( engine );

        dist = std::uniform_int_distribution< int >( 1, N );
        const int L = dist( engine );
        const int R = dist( engine );
        std::cout << std::min( L, R ) << " " << std::max( L, R ) << std::endl;

        std::string S( N, ' ' );
        dist = std::uniform_int_distribution< int >( 0, 25 );
        for( int i = 0; i < N; i ++ ) {
            S.at( i ) = dist( engine ) + 'a';
        } 
        std::cout << S << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
