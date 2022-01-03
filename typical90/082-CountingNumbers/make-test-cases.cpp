/*
    make-test-cases.cpp
    082 - Counting Numbers（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_cd
        Author: Keitaro Naruse
        Date:   2021-12-25, 2022-01-03
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
        const long long  L = 1LL, R = 1LL;
        std::cout << L << " " << R << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const long long  L = 1000000000000000000LL, R = 1000000000000000000LL;
        std::cout << L << " " << R << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< long long > dist( 1LL, 1000000000000000000LL ); 
        const long long L = dist( engine ), R = dist( engine );
        std::cout << std::min( L, R ) << " " << std::max( L, R ) << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
