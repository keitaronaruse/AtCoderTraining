/*
    make-test-cases.cpp
    058 - Original Calculator（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_bf
        Author: Keitaro Naruse
        Date:   2022-01-18, 2022-01-19
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
        const int N = 0;
        const long long L = 1LL;
        std::cout << N << " " << L << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 99999;
        const long long L = 1000000000000000000LL;
        std::cout << N << " " << L << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 0, 99999 );
        const int N = dist( engine );
        std::uniform_int_distribution< long long > dist_ll( 1, 1000000000000000000LL ); 
        const long long L = dist_ll( engine );
        std::cout << N << " " << L << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
