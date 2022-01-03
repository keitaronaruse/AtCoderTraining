/*
    make-test-cases.cpp
    075 - Magic For Balls（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bw
        Author: Keitaro Naruse
        Date:   2021-12-23, 2021-01-03 
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
        const long long N = 2LL;
        std::cout << N << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const long long N = 1000000000000LL;
        std::cout << N << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< long long > ll_dist( 2LL, 1000000000000LL ); 

        const long long N = ll_dist( engine );
        std::cout << N << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
