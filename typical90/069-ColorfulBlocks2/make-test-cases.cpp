/*
    make-test-cases.cpp
    069 - Colorful Blocks 2（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bq
        Author: Keitaro Naruse
        Date:   2021-12-21, 2022-01-02 
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
        const long long N = 1;
        const int K = 1;
        std::cout << N << " " << K << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const long long N = 1000000000000000000;
        const int K = 1000000000;
        std::cout << N << " " << K << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< long long > ll_dist( 1LL, 1000000000000000000LL ); 
        std::uniform_int_distribution< int > int_dist( 1, 1000000000 ); 

        const long long N = ll_dist( engine );
        const int K = int_dist( engine );
        std::cout << N << " " << K << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
