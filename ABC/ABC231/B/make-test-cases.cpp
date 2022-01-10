/*
    make-test-cases.cpp
    ABC231 Problem B - Election
        https://atcoder.jp/contests/abc231/tasks/abc231_b
        Author: Keitaro Naruse
        Date:   2021-12-11, 2022-01-10
        MIT License
*/

#include <iostream>
#include <string>
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
        for( int i = 0; i < N; i ++ ) {
            const std::string S = "a";
            std::cout << S << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const std::string S = "aaaaaaaaaa";
            std::cout << S << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 1, 100 );
        const int N = dist( engine );
        std::cout << N << std::endl;

        for( int i = 0; i < N; i ++ ) {
            dist = std::uniform_int_distribution< int >( 1, 10 );
            const int n = dist( engine );
            std::string S( n, ' ' );
            for( int j = 0; j < n; j ++ ) {
                dist = std::uniform_int_distribution< int >( 'a', 'z' );
                const char c = ( char ) dist( engine );
                S.at( j ) = c;
            }
            std::cout << S << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
