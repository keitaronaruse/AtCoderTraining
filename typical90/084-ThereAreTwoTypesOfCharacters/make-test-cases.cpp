/*
    make-test-cases.cpp
    084 - There are two types of characters（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_cf
        Author: Keitaro Naruse
        Date:   2021-12-26, 2022-01-03
        MIT License
*/

#include <iostream>
#include <random>
#include <string>
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
        const int N = 1;
        std::cout << N << std::endl;
        const std::string S = "o";
        std::cout << S << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 1000000;
        std::cout << N << std::endl;
        std::string S( N, 'o' );
        for( int i = 0; i < N; i += 2 ) {
            S.at( i ) = 'x';
        }
        std::cout << S << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist( 1, 1000000 ); 
        const int N = dist( engine );
        std::cout << N << std::endl;

        std::string S( N, 'o' );
        dist = std::uniform_int_distribution< int >( 0, 1 ); 
        for( int i = 0; i < N; i ++ ) {
            S.at( i ) = ( dist( engine ) == 0 )? 'o' : 'x';
        }
        std::cout << S << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
